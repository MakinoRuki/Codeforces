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
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, v, k;
string t;
int dp[N][N];
int main() {
  cin>>n>>v;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= v; ++j) {
      dp[i][j] = inf;
    }
  }
  dp[1][0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= v; ++j) {
      if (dp[i][j] < inf) {
        for (int k = 0; k <= v; ++k) {
          if (j + k <= v && j + k - 1 >= 0) {
            dp[i+1][j+k-1] = min(dp[i+1][j+k-1], dp[i][j]+i*k);
          }
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= v; ++i) {
    ans=min(ans, dp[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
