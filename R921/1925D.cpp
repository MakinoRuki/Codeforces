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
#include <ctime>
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  // 用到的组合数公式：i*C(k,i)=k*C(k-1, i-1); sum([i=0...k],C(k,i)*p^(k-i))=(p+1)^k.
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    ll tot=0LL;
    for (int i = 1; i <= m; ++i) {
      ll a,b,f;
      scanf("%lld%lld%lld", &a, &b, &f);
      tot = (tot + f) % mod;
    }
    ll cn = (ll)n*(ll)(n-1)/2LL;
    cn %= mod;
    ll ans = k * getpw(cn, k-1) % mod;
    ans =ans * tot %mod;
    ll ck = (ll)k*(ll)(k-1)/2LL;
    ck %= mod;
    if (k >= 2) ans = (ans + (ll)m*ck%mod*getpw(cn, k-2)%mod)%mod;
    cn = getpw(cn, k);
    ans = ans * getpw(cn, mod-2) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
