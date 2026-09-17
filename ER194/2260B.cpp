
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 1000005
using namespace std;
typedef long long ll;

int t;
ll x, y, k;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld%lld%lld", &x, &y, &k);

    ll ans = 0;
    ll lim = min(k, y);

    for (ll i = 0; i < lim; ++i) {
      ans += (y + i) % (x + i);
    }

    if (k > y) {
      ans += (k - y) * (y - x);
    }

    printf("%lld\n", ans);
  }

  return 0;
}
