#include <iostream>
#include <vector>
#include <algorithm>
#define N 50
#define M 205
using namespace std;
double dp[2][N][N];
int n,k;
int a[N];
int main() {
    // 示例：输出 Hello World 并进行简单计算
    cin>>n>>k;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        if (a[i] > a[j]) dp[0][i][j] = 1.0;
        else dp[0][i][j] = 0.0;
      }
    }
    for (int t = 1; t <= k; ++t) {
      int now = t&1;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          dp[now][i][j] = 0.0;
        }
      }
      double p = 2.0 / ((double)n*(double)(n+1));
      for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
          for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
              if (j < l) {
                dp[now][i][j] += dp[now^1][i][j]*p;
              } else if (i < l && j >= l && j <= r) {
                dp[now][i][j] += dp[now^1][i][l+r-j]*p;
              } else if (i >= l && j <= r) {
                int x = l+r-i;
                int y = l+r-j;
                if (x < y) dp[now][i][j] += dp[now^1][x][y]*p;
                else dp[now][i][j] += (1.0-dp[now^1][y][x])*p;
              } else if (i >= l && i <=r && j > r) {
                dp[now][i][j] += dp[now^1][l+r-i][j]*p;
              } else {
                dp[now][i][j] += dp[now^1][i][j]*p;
              }
            }
          }
        }
      }
    }
    double ans=0.0;
    for (int i=1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        ans += dp[k&1][i][j];
      }
    }
    printf("%.10lf\n", ans);
    return 0;
}
