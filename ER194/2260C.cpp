
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

    ll sum = x + y;
    ll a = 0;

    for (int i = 29; i >= 0; --i) {
      ll w = 1LL << i;

      if ((sum & w) && a + w <= x) {
        a += w;
      }
    }

    printf("%lld %lld\n", sum, x - a);
  }

  return 0;
}
