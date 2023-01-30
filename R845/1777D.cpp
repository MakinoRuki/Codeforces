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
#define N 200005
#define M 2505
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
ll ans;
ll pw;
int dfs(int u, int p, int d) {
  int mx = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    mx = max(mx, dfs(v, u, d+1));
  }
  mx++;
  ll dt = ((ll)mx%mod) * pw % mod;
  ans = (ans + dt) % mod;
  return mx;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    pw = 1LL;
    for (int i = 1; i < n; ++i) {
      pw = pw * 2LL % mod;
    }
    ans = 0LL;
    dfs(1, 0, 0);
    printf("%lld\n", ans);
  }
  return 0;
}
