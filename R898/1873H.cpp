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
#define N 200002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
vector<int> edges[N];
bool vis[N];
int dis[N];
int par[N];
bool mk[N];
int a,b;
int id;
bool dfs(int u, int p) {
  par[u] = p;
  if (vis[u]) {
    id = u;
    return true;
  }
  vis[u] = true;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (dfs(v, u)) return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      vis[i] = false;
      dis[i] = inf;
      mk[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    queue<pair<int,int>> q;
    id = 0;
    dfs(b, 0);
    //cout<<"cur="<<id<<endl;
    int cur = id;
    mk[cur] = true;
    cur = par[cur];
    while(cur != id) {
      mk[cur] = true;
      cur = par[cur];
    }
    if (a == b) {
      puts("NO");
      continue;
    } else {
      if (mk[b]) {
        puts("YES");
        continue;
      }
    }
    dis[id] = 0;
    while(!q.empty()) {
      q.pop();
    }
    q.push(make_pair(id, 0));
    while(!q.empty()) {
      auto pr = q.front();
      q.pop();
      int u = pr.first;
      int p = pr.second;
      for (int i = 0; i < edges[u].size(); ++i) {
        int v  = edges[u][i];
        if (v == p) continue;
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          q.push(make_pair(v, u));
        }
      }
    }
    if (dis[a] <= dis[b]) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}
