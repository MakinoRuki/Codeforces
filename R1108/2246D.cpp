
#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;

int n, t;
ll a[N];

ll calc(ll x) {
  return 63 - __builtin_clzll(x) + __builtin_popcountll(x);
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    ll mx = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      mx = max(mx, a[i]);
    }

    int m = 0;

    while ((1LL << m) < mx) {
      ++m;
    }

    ll ans = (1LL << 60);

    for (int k = 0; k <= m; ++k) {
      ll sum = -1LL * (n - 1) * k;
      ll w = (1LL << k);

      for (int i = 1; i <= n; ++i) {
        ll b = (a[i] + w - 1) / w;
        ll best = b * w - a[i] + calc(b) + k;

        for (int j = 1; j <= m - k; ++j) {
          ll p = (1LL << j);
          ll c = (b + p - 1) / p * p;
          ll x = c * w - a[i];
          ll y = calc(c) + k;

          best = min(best, x + y);
        }

        sum += best;
      }

      ans = min(ans, sum);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
