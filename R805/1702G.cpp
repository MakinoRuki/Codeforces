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
#include <random>
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
vector<int> edges[N];
int par[N];
int dep[N];
int dp[N][21];
bool vis[N];
bool vis2[N];
int getlca(int u, int v) {
  if (dep[u] < dep[v]) {
    swap(u, v);
  }
  for (int i = 19; i >= 0; --i) {
    if (dp[u][i] >= 1 && dep[dp[u][i]] >= dep[v]) {
      u = dp[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; --i) {
    if (dp[u][i] >= 1 && dp[v][i] >= 1 && dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  u = par[u];
  return u;
}
bool check(int u, int v, int lca, vector<pair<int,int>>& ps) {
  for (int i = 0; i < ps.size(); ++i) {
    int z = ps[i].second;
    if (dep[z] < dep[lca]) {
      return false;
    }
    if (getlca(u, z) != z && getlca(v, z) != z) {
      return false;
    }
  }
  return true;
}
void dfs(int u, int p, int d) {
  par[u] = p;
  dep[u] = d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
int main() {
  cin>>n;
  for (int i= 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0, 0);
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = par[i];
  }
  for (int i = 1; i < 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dp[j][i-1] >= 1 && dp[dp[j][i-1]][i-1] >= 1) {
        dp[j][i] = dp[dp[j][i-1]][i-1];
      }
    }
  }
  memset(vis, false, sizeof(vis));
  memset(vis2, false, sizeof(vis2));
  cin>>q;
  while(q-->0) {
    scanf("%d", &k);
    vector<pair<int,int>> ps;
    ps.clear();
    for (int i = 1; i <= k; ++i) {
      int x;
      scanf("%d", &x);
      ps.push_back(make_pair(dep[x], x));
      vis[x] = true;
    }
    sort(ps.begin(), ps.end());
    if (ps.size() == 1) {
      puts("YES");
    } else {
      int sz = (int)ps.size();
      int u = ps[sz-1].second;
      int v = 0;
      for (int i = sz-2; i >= 0; --i) {
        if (getlca(u, ps[i].second) != ps[i].second) {
          v = ps[i].second;
          break;
        }
      }
      int w = ps[0].second;
      int lca;
      bool found=false;
      if (v > 0) {
        lca = getlca(u, v);
        if (check(u, v, lca, ps)) {
          found=true;
        }
      }
      lca = getlca(u, w);
      if (check(u, w, lca, ps)) {
        found=true;
      }
      if (found) puts("YES");
      else puts("NO");
    }
    for (int i = 0; i < ps.size(); ++i) {
      vis[ps[i].second] = false;
    }
  }
  return 0;
}
