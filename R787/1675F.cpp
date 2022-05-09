#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int cnt[N];
bool vis[N];
void dfs1(int u, vector<int> p) {
  if (vis[u]) {
    cnt[u]++;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v =edges[u][i];
    if (v != p[0] && v != p[1]) {
      dfs1(v, {u, 0});
      cnt[u] += cnt[v];
    }
  }
}
void dfs2(int u, vector<int> p, int& res) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v != p[0] && v!= p[1] && cnt[v]>0) {
      res++;
      dfs2(v, {u, 0}, res);
      res++;
    }
  }
}
bool dfs(int u, int p, int y, vector<int>& ps) {
  if (u == y) {
    ps.push_back(u);
    return true;
  }
  for (int i = 0; i <edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    bool res= dfs(v, u, y, ps);
    if (res) {
      ps.push_back(u);
      return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    int x,y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i) {
      cnt[i] = 0;
      edges[i].clear();
      vis[i] = false;
    }
    for (int i = 1; i <= k; ++i) {
      scanf("%d", &a[i]);
      vis[a[i]] = true;
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    vector<int> ps;
    ps.clear();
    dfs(x, 0, y, ps);
    reverse(ps.begin(), ps.end());
    int ans = ps.size()-1;
    for (int i = 0; i < ps.size(); ++i) {
      vector<int> v;
      v.clear();
      if (i > 0) {
        v.push_back(ps[i-1]);
      }
      if (i < ps.size()-1) {
        v.push_back(ps[i+1]);
      }
      while(v.size() < 2) v.push_back(0);
      dfs1(ps[i], v);
      int res = 0;
      dfs2(ps[i], v, res);
      ans += res;
    }
    printf("%d\n", ans);
  }
  return 0;
}
