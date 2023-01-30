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
#define N 100005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll pw[N];
ll getpw(ll x, ll y) {
  ll res = 1LL;
  while(y) {
    if (y&1) res=res*x%mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  pw[0] = 1LL;
  for (int i =1; i < N; ++i) {
    pw[i] = pw[i-1] * (ll)i % mod;
  }
  ll pw3 = getpw(3LL, mod-2);
  ll pw2 = getpw(2LL, mod-2);
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll dt = (ll)n * ((ll)(n-1)%mod) % mod;
    dt = dt * pw2 % mod;
    dt = dt * dt % mod;
    dt = dt * pw[n-2] % mod;
    ll ans = dt * 2LL % mod;
    ll tmp = ((ll)n%mod * ((ll)(n-1)%mod))%mod;
    tmp = tmp*pw[n]%mod;
    tmp = tmp*pw2%mod;
    ans = (ans + tmp) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
