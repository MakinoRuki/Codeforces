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
#define N 200002
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
string s;
ll fac[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  fac[0] = 1LL;
  for (int i =1; i < N; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
  }
  cin>>n;
  ll bn=0,wn=0;
  ll bb=0,ww=0,wb=0,bw=0;
  ll wq=0,qw=0,bq=0,qb=0;
  ll qq=0;
  for (int i = 1; i <= n; ++i) {
    cin>>s;
    if (s == "W?") {
      wq++;
      wn++;
    } else if (s == "WB") {
      wn++;
      wb++;
      bn++;
    } else if (s == "WW") {
      wn += 2;
      ww++;
    } else if (s == "??") {
      qq++;
    } else if (s == "?W") {
      qw++;
      wn++;
    } else if (s == "?B") {
      qb++;
      bn++;
    } else if (s == "BB") {
      bn += 2;
      bb++;
    } else if (s == "B?") {
      bq++;
      bn++;
    } else {
      bw++;
      bn++;
      wn++;
    }
  }
  if (bn > n || wn > n) {
    puts("0");
  } else {
    ll x = 2*n-bn-wn;
    ll y = n-bn;
    ll ans = fac[y] * fac[x-y] % mod2;
    ans = getpw(ans, mod2-2) % mod2;
    ans = fac[x] * ans % mod2;
    if (bb == 0 && ww == 0) {
      ans = (ans - getpw(2LL, qq) + mod2) % mod2;
      if (!(wb> 0 && bw>0)) {
        if (!(wq>0&&qw>0) && !(bq>0&&qb>0) && !(wq>0&&bq>0) && !(qw>0&&qb>0)) {
          ans = (ans + 1) % mod2;
        }
        if (qq == n) {
          ans = (ans + 1) % mod2;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
