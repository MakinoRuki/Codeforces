#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int par[N];
vector<int> edges[N];
int deg[N];
vector<pair<int,int>> qs;
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
bool dfs(int u, int p, int tar, int len) {
  if (u == tar) {
    printf("%d\n", len);
    printf("%d", u);
    return true;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    if (dfs(v, u, tar, len+1)) {
      printf(" %d", u);
      return true;
    }
  }
  return false;
}
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
      par[pu] = pv;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
  }
  memset(deg, 0, sizeof(deg));
  cin>>q;
  qs.clear();
  while(q-->0) {
    int a, b;
    scanf("%d%d", &a, &b);
    qs.push_back(make_pair(a, b));
    deg[a]++;
    deg[b]++;
  }
  int cnt=0;
  for (int i = 1; i <=n ;++i) {
    if (deg[i] % 2) cnt++;
  }
  if (cnt == 0) {
    puts("YES");
    for (int i = 0; i < qs.size(); ++i) {
      int a = qs[i].first;
      int b = qs[i].second;
      dfs(b, 0, a, 1);
      cout<<endl;
    }
  } else {
    puts("NO");
    printf("%d\n", cnt/2);
  }
  return 0;
}
