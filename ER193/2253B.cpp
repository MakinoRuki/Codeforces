
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;

int n, m;
int t;
int c[N];
int len[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    m = 0;

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);

      if (m && c[m] == x) {
        ++len[m];
      } else {
        c[++m] = x;
        len[m] = 1;
      }
    }

    int ans = m;

    for (int i = 1; i < m; ++i) {
      if (len[i] >= 2 && len[i + 1] >= 2) {
        ans = max(ans, m + 2);
      }

      if (len[i] >= 2 && (i + 1 == m || c[i + 2] != c[i])) {
        ans = max(ans, m + 1);
      }

      if (len[i + 1] >= 2 && (i == 1 || c[i - 1] != c[i + 1])) {
        ans = max(ans, m + 1);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
