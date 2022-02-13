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
#define M 202
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
//int t;
ll dp[N][M];
int s[N], t[N], d[N], w[N];
int mx1[N], mx2[N];
int main() {
  cin>>n>>m>>k;
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d%d%d", &s[i], &t[i], &d[i], &w[i]);
  }
  vector<pair<int,int>> rk;
  rk.clear();
  memset(mx1, -1, sizeof(mx1));
  for (int i = 1; i <= k; ++i) {
    rk.push_back(make_pair(s[i], i));
  }
  sort(rk.begin(), rk.end());
  set<pair<pair<int,int>, int>> ss;
  ss.clear();
  int cur=0;
  for (int i =1; i <= n; ++i) {
    while(cur < rk.size() && rk[cur].first <= i) {
      int id = rk[cur].second;
      ss.insert(make_pair(make_pair(-w[id], -d[id]), id));
      cur++;
    }
    while(!ss.empty()) {
      int id = (*ss.begin()).second;
      if (t[id] < i) {
        ss.erase(ss.begin());
      } else {
        break;
      }
    }
    if (!ss.empty()) {
      mx1[i] = (*ss.begin()).second;
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = (1LL<<61)-1;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (dp[i][j] < (1LL<<61)-1) {
        int idx = mx1[i+1];
        if (idx < 0) {
          dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        } else {
          dp[d[idx]][j] = min(dp[d[idx]][j], dp[i][j]+w[idx]);
          if (j+1<=m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
        }
      }
    }
  }
  ll ans = (1LL<<61)-1;
  for (int i = 0; i <= m; ++i) {
    ans=min(ans, dp[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
