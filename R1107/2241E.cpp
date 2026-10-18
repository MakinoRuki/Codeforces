
#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base = 337;

int n, t;
int a[N];
int fa[N];
int sz[N];
int ord[N];
bool square[N];
vector<int> g[N];

int main() {
  for (int i = 1; i * i <= 1000000; ++i) {
    square[i * i] = true;
  }

  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      g[i].clear();
      sz[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);

      g[u].push_back(v);
      g[v].push_back(u);
    }

    int cnt = 1;
    ord[1] = 1;
    fa[1] = 0;

    for (int i = 1; i <= cnt; ++i) {
      int u = ord[i];

      for (int v : g[u]) {
        if (v == fa[u]) {
          continue;
        }

        fa[v] = u;
        ord[++cnt] = v;
      }
    }

    for (int i = n; i >= 2; --i) {
      int u = ord[i];
      sz[fa[u]] += sz[u];
    }

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;

    for (int u = 1; u <= n; ++u) {
      if (square[a[u]]) {
        continue;
      }

      ll dp[4] = {};

      for (int v : g[u]) {
        ll s = v == fa[u] ? n - sz[u] : sz[v];

        dp[3] += dp[2] * s;
        dp[2] += dp[1] * s;
        dp[1] += s;
      }

      ans -= dp[2] + dp[3];
    }

    printf("%lld\n", ans);
  }

  return 0;
}
