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
#define N 400005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
vector<pair<int,int>> edges[N];
int val[N];
vector<pair<int,int>> edges2[N];
int col[N];
vector<pair<int,int>> es;
bool dfs(int u, int c) {
  if (col[u] >= 0 && col[u] != c) {
    return false;
  }
  if (col[u]>=0) return true;
  col[u] = c;
  for (int i = 0; i < edges2[u].size(); ++i) {
    int v = edges2[u][i].first;
    int w = edges2[u][i].second;
    if (!dfs(v, c^w)) {
      return false;
    }
  }
  return true;
}
int getv(int x) {
  int cnt=0;
  while(x) {
    if (x%2) cnt++;
    x/=2;
  }
  return cnt%2;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      col[i] = -1;
      edges2[i].clear();
      edges[i].clear();
    }
    es.clear();
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edges[u].push_back(make_pair(v, i));
      edges[v].push_back(make_pair(u, i));
      val[i] = w;
      es.push_back(make_pair(u, v));
      if (val[i] >= 0) {
        edges2[u].push_back(make_pair(v, getv(val[i])));
        edges2[v].push_back(make_pair(u, getv(val[i])));
      }
     // if (val[i] >= 0) val[i] = getv(val[i]);
    }
    for (int i = 1; i <= m; ++i) {
      int a,b,p;
      scanf("%d%d%d", &a, &b, &p);
      edges2[a].push_back(make_pair(b, p));
      edges2[b].push_back(make_pair(a, p));
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (col[i] < 0 && edges2[i].size() > 0) {
        if (!dfs(i, 0)) {
          ok=false;
          break;
        }
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    for (int i = 1; i <= n;++i) {
      if (col[i]<0) col[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < edges[i].size(); ++j) {
        int id = edges[i][j].second;
        int v = edges[i][j].first;
        if (val[id] < 0) {
          val[id] = col[i] ^ col[v];
        }
      }
    }
    puts("YES");
    for (int i = 1; i < n; ++i) {
      printf("%d %d %d\n", es[i-1].first, es[i-1].second, val[i]);
    }
  }
  return 0;
}
