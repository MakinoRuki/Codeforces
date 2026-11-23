
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

int n, k, t;
int a[N], b[N];
char s[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    int x, y;
    scanf("%d%d%d", &x, &y, &n);
    scanf("%s", s + 1);

    int ans = x + y;

    for (int i = 1; i <= n; ++i) {
      if (x + y == 0) break;

      if (s[i] == '+') {
        if (y > 0) {
          ++y;
        } else {
          --x;
          ++y;
        }
      } else {
        // 尽量保留至少一个2，例如初始[1,2]、操作-+-+：先删1可得到3块，先把2变1则最多只有2块。
        if (y >= 2) {
          --y;
          ++x;
        } else if (x > 0) {
          --x;
        } else {
          --y;
          ++x;
        }
      }

      ans = max(ans, x + y);
    }

    printf("%d\n", ans);
  }

  return 0;
}
