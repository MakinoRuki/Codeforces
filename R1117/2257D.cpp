
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

ll S;

vector<ll> divisor;
vector<ll> pre;

// 返回前x列能够被百慕大矩形覆盖的最大高度之和。
ll getSum(ll x) {
  if (x <= 0) {
    return 0;
  }

  // 找到第一个不小于x的因数。
  int pos = lower_bound(divisor.begin(), divisor.end(), x)
            - divisor.begin();

  ll last = 0;
  ll ans = 0;

  if (pos > 0) {
    last = divisor[pos - 1];
    ans = pre[pos - 1];
  }

  // (last, divisor[pos]]中的每一列高度都是S/divisor[pos]。
  ans += (x - last) * (S / divisor[pos]);

  return ans;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld%d", &S, &q);

    divisor.clear();

    // 枚举S的所有因数。
    for (ll i = 1; i <= S / i; ++i) {
      if (S % i == 0) {
        divisor.push_back(i);

        if (i != S / i) {
          divisor.push_back(S / i);
        }
      }
    }

    sort(divisor.begin(), divisor.end());

    int sz = divisor.size();

    pre.assign(sz, 0);

    ll last = 0;

    // 对于列(last, divisor[i]]，
    // 能覆盖这些列的最小矩形宽度是divisor[i]，
    // 所以这些列的最大可覆盖高度为S/divisor[i]。
    for (int i = 0; i < sz; ++i) {
      ll len = divisor[i] - last;
      ll height = S / divisor[i];

      // pre[i] 表示从第 \(1\) 列到第 divisor[i] 列，所有列的“最大可覆盖高度”之和。
      // 因为按照divisor压缩之后，divisor[i]和divisor[i-1]之间的delta可能大于1.
      pre[i] = len * height;

      if (i > 0) {
        pre[i] += pre[i - 1];
      }

      last = divisor[i];
    }

    while (q--) {
      ll x, y;
      scanf("%lld%lld", &x, &y);

      // 高度至少为y的列，其对应的最小矩形宽度d满足：
      // S/d >= y，即d <= S/y。
      ll limit = S / y;

      int pos = upper_bound(divisor.begin(), divisor.end(), limit)
                - divisor.begin() - 1;

      // 前columns列的最大高度都不小于y。
      ll columns = min(x, divisor[pos]);

      ll ans = columns * y;
      ans += getSum(x) - getSum(columns);

      printf("%lld\n", ans);
    }
  }

  return 0;
}
