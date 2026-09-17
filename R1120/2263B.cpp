
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 1005
using namespace std;
typedef long long ll;

int n, k;
int t;
int a[N][N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    if (k < n || k > 2 * n - 1) {
      printf("-1\n");
      continue;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = 0;
      }
    }

    int d = 2 * n - 1 - k;

    for (int i = 1; i <= n; ++i) {
      if (i >= 2 && i <= d + 1) {
        a[i][i] = i;
      } else {
        a[1][i] = i;
      }
    }

    int x = n;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i][j] == 0) {
          a[i][j] = ++x;
        }

        printf("%d%c", a[i][j], " \n"[j == n]);
      }
    }
  }

  return 0;
}
