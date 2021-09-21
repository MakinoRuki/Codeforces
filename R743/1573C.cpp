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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
vector<int> edges[N];
int deg[N];
int dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      deg[i] = 0;
      edges[i].clear();
      dp[i] = 1;
    }
    for (int i =1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      for (int j = 1; j <= k; ++j) {
        int u;
        scanf("%d", &u);
        edges[u].push_back(i);
        deg[i]++;
      }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) {
        q.push(i);
        dp[i] = 1;
      }
    }
    int cnt=0;
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      cnt++;
      for (int i = 0; i < edges[cur].size(); ++i) {
        int v=edges[cur][i];
        if (cur > v) {
          dp[v] = max(dp[v], dp[cur]+1);
        } else {
          dp[v] = max(dp[v], dp[cur]);
        }
        deg[v]--;
        if (deg[v] == 0) {
          q.push(v);
        }
      }
    }
    if (cnt < n) {
      puts("-1");
    } else {
      int ans=1;
      for (int i = 1; i <= n; ++i) {
        ans=max(ans, dp[i]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
