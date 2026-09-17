
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;

int n, q;
char s[N];
int sum[N][4];

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 4; ++j) {
      sum[i][j] = sum[i - 1][j];
    }

    if (i > 1) {
      int x = (s[i - 1] - '0') * 2 + s[i] - '0';
      ++sum[i][x];
    }
  }

  for (int cas = 1; cas <= q; ++cas) {
    int l, r;
    scanf("%d%d", &l, &r);

    int cnt[4];

    for (int j = 0; j < 4; ++j) {
      cnt[j] = sum[r][j] - sum[l][j];
    }

    int x = (s[r] - '0') * 2 + s[l] - '0';
    ++cnt[x];

    int a = cnt[0];
    int b = cnt[3];
    int c = cnt[1];

    int lef = c;
    int rig = r - l + 1;

    while (lef < rig) {
      int mid = (lef + rig) / 2;

      if (max(0, a - mid) + max(0, b - mid) <= mid - c) {
        rig = mid;
      } else {
        lef = mid + 1;
      }
    }

    printf("%d\n", 4 * lef - (r - l + 1));
  }

  return 0;
}
