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
#include <list>
#define N 300005
#define M 1005
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
ll dp[N][3];
void dfs(int u, int p) {
  dp[u][0] = 1LL;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
  }
  dp[u][1] = 1LL;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    ll tmp = (dp[v][0] + dp[v][1]) % mod2;
    dp[u][1] = dp[u][1] * tmp % mod2;
    dp[u][2] = (dp[u][2] + dp[v][2]) % mod2;
    dp[u][2] = (dp[u][2] + dp[v][1]) % mod2;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[j][i] = 0LL;
      }
    }
    dfs(1, 0);
    ll ans=0LL;
    for (int i = 0; i < 3; ++i) {
      ans = (ans + dp[1][i]) % mod2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
