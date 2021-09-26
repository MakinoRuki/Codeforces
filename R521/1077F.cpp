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
#define M 21
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k, x;
int a[N];
ll dp[N][N];
deque<int> dq[N];
int main() {
  cin>>n>>k>>x;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0LL;
  dq[0].push_back(0);
  ll ans=-1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 0LL;
    for (int j = 1; j <= x; ++j) {
      while(!dq[j-1].empty() && dq[j-1].front() < i-k) {
        dq[j-1].pop_front();
      }
      if (!dq[j-1].empty()) {
        dp[i][j] = max(dp[i][j], dp[dq[j-1].front()][j-1] + (ll)a[i]);
      }
    }
    for (int j = 0; j <= x; ++j) {
      if (dp[i][j] < 0) continue;
      while(!dq[j].empty() && dp[i][j] >= dp[dq[j].back()][j]) {
        dq[j].pop_back();
      }
      if (j > 0 || i < k) dq[j].push_back(i);
    }
  }
  for (int i = n; i > max(0, n-k); --i) {
    ans = max(ans, dp[i][x]);
  }
  printf("%lld\n", ans);
  return 0;
}
