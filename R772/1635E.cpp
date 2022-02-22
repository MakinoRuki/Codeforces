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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
vector<int> edges[N];
vector<pair<int, pair<int,int>>> vv;
int deg[N];
vector<int> edges2[N];
int col[N];
int pos[N];
vector<int> bfs() {
  vector<int> ans;
  ans.clear();
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (int i = 0; i < edges2[u].size(); ++i) {
      int v = edges2[u][i];
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  return ans;
}
bool dfs(int u, int c) {
  if (col[u] >= 0) {
    return col[u] == c;
  }
  col[u] = c;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v=edges[u][i];
    if (!dfs(v, !c)) {
      return false;
    }
  }
  return true;
}
int main() {
  cin>>n>>m;
  vv.clear();
  for (int i =1 ; i <= m; ++i) {
    int ty, u, v;
    scanf("%d%d%d", &ty, &u, &v);
    vv.push_back(make_pair(ty, make_pair(u, v)));
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  memset(col, -1, sizeof(col));
  bool ok = true;
  for (int i=  1; i <= n; ++i) {
    if (col[i] < 0) {
      if (!dfs(i, 0)) {
        ok=false;
        break;
      }
    }
  }
  if (!ok) {
    puts("NO");
    return 0;
  }
  memset(deg, 0,sizeof(deg));
  for (int i = 0; i < vv.size(); ++i) {
    int ty = vv[i].first;
    int u = vv[i].second.first;
    int v = vv[i].second.second;
    if (col[u] == 0 && col[v] == 1) {
      if (ty == 1) {
        edges2[u].push_back(v);
        deg[v]++;
      } else {
        edges2[v].push_back(u);
        deg[u]++;
      }
    } else {
      if (ty == 2) {
        edges2[u].push_back(v);
        deg[v]++;
      } else {
        edges2[v].push_back(u);
        deg[u]++;
      }
    }
  }
  auto ans = bfs();
  if (ans.size() < n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < ans.size(); ++i) {
    pos[ans[i]] = i+1;
  }
  for (int i= 1; i <= n; ++i) {
    if (col[i] == 1) {
      printf("R %d\n", pos[i]);
    } else {
      printf("L %d\n", pos[i]);
    }
  }
  return 0;
}
