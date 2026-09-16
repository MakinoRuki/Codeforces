
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
int cnt[N];
int pre[N];

ll ans[N];
ll value[25];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 0; i <= m + 1; ++i) {
      cnt[i] = 0;
      pre[i] = 0;
      ans[i] = 0;
    }

    ll totalSum = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);

      ++cnt[a[i]];
      totalSum += a[i];
    }

    // pre[i]表示长度不超过i的胡萝卜数量。
    for (int i = 1; i <= m; ++i) {
      pre[i] = pre[i - 1] + cnt[i];
    }

    // 当2^k >= m时，选择最终长度为1，
    // 可以将所有胡萝卜完全切成单位长度。
    int maxK = 0;

    while ((1LL << maxK) < m) {
      ++maxK;
    }

    // 枚举最终出售的胡萝卜长度x。
    for (int x = 1; x <= m; ++x) {
      for (int operation = 1; operation < maxK; ++operation) {
        value[operation] = 0;
      }

      // 如果原长度l位于[j*x, (j+1)*x-1]，
      // 那么floor(l/x)=j。
      for (int j = 1; 1LL * j * x <= m; ++j) {
        int left = j * x;
        int right = min(m, (j + 1) * x - 1);

        int number = pre[right] - pre[left - 1];

        if (number == 0) {
          continue;
        }

        // k次操作最多产生2^k段。
        // 如果不能完全切成2^k段长度x，
        // 至少需要留一段作为剩余部分。
        for (int operation = 1; operation < maxK; ++operation) {
          int limit = (1 << operation) - 1;
          int contribution = min(j, limit);

          value[operation] += 1LL * contribution * number;
        }
      }

      for (int operation = 1; operation < maxK; ++operation) {
        ll pieces = 1LL << operation;
        ll exactLength = pieces * x;

        // 当原长度恰好为2^k*x时，
        // 可以完全切成2^k根长度为x的胡萝卜，
        // 因此在原来的2^k-1上额外贡献1。
        if (exactLength <= m) {
          value[operation] += cnt[exactLength];
        }

        ans[operation] = max(ans[operation], value[operation]);
      }
    }

    int k = 1;
    for (int operation = 1; operation <= k; ++operation) {
      ll answer;

      if (operation < maxK) {
        answer = ans[operation];
      } else {
        answer = totalSum;
      }

      printf("%lld", answer);

      if (operation < m) {
        printf(" ");
      }
    }

    printf("\n");
  }

  return 0;
}
