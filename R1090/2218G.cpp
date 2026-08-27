
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

int b[N];

int cnt[N];
int pre[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
      cnt[i] = 0;
      pre[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      ++cnt[b[i]];
    }

    // pre[i]表示时刻i结束后，已经坐下的总人数。
    pre[0] = cnt[0];

    for (int i = 1; i < m; ++i) {
      pre[i] = pre[i - 1] + cnt[i];
    }

    ll ans = 1;

    for (int i = 1; i <= n; ++i) {
      int cur = b[i];

      // 在时刻0坐下，当且仅当a[i]=0，只有一种选择。
      if (cur == 0) {
        continue;
      }

      int minNeighborTime = inf;

      if (i > 1) {
        minNeighborTime = min(minNeighborTime, b[i - 1]);
      }

      if (i < n) {
        minNeighborTime = min(minNeighborTime, b[i + 1]);
      }

      ll ways = 0;

      // 在cur时刻之前没有任何相邻者坐下，因此无解。
      if (minNeighborTime >= cur) {
        ways = 0;
      } else if (minNeighborTime == cur - 1) {
        // 相邻条件在当前时刻才首次满足。
        // a[i]可以是1到pre[cur-1]中的任意值。
        ways = pre[cur - 1];
      } else {
        // 相邻条件之前已经满足。
        // 必须有pre[cur-2] < a[i] <= pre[cur-1]，
        // 可选数量就是上一波坐下的人数。
        ways = cnt[cur - 1];
      }

      ans = ans * ways % mod3;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
