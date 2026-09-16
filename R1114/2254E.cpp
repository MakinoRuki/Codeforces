
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

ll b[N];
ll ans[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    vector<ll> positive;
    multiset<ll> negative;
    int zero = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);

      if (b[i] > 0) {
        positive.push_back(b[i]);
      } else if (b[i] < 0) {
        negative.insert(-b[i]);
      } else {
        ++zero;
      }
    }

    sort(positive.begin(), positive.end());

    // 第一个差分必须是正数，否则a[1]不是严格正整数。
    if (positive.empty()) {
      printf("-1\n");
      continue;
    }

    int pos = 0;
    int len = 0;
    ll sum = positive[pos++];

    ans[++len] = sum;

    bool ok = true;

    while (len < n) {
      // 找到绝对值严格小于sum的最大负数。
      auto it = negative.lower_bound(sum);

      if (it != negative.begin()) {
        --it;

        sum -= *it;
        negative.erase(it);

        ans[++len] = sum;
      } else if (zero > 0) {
        --zero;
        ans[++len] = sum;
      } else if (pos < (int)positive.size()) {
        sum += positive[pos++];
        ans[++len] = sum;
      } else {
        // 剩余负数都无法加入，说明不存在合法排列。
        ok = false;
        break;
      }
    }

    if (!ok) {
      printf("-1\n");
      continue;
    }

    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", ans[i], " \n"[i == n]);
    }
  }

  return 0;
}
