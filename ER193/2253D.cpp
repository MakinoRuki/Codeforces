
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int t;
ll x, y;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld%lld", &x, &y);

    int k = 0;
    ll sum = 0;

    while (sum + k + 1 <= x + y) {
      ++k;
      sum += k;
    }

    ll lef = max(0LL, sum - y);
    ll rig = min(x, sum);
    ll dx = max(lef, min(rig, (x - y + sum) / 2));

    for (int i = k; i >= 1; --i) {
      if (dx >= i) {
        putchar('X');
        dx -= i;
      } else {
        putchar('Y');
      }
    }

    putchar('\n');
  }

  return 0;
}
