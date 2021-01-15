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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
vector<int> edges[N];
int dis[N];
bool vis[N];
int ans[N];
void dfs(int u) {
  if (ans[u] >= 0) return;
  ans[u] = dis[u];
  for (int i = 0; i < edges[u].size(); ++i) {
    int v=edges[u][i];
    if (dis[v] > dis[u]) {
      dfs(v);
      if (ans[u] < 0 || ans[u] > ans[v]) {
        ans[u] = ans[v];
      }
    } else {
      if (ans[u] < 0 || dis[v] < ans[u]) {
        ans[u] = dis[v];
      }
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
      dis[i] = inf;
      vis[i] = false;
    }
    queue<int> q;
    dis[1] = 0;
    vis[1] = true;
    q.push(1);
    while(!q.empty()) {
      int cur=q.front();
      q.pop();
      vis[cur] = false;
      for (int i = 0; i < edges[cur].size(); ++i) {
        int v = edges[cur][i];
        if (dis[v] > dis[cur]+1) {
          dis[v]=dis[cur]+1;
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
    }
  //  cout<<dis[2]<<endl;
    for (int i = 1; i <= n; ++i) {
      ans[i] = -1;
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
      printf("%d", ans[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
