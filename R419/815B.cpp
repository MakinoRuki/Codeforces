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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
ll a[N];
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
  cin>>n;
  fac[0] = 1LL;
  fac2[0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod;
    fac2[i] = getpw(fac[i], mod-2);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  if (n == 1) {
    printf("%lld\n", a[n]);
  } else {
    if (n % 2) {
      for (int i = 1; i < n; ++i) {
        if (i % 2) a[i] = (a[i] + a[i+1]) % mod;
        else a[i] = (a[i] - a[i+1] + mod) % mod;
      }
      n--;
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; i += 2) {
      ans = (ans + (ll)a[i] * comb(n/2-1, i/2) % mod) % mod;
    }
  //  cout<<ans<<endl;
    for (int i = 2; i <= n; i += 2) {
      if ((n/2)%2 == 0) {
        ans = (ans - (ll)a[i] * comb(n/2-1, i/2-1) % mod + mod) % mod;
      } else {
        ans = (ans + (ll)a[i] * comb(n/2-1, i/2-1) % mod) % mod;
      }
    //  cout<<i<<" "<<a[i]<<" "<<ans<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
