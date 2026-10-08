
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 735
using namespace std;
typedef long long ll;

int n;
int t;
int cnt[N][N];

int calc(int x) {
  int sum = 0;

  while (x) {
    int d = x % 10;
    sum += d * d;
    x /= 10;
  }

  return sum;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);

      for (int j = 1; j <= 730; ++j) {
        x = calc(x);
        ++cnt[j][x];
      }
    }

    ll ans = 0;

    for (int i = 0; i <= 729; ++i) {
      ans += 1LL * cnt[730][i] * (cnt[730][i] - 1) / 2;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
