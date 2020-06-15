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
#define N 200002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, k;
vector<pair<int, int>> edges[N];
set<int> edges2[N];
bool vis[N];
int col[N];
int dep[N];
int pre[N];
int id1[N];
int id2[5*N];
int dp[5*N][30];
vector<pair<int,int>> es;
int cnt;
// void dfs(int u, int p, int d, int c) {
//   dep[u] = d;
//   col[u] = c;
//   for (int i = 0; i < edges[u].size(); ++i) {
//     int v = edges[u][i];
//     if (v==p) continue;
//     dfs(v, u, d+1, !c);
//   }
// }
void dfs1(int u, int p, int d, int c) {
  ++cnt;
  id1[u] = cnt;
  dep[cnt] = d;
  id2[cnt] = u;
  col[u] = c;
  pre[u] = p;
  dp[cnt][0] = cnt;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i].first;
    int x = edges[u][i].second;
    if (v!=p && id1[v] < 0) {
      vis[x] = true;
      dfs1(v, u, d+1, !c);
      ++cnt;
      id2[cnt] = u;
      dep[cnt] = d;
      dp[cnt][0] = cnt;
    }
  }
}
int getlca(int u, int v) {
  int x = id1[u];
  int y = id1[v];
  if (x > y) swap(x, y);
  int len = y-x+1;
  int pw;
  for (pw = 0; (1<<pw) <= len; ++pw) {

  }
  pw--;
  // if (u == 3 && v == 5) {
  //   cout<<":"<<x<<" "<<y<<" "<<pw<<endl;
  // }
  int x2 = dp[x][pw];
  int y2 = dp[y-(1<<pw)+1][pw];
  // if (u==3 && v==5) {
  //   cout<<"??"<<x2<<" "<<y2<<endl;
  // }
  if (dep[x2] < dep[y2]) {
    return id2[x2];
  } else {
    return id2[y2];
  }
}
int main() {
  cin>>n>>m>>k;
  es.clear();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(make_pair(v, i));
    edges[v].push_back(make_pair(u, i));
    es.push_back(make_pair(u, v));
  }
  cnt=0;
  memset(id1, -1, sizeof(id1));
  memset(id2, -1, sizeof(id2));
  memset(dp, -1, sizeof(dp));
  memset(col, -1, sizeof(col));
  memset(vis, false, sizeof(vis));
  dfs1(1, 0, 0, 0);
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= cnt; ++j) {
      if (j+(1<<i)-1 <= cnt) {
        int x = dp[j][i-1];
        if (x >= 0) {
          int y = dp[j+(1<<(i-1))][i-1];
          //if (i==1 && j==1) cout<<"!!"<<x<<" "<<y<<endl;
          if (y < 0) continue;
          if (dep[x] < dep[y]) {
            dp[j][i] = x;
          } else {
            dp[j][i] = y;
          }
        }
      }
    }
  }
  vector<int> ids1,ids2;
  ids1.clear();
  ids2.clear();
  bool found=false;
  for (int i = 1; i <= m; ++i) {
    if (!vis[i]) {
      int u = es[i-1].first;
      int v = es[i-1].second;
      int lca = getlca(u, v);
      if (dep[id1[v]]-dep[id1[lca]]+dep[id1[u]]-dep[id1[lca]]+1 <= k) {
        int cur = u;
        while(true) {
          ids1.push_back(cur);
          if (cur == lca) break;
          cur = pre[cur];
        }
        cur = v;
        while(true) {
          ids2.push_back(cur);
          if (cur == lca) break;
          cur = pre[cur];
        }
        ids2.pop_back();
        reverse(ids2.begin(), ids2.end());
        for (int j = 0; j < ids2.size(); ++j) {
          ids1.push_back(ids2[j]);
        }
        cout<<2<<endl;
        cout<<ids1.size()<<endl;
        for (int j = 1; j <= ids1.size(); ++j) {
          printf("%d", ids1[j-1]);
          if (j < ids1.size()) cout<<" ";
          else cout<<endl;
        }
        found=true;
        break;
      }
    }
  }
  if (found) return 0;
  ids1.clear();
  ids2.clear();
  for (int i = 1; i <= n; ++i) {
    if (col[i] == 1) ids1.push_back(i);
    else ids2.push_back(i);
  }
  if (ids1.size() >= (k+1)/2) {
    cout<<1<<endl;
    for (int i = 1; i <= (k+1)/2; ++i) {
      printf("%d", ids1[i-1]);
      if (i < (k+1)/2) cout<<" ";
      else cout<<endl;
    }
    return 0;
  }
  if (ids2.size() >= (k+1)/2) {
    cout<<1<<endl;
    for (int i = 1; i <= (k+1)/2; ++i) {
      printf("%d", ids2[i-1]);
      if (i < (k+1)/2) cout<<" ";
      else cout<<endl;
    }
    return 0;
  }
  
  return 0;
}
