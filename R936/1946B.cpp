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
int a[N];
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
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    ll tot=0LL;
    ll mx=0LL;
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
      if (sum < 0) sum = 0LL;
      mx=max(mx, sum);
      tot = (tot + a[i] + mod)%mod;
    }
    tot %= mod;
    tot = (tot + (getpw(2LL, k)-1+mod)%mod*(mx%mod)%mod) % mod;
    printf("%lld\n", tot);
  }
  return 0;
}
