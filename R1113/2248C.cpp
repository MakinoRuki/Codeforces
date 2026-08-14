
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
int pos[N];
ll dp[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int len = 2 * n;

    for (int i = 1; i <= n; ++i) {
      pos[i] = 0;
    }

    for (int i = 0; i <= len; ++i) {
      dp[i] = 0;
    }

    for (int i = 1; i <= len; ++i) {
      scanf("%d", &a[i]);
    }

    dp[0] = 0;

    for (int i = 1; i <= len; ++i) {
      // 当前元素最终单独贡献 1
      dp[i] = dp[i - 1] + 1;

      if (pos[a[i]] == 0) {
        // 第一次出现
        pos[a[i]] = i;
      } else {
        // 第二次出现
        int l = pos[a[i]];
        ll length = i - l + 1;

        dp[i] = max(dp[i],
                    dp[l - 1] + length * length);
      }
    }

    printf("%lld\n", dp[len]);
  }

  return 0;
}
