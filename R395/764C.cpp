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
bool dp[N];
int ans;
void dfs1(int u, int p) {
  bool found=false;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs1(v, u);
    if (a[v] != a[u] || !dp[v]) {
      found=true;
    }
  }
  dp[u] = !found;
}
void dfs2(int u, int p, int cc) {
  int id = -1;
  bool ok = true;
  bool found=false;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v= edges[u][i];
    if (v==p) continue;
    if (a[u] != a[v] || !dp[v]) {
      if (!dp[v]) found=true;
      if (id < 0) id = v;
      else {
        ok=false;
      }
    }
  }
  if (!ok) {
    if (!found) {
      if (ans < 0) ans = u;
    }
    return;
  }
  if (id > 0) {
    if (cc == a[u]) {
      dfs2(id, u, cc);
    }
    if (!found && ans < 0) ans = u;
    return ;
  }
  if (ans < 0) ans=u;
  return;
}
int main() {
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  ans = -1;
  memset(dp, false, sizeof(dp));
  dfs1(1, 0);
  dfs2(1, 0, a[1]);
  if (ans < 0) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d\n", ans);
  }
  return 0;
}
