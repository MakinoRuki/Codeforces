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
#define N 2002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll dp[N][N];
int main() {
  cin>>n;
  ll ans=0LL;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1LL;
  for (int i = 0; i < 2*n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j]) {
        int num=(i-j)/2+j;
        if (num<n) {
          dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
        }
        if (j > 0) {
          dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % mod;
        }
      }
    }
  }
  for (int i = 1; i <= 2*n; ++i) {
    for (int j = 0; j <= n; ++j) {
      int det=2*n-i;
      if (det%2) {
        ans = (ans + dp[i][j]) % mod;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
