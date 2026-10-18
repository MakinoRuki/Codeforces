
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
int deg[N];

int find(int x) {
  if (fa[x] != x) {
    fa[x] = find(fa[x]);
  }

  return fa[x];
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
      deg[i] = 0;
    }

    int tot = n;

    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);

      ++deg[u];
      ++deg[v];

      int x = find(u);
      int y = find(v);

      if (x != y) {
        fa[x] = y;
        --tot;
      }
    }

    bool flag = false;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) {
        flag = true;
      }

      if (deg[i] > 1) {
        ++cnt;
      }
    }

    if (flag) {
      printf("Brain Melt\n");
    } else if (tot > 1 || cnt != 1) {
      printf("Many\n");
    } else {
      printf("2\n");
    }
  }

  return 0;
}
