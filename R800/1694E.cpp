#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int deg[N];
int dis[N];
int main() {
  scanf("%d%d", &n, &m);
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[v].push_back(u);
    deg[u]++;
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  for (int i = 0; i <= n; ++i) {
    dis[i] = inf;
  }
  dis[n] = 0;
  pq.push(make_pair(0, n));
  while(!pq.empty()) {
    auto pr = pq.top();
    pq.pop();
    int d = pr.first;
    int u = pr.second;
    if (dis[u] < d) continue;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (dis[u] + deg[v] < dis[v]) {
        dis[v] = dis[u] + deg[v];
        pq.push(make_pair(dis[v], v));
      }
      deg[v]--;
    }
  }
  printf("%d\n", dis[1]);
  return 0;
}
