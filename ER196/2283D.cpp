
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
int fa[N];
int root[N];
vector<int> g[N];

bool check(int k, int u) {
  stack<int> stk;
  stk.push(u);

  fa[u] = 0;
  root[u] = 0;

  while (!stk.empty()) {
    int v = stk.top();
    stk.pop();

    for (int w : g[v]) {
      if (w == fa[v]) {
        continue;
      }

      fa[w] = v;
      root[w] = v == u ? w : root[v];
      stk.push(w);
    }
  }

  for (int i = 1; i <= n; ++i) {
    int j = k - i;

    if (j < 1 || j > n || i >= j) {
      continue;
    }

    if (root[i] != root[j]) {
      return true;
    }
  }

  return false;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }

    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);

      g[u].push_back(v);
      g[v].push_back(u);
    }

    int ans = n + 1;

    if (n % 2 == 1) {
      for (int k = n; k <= n + 2; ++k) {
        int u;

        if (k == n) {
          u = n;
        } else if (k == n + 1) {
          u = (n + 1) / 2;
        } else {
          u = 1;
        }

        if (check(k, u)) {
          ans = k;
          break;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
