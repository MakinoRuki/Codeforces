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
#define N 2005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
ll dp[N][N];
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
  ll rev2 = getpw(2LL, mod-2);
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = 0;
      for (int j = 1; j < i; ++j) {
        dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])* rev2 % mod;
      }
      dp[i][i] = i;
    }
    ll ans = dp[n][m] * (ll)k % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
