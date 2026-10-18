
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

int n, t;
ll m, k;
ll lef[N], rig[N], sum[N];

ll get(ll x) {
  int p = upper_bound(lef + 1, lef + n + 1, x) - lef - 1;

  if (p == 0) {
    return 0;
  }

  return sum[p - 1] + min(x, rig[p]) - lef[p] + 1;
}

ll calc(ll x) {
  return get(x + m - 1) - get(x - 1);
}

ll solve(ll l, ll r) {
  if (l > r) {
    return -1;
  }

  ll x = calc(l);
  ll y = calc(r);

  if (k < min(x, y) || k > max(x, y)) {
    return -1;
  }

  bool flag = x <= y;

  while (l < r) {
    ll mid = l + (r - l) / 2;
    ll value = calc(mid);

    if (flag) {
      if (value >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    } else {
      if (value <= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
  }

  return l;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%lld%lld", &n, &m, &k);

    sum[0] = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld%lld", &lef[i], &rig[i]);
      sum[i] = sum[i - 1] + rig[i] - lef[i] + 1;
    }

    if (k == 0) {
      printf("%lld\n", rig[n] + 1);
      continue;
    }

    ll ans = solve(1, lef[1] - 1);

    for (int i = 1; i <= n && ans == -1; ++i) {
      ans = solve(lef[i], rig[i]);

      if (ans == -1 && i < n) {
        ans = solve(rig[i] + 1, lef[i + 1] - 1);
      }
    }

    if (ans == -1) {
      ans = solve(rig[n] + 1, rig[n] + m);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
