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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
ll dp[2][N][N];
void update(int i, int j, int nj, int add) {
  if (dp[0][i][j]+add > dp[0][i+1][nj]) {
    dp[0][i+1][nj] = dp[0][i][j]+add;
    dp[1][i+1][nj] = dp[1][i][j];
  } else if (dp[0][i][j]+add == dp[0][i+1][nj]) {
    dp[1][i+1][nj] = (dp[1][i+1][nj] + dp[1][i][j]) % mod;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i<= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[0][i][j] = -1;
        dp[1][i][j] = 0;
      }
    }
    dp[0][0][0] = 0LL;
    dp[1][0][0] = 1LL;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[0][i][j] >= 0) {
          update(i, j, j, 0);
          update(i, j, j+1, a[i+1]);
        }
      }
    }
    printf("%lld\n", dp[1][n][k]);
  }
  return 0;
}
