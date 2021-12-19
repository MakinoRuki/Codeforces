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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int a[N];
vector<int> edges[N];
ll dp[N][2];
int id[N][2];
ll dfs(int u, int p) {
  ll tot = a[u];
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    ll res = dfs(v, u);
    ll res2 = max(res, dp[v][0]);
    if (res2 > dp[u][0]) {
      dp[u][1] = dp[u][0];
      id[u][1] = id[u][0];
      dp[u][0] = res2;
      id[u][0] = v;
    } else if (res2 > dp[u][1]) {
      dp[u][1] = res2;
      id[u][1] = v;
    }
    tot += res;
  }
  return tot;
}
void dfs2(int u, int p, ll& ans) {
//  ll res1 = max(pre, dp[u][0]);
 // ll res2 = max(pre, dp[u][1]);
 // if (u == 3) cout<<"v="<<pre<<" "<<dp[u][0]<<" "<<dp[u][1]<<endl;
  // if (res1 > -(1LL<<60) && dp[u][1] > -(1LL<<60)) {
  //   ans=max(ans, dp[u][1] + res1);
  // }
  // if (res2 > -(1LL<<60) && dp[u][0] > -(1LL<<60)) {
  //   ans=max(ans, dp[u][0] + res2);
  // }
  if (dp[u][0] > -(1LL<<60) && dp[u][1] > -(1LL<<60)) {
    ans=max(ans, dp[u][0] + dp[u][1]);
  }
//  cout<<"u="<<u<<" "<<ans<<endl;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    // if (v == id[u][1]) dfs2(v, u, max(pre, dp[u][0]), ans);
    // else dfs2(v, u, max(pre, dp[u][1]), ans);
    dfs2(v, u, ans);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i= 1; i <= n; ++i) {
    dp[i][0] = -(1LL<<60);
    dp[i][1] = -(1LL<<60);
  }
  memset(id, -1, sizeof(id));
  dfs(1, 0);
  ll ans = -(1LL<<60);
  dfs2(1, 0, ans);
  if (ans <= -(1LL<<60)) puts("Impossible");
  else printf("%lld\n", ans);
  return 0;
}
