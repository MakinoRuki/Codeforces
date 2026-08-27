
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

vector<pair<int, int>> ans;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    int x, y;
    scanf("%d%d", &x, &y);

    n = x + y;

    bool flag = true;

    if (n & 1) {
      // 根节点的子树大小为奇数，因此根占用一个奇节点。
      // 剩余y-1个奇节点至少要给每个偶节点配一个叶子。
      if (y - 1 < x) {
        flag = false;
      }
    } else {
      // 根节点的子树大小为偶数，因此至少需要一个偶节点。
      if (x == 0 || x > y) {
        flag = false;
      }
    }

    if (!flag) {
      printf("NO\n");
      continue;
    }

    printf("YES\n");

    ans.clear();

    // 根节点已经根据n的奇偶性贡献一个对应节点。
    int evenCnt = x - (n % 2 == 0);
    int oddCnt = y - (n % 2 == 1);

    int cur = 2;

    // 每个非根偶节点连接到根，并给它连接一个叶子。
    // 这样该节点的子树大小为2。
    for (int i = 1; i <= evenCnt; ++i) {
      int evenNode = cur++;
      int leaf = cur++;

      ans.push_back({1, evenNode});
      ans.push_back({evenNode, leaf});

      --oddCnt;
    }

    // 剩余奇节点全部作为叶子直接连接到根。
    while (oddCnt--) {
      ans.push_back({1, cur});
      ++cur;
    }

    for (auto e : ans) {
      printf("%d %d\n", e.first, e.second);
    }
  }

  return 0;
}
