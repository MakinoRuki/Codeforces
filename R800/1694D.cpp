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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int p[N];
int l[N], r[N];
vector<int> edges[N];
int ans;
ll dfs(int u) {
  if (edges[u].empty()) {
    ans++;
    return r[u];
  }
  ll tot=0LL;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    tot += dfs(v);
  }
  if (tot < l[u]) {
    ans++;
    return r[u];
  }
  return min(tot, (ll)r[u]);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &p[i]);
      edges[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &l[i], &r[i]);
    }
    ans = 0;
    dfs(1);
    printf("%d\n", ans);
  }
  return 0;
}
