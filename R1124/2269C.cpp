
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;

int n, k;
int t;
ll a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    ll ans = 0;

    if (n >= 2 * k - 1) {
      for (int i = k; i <= n - k + 1; ++i) {
        ans += a[i];
      }

      for (int i = 1; i < k; ++i) {
        ans += max(a[i], a[n - i + 1]);
      }
    } else {
      for (int i = 1; i <= n - k + 1; ++i) {
        ans += max(a[i], a[n - i + 1]);
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
