#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k, q;
int a[N];
ll dp[2][N][N];
ll dp2[N];
int main() {
  cin>>n>>k>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[0][i][0] = 1LL;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j-1>=1) {
        dp[0][j][i] = (dp[0][j-1][i-1] + dp[0][j][i]) % mod;
      }
      if (j+1<=n) {
        dp[0][j][i] = (dp[0][j][i] + dp[0][j+1][i-1]) % mod;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[1][i][0] = 1LL;
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j-1>=1) {
        dp[1][j][i] = (dp[1][j-1][i-1] + dp[1][j][i]) % mod;
      }
      if (j+1<=n) {
        dp[1][j][i] = (dp[1][j][i] + dp[1][j+1][i-1]) % mod;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp2[i] = 0LL;
    for (int j = 0; j <= k; ++j) {
      int j2 = k-j;
      dp2[i] = (dp2[i] + dp[0][i][j2] * dp[1][i][j] % mod) % mod;
    }
  }
  // memset(dp, -1, sizeof(dp));
  // for (int i = 1; i <= n; ++i) {
  //   dfs(0, i);
  // }
  // for (int i = 1; i <= n; ++i) {
  //   dp2[i] = 0LL;
  //   for (int j = 0; j <= k; ++j) {
  //     dp2[i] = (dp2[i] + dp[j][i]) % mod;
  //   }
  // }
  // for (int i = 1; i <= n; ++i) {
  //   dp[0][i] = 1LL;
  // }
  // for (int i = 1; i <= k; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     if (j-1>=1) {
  //       dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
  //     }
  //     if (j+1<=n) {
  //       dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
  //     }
  //   }
  // }
  ll tot=0LL;
  for (int i = 1; i <= n; ++i) {
    tot = (tot + dp2[i] * (ll)a[i] % mod) % mod;
  }
  while(q-->0) {
    int i, x;
    scanf("%d%d", &i, &x);
    tot = (tot - dp2[i] * (ll)a[i] % mod + mod) % mod;
    a[i] = x;
    tot = (tot + dp2[i] * (ll)a[i] % mod) % mod;
    printf("%lld\n", tot);
  }
  return 0;
}
