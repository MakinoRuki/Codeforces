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
#include <ctime>
#include <list>
#define N 300005
#define M 2005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int par[N];
int dp[N];
vector<pair<int,int>> es;
bool vis[N];
void dfs(int u, int p) {
    par[u]=p;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        dfs(v, u);
    }
}
int dfs2(int u, int p) {
    int mx=0;
    for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (v == p) continue;
        mx = max(mx, dfs2(v, u)+dp[v]);
    }
    return mx;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      for (int i =1; i <= n; ++i) {
          edges[i].clear();
          dp[i] = 0;
          vis[i] = false;
      }
      es.clear();
      for (int i =1; i < n; ++i) {
          int u, v;
          scanf("%d%d", &u, &v);
          es.push_back(make_pair(u, v));
          edges[u].push_back(v);
          edges[v].push_back(u);
      }
      dfs(1, 0);
      for (int i = 0; i < es.size(); ++i) {
          int u = es[i].first;
          int v = es[i].second;
          if (par[v] != u) {
              swap(u, v);
          }
          if (u == 1 || !vis[u]) {
              dp[v]++;
          }
          vis[v]=true;
      }
      int ans=dfs2(1, 0);
      printf("%d\n", ans);
  }
  return 0;
}
