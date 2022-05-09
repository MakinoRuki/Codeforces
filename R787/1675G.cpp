#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 260
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int dp[N][N][N];
int sum[N];
int main() {
  cin>>n>>m;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= m; ++k) {
        dp[i][j][k] = inf;
      }
    }
  }
  for (int i = 0; i <= m; ++i) {
    dp[1][i][i] = abs(i - a[1]);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int tmp[N];
      for (int k = m; k >= 0; --k) {
        tmp[k] = dp[i][j][k];
        if (k + 1 <= m) tmp[k] = min(tmp[k], tmp[k+1]);
      }
    //  if (i == 1 && j == 4) cout<<"x="<<tmp[3]<<endl;
      int dt = sum[i] - j;
      for (int k = 0; k <= m; ++k) {
        if (j + k <=m) dp[i+1][j + k][k] = min(dp[i+1][j+k][k], tmp[k] + abs(k-(a[i+1]+dt)));
      }
    }
  }
//  cout<<dp[1][3][3]<<" "<<dp[2][5][2]<<" "<<dp[3][6][1]<<endl;
  int ans=inf;
  for (int i = 0; i <= m; ++i) {
    ans = min(ans, dp[n][m][i]);
  }
  cout<<ans<<endl;
  return 0;
}
