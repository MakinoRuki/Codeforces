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
int dp1[N][2];
int dp2[N][2];
int deg[N];
int w[N];
void dfs(int u, int p) {
  if (deg[u] == 1) {
    dp1[u][0] = 0;
    dp2[u][0] = 1;
    dp1[u][1] = 1;
    dp2[u][1] = 1;
    return ;
  }
  dp1[u][1] = 1;
  dp2[u][1] = (int)edges[u].size();
  dp1[u][0] = 0;
  dp2[u][0] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
    dp1[u][1] += dp1[v][0];
    dp2[u][1] += dp2[v][0];
    if (dp1[v][0] > dp1[v][1]) {
      dp1[u][0] += dp1[v][0];
      dp2[u][0] += dp2[v][0];
    } else if (dp1[v][0] == dp1[v][1] && dp2[v][0] < dp2[v][1]) {
      dp1[u][0] += dp1[v][0];
      dp2[u][0] += dp2[v][0];
    } else {
      dp1[u][0] += dp1[v][1];
      dp2[u][0] += dp2[v][1];
    }
  }
}
void dfs2(int u, int p, int r) {
  if (r == 1) {
    w[u] = (int)edges[u].size();
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      dfs2(v, u, 0);
    }
  } else {
    w[u] = 1;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      if (dp1[v][0] > dp1[v][1]) {
        dfs2(v, u, 0);
      } else if (dp1[v][0] == dp1[v][1] && dp2[v][0] < dp2[v][1]) {
        dfs2(v, u, 0);
      } else {
        dfs2(v, u, 1);
      }
    }
  }
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  memset(dp1, -1, sizeof(dp1));
  for (int i = 1; i <= n; ++i) {
    dp2[i][0] = dp2[i][1] = inf;
  }
  int i;
  for (i = 1; i <= n; ++i) {
    if (deg[i] > 1) {
      break;
    }
  }
  if (i > n) {
    printf("%d %d\n", 2, 2);
    printf("%d %d\n", 1, 1);
    return 0;
  }
  dfs(i, 0);
  if (dp1[i][0] > dp1[i][1]) {
    printf("%d %d\n", dp1[i][0], dp2[i][0]);
    dfs2(i, 0, 0);
  } else if (dp1[i][0] == dp1[i][1] && dp2[i][0] < dp2[i][1]) {
    printf("%d %d\n", dp1[i][0], dp2[i][0]);
    dfs2(i,0, 0);
  } else {
    printf("%d %d\n", dp1[i][1], dp2[i][1]);
    dfs2(i,0, 1);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d", w[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
