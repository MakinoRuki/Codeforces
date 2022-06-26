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
#include <random>
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
ll fac[N];
ll fac2[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
ll comb(ll x, ll y) {
  ll res = fac[x] * fac2[y] % mod * fac2[x-y] % mod;
  return res;
}
int main() {
  fac[0] = 1LL;
  fac2[0] = 1LL;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod;
    fac2[i] = getpw(fac[i], mod-2);
  }
  cin>>n;
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ll ans = 0LL;
  for (int i = 0; i <= n; ++i) {
    if (a[i] > 0) ans = (ans + comb(i + a[i], i+1)) % mod;
  }
  cout<<ans<<endl;
  return 0;
}
