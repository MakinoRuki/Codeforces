
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    if (n == 1) {
      printf("0\n");
      continue;
    }

    // n>=2时，最少探测器数量为ceil(n/2)，即(n+1)/2。
    // 起点从1枚举到(n+1)/2，每个区间长度为floor(n/2)，即n/2。
    // 这样每个位置被哪些探测器覆盖都不同，可以唯一确定位置。
    int k = (n + 1) / 2;
    int len = n / 2;

    printf("%d\n", k);

    for (int i = 1; i <= k; ++i) {
      printf("%d %d\n", i, i + len - 1);
    }
  }

  return 0;
}
