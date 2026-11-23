
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

bool check(ll x) {
  int cnt = 0, p = 0, q = 0;

  for (int i = 1; i < n; ++i) {
    if (b[i] > x) {
      ++cnt;

      if (cnt == 1) p = i;
      if (cnt == 2) q = i;
      if (cnt > 2) return false;
    }
  }

  if (cnt == 0) return true;

  if (cnt == 2) {
    // 只能操作 [p + 1, q]
    for (int i = p + 1; i < q; ++i) {
      if (2LL * b[i] > x) return false;
    }

    if (abs(a[p] - 2LL * a[q]) > x) return false;
    if (abs(2LL * a[p + 1] - a[q + 1]) > x) return false;

    return true;
  }

  // 唯一超限边为 p，枚举操作区间 [l, p]
  ll mx = 0;

  for (int l = p; l >= 1; --l) {
    if (l < p) mx = max(mx, (ll)b[l]);

    // 继续向左扩展，内部最大差也不会减小
    if (2LL * mx > x) break;

    if (l > 1 && abs(a[l - 1] - 2LL * a[p]) > x) {
      continue;
    }

    if (abs(2LL * a[l] - a[p + 1]) > x) {
      continue;
    }

    return true;
  }

  // 枚举操作区间 [p + 1, r]
  mx = 0;

  for (int r = p + 1; r <= n; ++r) {
    if (r > p + 1) mx = max(mx, (ll)b[r - 1]);

    if (2LL * mx > x) break;

    if (abs(a[p] - 2LL * a[r]) > x) {
      continue;
    }

    if (r < n && abs(2LL * a[p + 1] - a[r + 1]) > x) {
      continue;
    }

    return true;
  }

  return false;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    ll l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
      b[i] = abs(a[i + 1] - a[i]);
      r = max(r, (ll)b[i]);
    }

    while (l < r) {
      ll mid = (l + r) / 2;

      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    printf("%lld\n", l);
  }

  return 0;
}
