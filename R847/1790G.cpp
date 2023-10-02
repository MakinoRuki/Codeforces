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
#define N 200010
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
int pv[N];
int bv[N];
int par[N];
int cnt[N];
int dis[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int p,b;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &p, &b);
    for (int i = 1; i <= n; ++i) {
      pv[i] = false;
      bv[i] = false;
      edges[i].clear();
      par[i] = i;
      cnt[i] = 1;
      dis[i] = inf;
    }
    for (int i = 1; i <= p; ++i) {
      scanf("%d", &x);
      pv[x] = true;
    }
    for (int i = 1; i <= b; ++i) {
      scanf("%d", &x);
      bv[x] = true;
    }
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
      if (bv[u] && bv[v]) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
          cnt[pv] += cnt[pu];
          par[pu] = pv;
        }
      }
    }
    if (pv[1]) {
      puts("YES");
      continue;
    }
    bool found=false;
    for (int i = 0; i < edges[1].size(); ++i) {
      int u = edges[1][i];
      if (pv[u]) {
        found=true;
        break;
      }
    }
    if (found) {
      puts("YES");
      continue;
    }
    dis[1] = 0;
    queue<int> q;
    for (int i = 0; i < edges[1].size(); ++i) {
      int u = edges[1][i];
      if (bv[u]) {
        dis[u] = 1;
        q.push(u);
      }
    }
    int ans=inf;
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < edges[u].size(); ++i) {
        int v = edges[u][i];
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          if (bv[v]) {
            q.push(v);
          }
        }
      }
    }
    set<int> s1, s2;
    s1.clear();
    s2.clear();
    for (int i = 2; i <= n; ++i) {
      if (pv[i]) {
        bool n1=false, n2=false;
        for (int j = 0; j < edges[i].size(); ++j) {
          int u = edges[i][j];
          if (cnt[par[u]] >= 2) {
            n2=true;
          }
          if (!bv[i] && bv[u]) {
            n1=true;
          }
        }
        if (n2) s2.insert(i);
        else if (n1) s1.insert(i);
      }
    }
    bool ok=false;
    for (int i = 2; i <= n; ++i) {
      if (pv[i] && dis[i] < inf) {
        bool n1=false, n2=false;
        if (s2.find(i) != s2.end()) {
          s2.erase(i);
          n2=true;
        }
        if (s1.find(i) != s1.end()) {
          s1.erase(i);
          n1=true;
        }
        if (!s2.empty()) {
          ok=true;
        } else if ((int)s1.size() >= dis[i]-1) {
          ok=true;
        }
        if (n2) s2.insert(i);
        if (n1) s1.insert(i);
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
