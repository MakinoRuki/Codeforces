
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int n, k;
int t;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    ll ans = (1LL << (n - k + 1)) + 2LL * (k - 1);

    printf("%lld\n", ans);
  }

  return 0;
}
