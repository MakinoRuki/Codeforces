
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
int p[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 1; i <= k; ++i) {
      scanf("%d", &p[i]);
    }

    int x = a[p[1]];

    int totalBoundary = 0;
    int maxBoundary = 0;
    int currentBoundary = 0;

    int specialIndex = 1;
    int last = 0;

    // 令d[i] = a[i] xor x，并在两端补0。
    // 如果d[i-1] != d[i]，则边界i需要被处理。
    for (int i = 1; i <= n; ++i) {
      int current = a[i] ^ x;

      if (last != current) {
        ++totalBoundary;
        ++currentBoundary;
      }

      last = current;

      // 特殊位置i位于边界i和边界i+1之间，
      // 因此处理完边界i后结束当前边界组。
      if (specialIndex <= k && p[specialIndex] == i) {
        maxBoundary = max(maxBoundary, currentBoundary);
        currentBoundary = 0;
        ++specialIndex;
      }
    }

    // 处理数组右侧的虚拟0，即边界n+1。
    if (last != 0) {
      ++totalBoundary;
      ++currentBoundary;
    }

    maxBoundary = max(maxBoundary, currentBoundary);

    // 每个需要翻转的连续段会产生两个变化边界。
    int segmentCount = totalBoundary / 2;

    // 至少需要segmentCount次操作来处理全部边界，
    // 同一边界组中的边界不能在一次操作中互相配对，
    // 因此还至少需要maxBoundary次操作。
    int ans = max(segmentCount, maxBoundary);

    printf("%d\n", ans);
  }

  return 0;
}
