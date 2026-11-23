
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

int n, m, t;
int fa[N];
int level[N];
int ord[N];
int maxd[N];
bool mark[N];
bool path[N];
vector<int> g[N];

void dfs1() {
  stack<int> stk;
  stk.push(1);

  fa[1] = 0;
  level[1] = 0;

  int cnt = 0;

  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();

    ord[++cnt] = u;

    for (int v : g[u]) {
      if (v == fa[u]) {
        continue;
      }

      fa[v] = u;
      level[v] = level[u] + 1;
      stk.push(v);
    }
  }

  for (int u = n; u != 0; u = fa[u]) {
    path[u] = true;
  }
}

int dfs2() {
  int ans = level[n];

  for (int i = n; i >= 1; --i) {
    int u = ord[i];
    maxd[u] = mark[u] ? 0 : -1;

    for (int v : g[u]) {
      if (v == fa[u] || path[v]) {
        continue;
      }

      if (maxd[v] != -1) {
        maxd[u] = max(maxd[u], maxd[v] + 1);
      }
    }

    if (u != 1 && path[u] && maxd[u] != -1) {
      ans = max(ans, level[n] - level[u] + maxd[u] + 1);
    }
  }

  return ans;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      mark[i] = false;
      path[i] = false;
    }

    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);

      g[u].push_back(v);
      g[v].push_back(u);
    }

    for (int i = 1; i <= m; ++i) {
      int v;
      scanf("%d", &v);

      if (v != n) {
        mark[v] = true;
      }
    }

    dfs1();
    printf("%d\n", dfs2());
  }

  return 0;
}
