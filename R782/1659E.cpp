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
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
vector<pair<int,int>> edges[N];
int par[32][N];
bool vis[32][N];
vector<pair<pair<int,int>, int>> es;
int find(int id, int u) {
  return par[id][u] == u ? u : par[id][u] = find(id, par[id][u]);
}
int main() {
  cin>>n>>m;
  es.clear();
  for (int i = 1; i <= m; ++i) {
    int a,b,w;
    scanf("%d%d%d", &a, &b, &w);
    es.push_back(make_pair(make_pair(a,b), w));
    edges[a].push_back(make_pair(b, w));
    edges[b].push_back(make_pair(a, w));
  }
  for (int i = 0; i <= 30; ++i) {

    for (int j = 1; j <= n; ++j) {
      par[i][j] = j;
    }
    for (int j = 0; j < es.size(); ++j) {
      int u = es[j].first.first;
      int v = es[j].first.second;
      int w = es[j].second;
      if ((1<<i) & w) {
        int pu = find(i, u);
        int pv = find(i, v);
        if (pu != pv) {
          par[i][pu] = pv;
        }
      }
    }
  }
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= 30; ++i) {
    for (int j = 1; j <= n; ++j) {
      int j2;
      for (j2 = 0; j2 < edges[j].size(); ++j2) {
        int w = edges[j][j2].second;
        if (w % 2 == 0) {
          break;
        }
      }
      if (j2 < edges[j].size()) {
        int pu = find(i, j);
        vis[i][pu] = true;
      }
    }
  }
  cin>>q;
  while(q-->0) {
    int u, v;
    scanf("%d%d", &u, &v);
    int i;
    for (i = 0; i <= 30; ++i) {
      int pu = find(i, u);
      int pv = find(i, v);
      if (pu == pv) {
        break;
      }
    }
    if (i <= 30) {
      puts("0");
    } else {
      for (i = 1; i <= 30; ++i) {
        int pu = find(i, u);
        if (vis[i][pu]) {
          break;
        }
      }
      if (i <= 30) {
        puts("1");
      } else {
        puts("2");
      }
    }
  }
  return 0;
}
