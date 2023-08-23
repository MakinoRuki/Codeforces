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
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int dp[N][5][2];
int pw[6] = {1, 10, 100, 1000, 10000, 100000};
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = -2000000005;
        }
      }
    }
    for (int j = 0; j < 5; ++j) {
      if (s[n-1] - 'A' == j) {
        dp[n][j][0] = pw[j];
      } else {
        dp[n][j][1] = pw[j];
      }
    }
    for (int i = n; i > 1; --i) {
      for (int j = 0; j < 5; ++j) {
        for (int k = 0; k < 2; ++k) {
          if (dp[i][j][k] <= -2000000005) continue;
          for (int j2 = 0; j2 < 5; ++j2) {
            if (k && (j2 != s[i-2]-'A')) continue;
            int k2 = (j2!=s[i-2]-'A');
            if (j2 < j) {
              dp[i-1][j][k | k2] = max(dp[i-1][j][k|k2], dp[i][j][k]-pw[j2]);
            } else {
              dp[i-1][j2][k|k2] = max(dp[i-1][j2][k|k2], dp[i][j][k]+pw[j2]);
            }
          }
        }
      }
    }
    int ans = -2000000005;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 2; ++j) {
        ans = max(ans, dp[1][i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
