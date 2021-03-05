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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
vector<int> edges[N];
int s;
bool dp[N][2];
int dp2[N][2];
int res[N][2];
int vis[N];
bool dfs(int u) {
  if (vis[u]>=1) return false;
  if (vis[u] == -1) return true;
  vis[u]=-1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (dfs(v)) return true;
  }
  vis[u]=1;
  return false;
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    int c;
    scanf("%d", &c);
    for (int j = 1; j <= c; ++j) {
      int a;
      scanf("%d", &a);
      edges[i].push_back(a);
    }
  }
  cin>>s;
  queue<pair<int,int>> q;
  memset(dp, false, sizeof(dp));
  q.push(make_pair(s, 0));
  dp[s][0]=true;
  while(!q.empty()) {
    auto pr = q.front();
    q.pop();
    int u = pr.first;
    int d = pr.second;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (!dp[v][!d]) {
        dp[v][!d] = true;
        res[v][!d] = u;
        q.push(make_pair(v, !d));
      }
    }
  }
  int id = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i][1] && edges[i].empty()) {
      id = i;
      break;
    }
  }
  if (!id) {
    memset(vis, 0, sizeof(vis));
    if (dfs(s)) {
      puts("Draw");
    } else {
      puts("Lose");
    }
  } else {
    int cur=id;
    vector<int> ans;
    ans.clear();
    int d = 1;
    while(true) {
      ans.push_back(cur);
      if (cur == s && !d) {
        break;
      }
      cur = res[cur][d];
      d = !d;
    }
    puts("Win");
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
