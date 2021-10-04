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
#define M 2005
#define N 10005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
int a[N];
int dp[N][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= 2000; ++j) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 2000; ++j) {
        if (dp[i][j] < inf) {
          if (j + a[i+1] <= 2000) {
            dp[i+1][j+a[i+1]] = min(dp[i+1][j+a[i+1]], max(dp[i][j], j+a[i+1]));
          }
          if (j >= a[i+1]) {
            dp[i+1][j-a[i+1]] = min(dp[i+1][j-a[i+1]], dp[i][j]);
          } else {
            dp[i+1][0] = min(dp[i+1][0], dp[i][j]-j+a[i+1]);
          }
        }
      }
    }
    int ans = inf;
    for (int i = 0; i <= 2000; ++i) {
      ans=min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
