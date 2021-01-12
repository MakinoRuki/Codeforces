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
#define M 31
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, t;
int x[N];
string s;
int dp[N][5][5];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>s;
    n = s.size();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i][j][k] = inf;
        }
      }
    }
    if (n==1) {
      printf("%d\n", 0);
    } else {
      dp[2][0][1] = 1;
      dp[2][1][0] = 1;
      dp[2][1][1] = 2;
      if (s[0] != s[1]) {
        dp[2][0][0] = 0;
      }
      for (int i = 3; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
          for (int k = 0; k < 2; ++k) {
            if (dp[i-1][j][k] < inf) {
              if ((s[i-1] == s[i-3] && !j) || (s[i-1]==s[i-2] && !k)) {
                dp[i][k][1] = min(dp[i][k][1], dp[i-1][j][k]+1);
              } else {
                dp[i][k][1] = min(dp[i][k][1], dp[i-1][j][k]+1);
                dp[i][k][0] = min(dp[i][k][0], dp[i-1][j][k]);
              }
            }
          }
        }
      }
      int ans=inf;
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          ans = min(ans, dp[n][j][k]);
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
