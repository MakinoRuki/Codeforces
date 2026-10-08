
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int n, q;
int t;
int a[N];
int ok[16] = {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1};

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &q);

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ans += ok[a[i]];
    }

    printf("%d", ans);

    for (int i = 1; i <= q; ++i) {
      int p, x;
      scanf("%d%d", &p, &x);

      ans -= ok[a[p]];
      a[p] = x;
      ans += ok[a[p]];

      printf(" %d", ans);
    }

    printf("\n");
  }

  return 0;
}
