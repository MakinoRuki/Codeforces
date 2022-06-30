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
#define N 1005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N][N];
int dp[2][N][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int tot=0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
        tot += a[i][j];
       // par[i*m+j] = i*m+j;
      }
    }
    if (n == 1 || m == 1) {
      if (tot == 0) {
        puts("YES");
      } else {
        puts("NO");
      }
      continue;
    }
    if ((n+m-1)%2) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[0][i][j] = inf;
        dp[1][i][j] = -inf;
      }
    }
    dp[0][0][0] = dp[1][0][0] = a[0][0];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i+1<n) {
          dp[0][i+1][j] = min(dp[0][i+1][j], dp[0][i][j]+a[i+1][j]);
          dp[1][i+1][j] = max(dp[1][i+1][j], dp[1][i][j]+a[i+1][j]);
        }
        if (j+1<m) {
          dp[0][i][j+1] = min(dp[0][i][j+1], dp[0][i][j]+a[i][j+1]);
          dp[1][i][j+1] = max(dp[1][i][j+1], dp[1][i][j]+a[i][j+1]);
        }
      }
    }
    if (dp[0][n-1][m-1]<=0 && dp[1][n-1][m-1] >= 0) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
