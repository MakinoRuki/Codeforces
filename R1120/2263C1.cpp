
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;

int n;
int t;
int a[N];
int d[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 0; i <= n + 1; ++i) {
      d[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);

      ll l = 1LL * a[i] * i;
      ll r = min(1LL * n - 1, l + i - 1);

      if (l <= r) {
        ++d[l];
        --d[r + 1];
      }
    }

    vector<int> ans;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      cnt += d[i];

      if (cnt == 0) {
        ans.push_back(i);
      }
    }

    int m = ans.size();
    printf("%d\n", m);

    for (int i = 0; i < m; ++i) {
      printf("%d%c", ans[i], " \n"[i == m - 1]);
    }

    if (m == 0) {
      printf("\n");
    }
  }

  return 0;
}
