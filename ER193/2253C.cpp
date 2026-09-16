
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int n, m, x, y;
int t;
int a[N];
int b[N];

ll solve(int p, int q) {
  int i = x;
  int j = y;
  int cnt = 0;
  ll ans = 0;

  while ((i || j) && cnt < p + q) {
    if (i && j && a[i] == b[j]) {
      ans += a[i];
      ++cnt;
      --i;
      --j;
    } else if (i && (!j || a[i] > b[j])) {
      if (p > 0) {
        ans += a[i];
        --p;
      }
      --i;
    } else {
      if (q > 0) {
        ans += b[j];
        --q;
      }
      --j;
    }
  }

  return ans;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d%d", &n, &m, &x, &y);

    for (int i = 1; i <= x; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 1; i <= y; ++i) {
      scanf("%d", &b[i]);
    }

    ll ans = max(solve(n, m - 1), solve(n - 1, m));

    printf("%lld\n", ans);
  }

  return 0;
}
