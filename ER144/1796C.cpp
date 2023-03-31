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
#define N 200005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll p3[22];
ll p2[22];
ll fac[22];
ll fac2[22];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll comb(ll x, ll y) {
  ll res = fac[x] * fac2[y] % mod2 * fac2[x-y] % mod2;
  return res;
}
int main() {
  p3[0] = 1LL;
  p2[0] = 1LL;
  fac[0] = 1LL;
  fac2[0] = 1LL;
  for (int i = 1; i <= 20; ++i) {
    p3[i] = p3[i-1] * 3LL;
    p2[i] = p2[i-1] * 2LL;
    fac[i] = fac[i-1] * (ll)i % mod2;
    fac2[i] = getpw(fac[i], mod2-2);
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    int cnt=0;
    ll l2 = l;
    while(l2*2LL <= r) {
      l2 *= 2LL;
      cnt++;
    }
    int n3 = 0;
    for (int i = 0; i <= cnt; ++i) {
      int j = cnt-i;
      if (p2[i] <= r && p2[i] * l <= r && p3[j] <= r && p3[j] * l <= r && l * p2[i] * p3[j] <= r) {
        n3 = max(n3, j);
      }
    }
    //cout<<"n3="<<n3<<endl;
    ll ans = 0LL;
    for (int i = 0; i <= n3; ++i) {
      ll tmp = r / (p2[cnt-i] * p3[i]);
      ll dt = tmp-l+1;
      ans = (ans + dt * comb(cnt, i) % mod2) % mod2;
    }
    printf("%d %lld\n", cnt+1, ans);
  }
  return 0;
}
