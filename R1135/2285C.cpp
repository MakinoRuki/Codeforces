
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

ll qpow(ll x, int y) {
  ll res = 1;

  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }

  return res;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    a[0] = 0;
    int pos = 0;

    for (int i = 2; i <= n; ++i) {
      if (a[i] == a[i - 1]) {
        pos = i;
      }
    }

    // 最终最大值为 x；没有重复值时，以 x = 0 为边界
    ll ans = pos > 0 ? qpow(a[pos], n - pos) : 0;

    for (int i = pos + 1; i <= n; ++i) {
      // 最终最大值在 (a[i - 1], a[i]) 内
      int cnt = n - i + 1;

      ll cur = (qpow(a[i] - 1, cnt)
                - qpow(a[i - 1], cnt) + mod) % mod;

      ans = (ans + cur) % mod;

      // 最终最大值恰好为 a[i]
      ans = (ans + qpow(a[i], n - i)) % mod;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
