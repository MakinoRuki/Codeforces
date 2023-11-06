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
#define N 300005
#define M 20
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
int deg[N];
int dis[N];
int dis2[N];
void dfs(int u, int p, int d) {
  dis[u] = d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
int main() {
  cin>>n;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  int u = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      u = i;
      break;
    }
  }
  dfs(u, 0, 0);
  int v=0;
  for (int i = 1; i <= n; ++i) {
    if (i != u) {
      if (v == 0 || dis[i] > dis[v]) {
        v = i;
      }
    }
  }
  dfs(v, 0, 0);
  u = 0;
  for (int i = 1; i <= n; ++i) {
    if (i != v) {
      if (u == 0 || dis[i] > dis[u]) {
        u = i;
      }
    }
  }
 // cout<<"u="<<u<<" "<<"v="<<v<<endl;
  memset(dis2, 0, sizeof(dis2));
  for (int i = 1; i <= n; ++i) {
    dis2[i] = max(dis2[i], dis[i]);
  }
  dfs(u, 0, 0);
  for (int i = 1; i <= n; ++i) {
    dis2[i] = max(dis2[i], dis[i]);
  }
  vector<pair<int,int>> vv;
  vv.clear();
  for (int i = 1; i <= n; ++i) {
    vv.push_back(make_pair(dis2[i], i));
  }
  sort(vv.begin(), vv.end());
  int j = 0;
  for (int i = 1; i <=n; ++i) {
    while(j < vv.size() && vv[j].first < i) {
      j++;
    }
    printf("%d ", min(j+1, n));
  }
  cout<<endl;
  return 0;
}
