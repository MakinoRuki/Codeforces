#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 102
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int a[N];
int zn, on, oz;
void solve(ll* x, ll b[][N]) {
  ll m = k;
  while(m) {
    if (m&1) {
      ll c[N];
      for (int i = 0; i <= n; ++i) {
        c[i] = 0LL;
        for (int j = 0; j <= n; ++j) {
          c[i] = (c[i] + b[i][j]*x[j]%mod)%mod;
        }
      }
      for (int i = 0; i <= n; ++i) {
        x[i] = c[i];
      }
    }
    ll c[N][N];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        c[i][j] = 0;
        for (int t = 0; t <= n; ++t) {
          c[i][j] = (c[i][j]+b[i][t]*b[t][j]%mod)%mod;
        }
      }
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        b[i][j] = c[i][j];
      }
    }
    m /= 2;
  }
}
int main() {
  cin>>n>>k;
  zn = 0;
  on = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) on++;
    else {
      zn++;
    }
  }
  for (int i = 0; i < zn; ++i) {
    if (a[i] == 0) oz++;
  }
  ll b[N][N];
  ll res=1LL;
  ll m = mod-2;
  ll tmp = (ll)n*(ll)(n-1)%mod;
  while(m) {
    if (m&1) res=res*tmp%mod;
    tmp=tmp*tmp%mod;
    m/=2;
  }
  for (int j = 0; j <= n; ++j) {
    if (j > zn) continue;
    int zn2 = j;
    int on2 = zn-j;
    if (j-1>=0) {
      b[j-1][j] = 2LL*(ll)zn2%mod*(ll)(on-on2)%mod;
      b[j-1][j] = b[j-1][j]*res%mod;
    }
    if (j+1<=zn) {
      b[j+1][j] = 2LL*(ll)(zn-zn2)%mod*(ll)(zn-zn2)%mod;
      b[j+1][j] = b[j+1][j]*res%mod;
    }
    b[j][j] = (ll)n*(ll)(n-1)%mod;
    if (j-1 >= 0) b[j][j] = (b[j][j]-2LL*(ll)zn2%mod*(ll)(on-on2)%mod+mod)%mod;
    if (j+1 <= zn) b[j][j] = (b[j][j] - 2LL*(ll)(zn-zn2)%mod*(ll)(zn-zn2)%mod + mod) % mod;
    b[j][j] = b[j][j]*res%mod;
  }
  ll x[N];
  for (int i = 0; i <= n; ++i) {
    if (i == oz) x[i] = 1;
    else x[i] = 0;
  }
  solve(x, b);
  ll ans = x[zn];
  cout<<ans<<endl;
  return 0;
}
