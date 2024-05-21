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
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
ll dp[N];
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
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int n0=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 0) n0++;
    }
    int n1=0;
    for (int i = 1; i <= n0; ++i) {
      if (a[i] == 1) n1++;
    }
    dp[0]=0LL;
    for (int i = 1; i <= n0; ++i) {
      ll tmp = 2LL * (ll)i * (ll)i;
      tmp = tmp % mod2;
      tmp = getpw(tmp, mod2-2);
      tmp = tmp * ((ll)n*(ll)(n-1)%mod2) % mod2;
      dp[i] = (dp[i-1] + tmp) % mod2;
    }
    printf("%lld\n", dp[n1]);
  }
  return 0;
}
