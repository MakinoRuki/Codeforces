#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long ll;
int n,m;
const ll mod = 1000000007LL;
ll dp[2][12][1002];
int main() {
  cin>>n>>m;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[0][1][i] = 1;
  }
  for (int i = 2; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k <= n; ++k) {
        dp[0][i][k] = (dp[0][i-1][j] + dp[0][i][k]) % mod;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    dp[1][m][i] = 1;
  }
  for (int i = m-1; i >= 1; --i) {
    for (int j = n; j >= 1; --j) {
      for (int k = j; k >= 1; --k) {
        dp[1][i][k] = (dp[1][i][k] + dp[1][i+1][j]) % mod;
      }
    }
  }
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ans = (ans + dp[0][m][i] * dp[1][1][j] % mod) % mod;
    }
  }
  cout<<ans<<endl;
	return 0;
}
