
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;

int n;
int t;
char s[N];
int dp[2][7];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    int ans = -1;

    for (int cost = 1; cost <= 3; ++cost) {
      memset(dp, 0, sizeof(dp));
      dp[0][3] = 1;

      for (int i = 1; i <= n; ++i) {
        int now = i & 1;
        int pre = now ^ 1;

        memset(dp[now], 0, sizeof(dp[now]));

        for (int v = -3; v <= 3; ++v) {
          if (s[i] == '+' && v <= 0) continue;
          if (s[i] == '-' && v >= 0) continue;
          if (s[i] == '0' && v != 0) continue;

          for (int u = -3; u <= 3; ++u) {
            if (u != v && abs(u - v) <= cost && dp[pre][u + 3]) {
              dp[now][v + 3] = 1;
              break;
            }
          }
        }
      }

      int ok = 0;

      for (int j = 0; j < 7; ++j) {
        ok |= dp[n & 1][j];
      }

      if (ok) {
        ans = cost;
        break;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
