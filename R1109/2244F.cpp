
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

int n, m, q;
int k, w;
int t;

int a[N];
int mn[N];
int mx[N];

bool ok[N];

vector<int> edge[N];
vector<int> order;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      edge[i].clear();
    }

    for (int i = 2; i <= n; ++i) {
      int parent;
      scanf("%d", &parent);

      // 因为i从小到大读入，所以儿子自然按照编号递增。
      edge[parent].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    order.clear();
    order.push_back(1);

    // 先得到从根向下的遍历顺序。
    for (int i = 0; i < (int)order.size(); ++i) {
      int u = order[i];

      for (int v : edge[u]) {
        order.push_back(v);
      }
    }

    // 逆序处理，保证计算一个节点时，它的儿子都已经处理完。
    reverse(order.begin(), order.end());

    for (int u : order) {
      if (edge[u].empty()) {
        ok[u] = true;
        mn[u] = mx[u] = a[u];
        continue;
      }

      ok[u] = true;
      mn[u] = inf;
      mx[u] = -inf;

      int bad = 0;
      int sz = edge[u].size();

      for (int i = 0; i < sz; ++i) {
        int v = edge[u][i];

        if (!ok[v]) {
          ok[u] = false;
        }

        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);

        if (i + 1 < sz) {
          int nxt = edge[u][i + 1];

          if (mx[v] >= mn[nxt]) {
            ++bad;
          }
        }
      }

      if (!ok[u]) {
        continue;
      }

      if (bad == 0) {
        ok[u] = true;
      } else if (bad == 1) {
        int first = edge[u][0];
        int last = edge[u][sz - 1];

        // 将唯一断点后的儿子旋转到最前面后，
        // 原来的最后一棵子树必须能接在第一棵子树之前。
        if (mx[last] < mn[first]) {
          ok[u] = true;
        } else {
          ok[u] = false;
        }
      } else {
        ok[u] = false;
      }
    }

    if (ok[1]) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
