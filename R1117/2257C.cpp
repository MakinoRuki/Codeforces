
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

bool dam[N];
bool has[N];

vector<int> edge[N];
vector<int> ans;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      edge[i].clear();
      dam[i] = false;
      has[i] = false;
    }

    // 题目保证p[i] < i，因此儿子的编号一定大于父亲。
    for (int i = 2; i <= n; ++i) {
      int parent;
      scanf("%d", &parent);

      edge[parent].push_back(i);
    }

    scanf("%d", &m);

    for (int i = 1; i <= m; ++i) {
      int x;
      scanf("%d", &x);

      dam[x] = true;
    }

    ans.clear();

    // 因为父亲编号小于儿子编号，所以从大到小处理
    // 就相当于一次后序遍历。
    for (int u = n; u >= 1; --u) {
      bool leftOne = false;

      for (int v : edge[u]) {
        if (!has[v]) {
          continue;
        }

        // 如果u不是水坝，可以保留一个含水坝的儿子子树，
        // 不在连接边上安装摄像头。
        if (!dam[u] && !leftOne) {
          leftOne = true;
        } else {
          // 输出子节点v表示在(v, parent[v])上安装摄像头。
          ans.push_back(v);
        }
      }

      // 当u本身是水坝时，所有含水坝的儿子边都已安装摄像头，
      // 但以u为根的子树中仍然存在水坝u。
      has[u] = dam[u] || leftOne;
    }

    printf("%d", (int)ans.size());

    for (int x : ans) {
      printf(" %d", x);
    }

    printf("\n");
  }

  return 0;
}
