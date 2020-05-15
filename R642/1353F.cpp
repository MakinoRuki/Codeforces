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
#define N 102
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
ll mt[N][N];
ll dp[N][N];
string s;
ll solve(int x, int y) {
  for (int i = 1; i <= n; ++i) {
    for (int j =1 ; j <= m; ++j) {
      dp[i][j] = ((i==x && j==y) ? 0 : (1LL<<62)-1);
    }
  }
  for (int i = x; i >= 1; --i) {
    for (int j = y; j >= 1; --j) {
      int ds = abs(i-x)+abs(j-y);
      if (i+1<=x && mt[i][j] >= mt[x][y]-ds) {
        dp[i][j] = min(dp[i][j], dp[i+1][j] + (mt[i][j]-mt[x][y]+ds));
      }
      if (j+1<=y && mt[i][j] >= mt[x][y]-ds) {
        dp[i][j] = min(dp[i][j], dp[i][j+1] + (mt[i][j]-mt[x][y]+ds));
      }
    }
  }
  for (int i = x; i <= n; ++i) {
    for (int j= y; j <= m; ++j) {
      int ds = abs(x-i) + abs(y-j);
      if (i-1 >= x && mt[i][j] >= mt[x][y]+ds) {
        dp[i][j] = min(dp[i][j], dp[i-1][j] + (mt[i][j]-mt[x][y]-ds));
      }
      if (j-1 >= y && mt[i][j] >= mt[x][y]+ds) {
        dp[i][j] = min(dp[i][j], dp[i][j-1] + (mt[i][j]-mt[x][y]-ds));
      }
    }
  }
  if (dp[1][1] < (1LL<<62)-1 && dp[n][m] < (1LL<<62)-1) {
    return dp[1][1] + dp[n][m];
  }
  return (1LL<<62)-1;
}
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%lld", &mt[i][j]);
      }
    }
    ll ans = (1LL<<62)-1;
    for (int i = 1; i <= n; ++i) {
      for (int j =1 ; j <= m; ++j) {
        ans = min(ans, solve(i, j));
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
