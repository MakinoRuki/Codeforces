#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int t;
int a[N][32];
void solve2(int ra, int ro, int b, int i1, int i2) {
  if (a[i1][b] >= 0 && a[i2][b] >= 0) {
    return;
  }
  if (ra & (1<<b)) {
    a[i1][b] = 1;
    a[i2][b] = 1;
  } else if (!(ro & (1<<b))) {
    a[i1][b] = 0;
    a[i2][b] = 0;
  } else {
    if (a[i1][b] >= 0) {
      if (a[i1][b] && (ra & (1<<b))) {
        a[i2][b] = 1;
      } else if (!a[i1][b] && (ro & (1<<b))) {
        a[i2][b] = 1;
      } else {
        a[i2][b] = 0;
      }
    } else if (a[i2][b] >= 0) {
      if (a[i2][b] && (ra & (1<<b))) {
        a[i1][b] = 1;
      } else if (!a[i2][b] && (ro & (1<<b))) {
        a[i1][b] = 1;
      } else {
        a[i1][b] = 0;
      }
    }
  }
}
void solve(int i1, int i2, int i3) {
  vector<int> ras;
  vector<int> ros;
  int res=0;
  printf("and %d %d\n", i1, i2);
  fflush(stdout);
  scanf("%d", &res);
  ras.push_back(res);
  printf("and %d %d\n", i2, i3);
  fflush(stdout);
  scanf("%d", &res);
  ras.push_back(res);
  printf("and %d %d\n", i1, i3);
  fflush(stdout);
  scanf("%d", &res);
  ras.push_back(res);
  if (i3 + 1 <= n) {
    printf("and %d %d\n", i3, i3+1);
    fflush(stdout);
    scanf("%d", &res);
    ras.push_back(res);
  }
  printf("or %d %d\n", i1, i2);
  fflush(stdout);
  scanf("%d", &res);
  ros.push_back(res);
  printf("or %d %d\n", i2, i3);
  fflush(stdout);
  scanf("%d", &res);
  ros.push_back(res);
  printf("or %d %d\n", i1, i3);
  fflush(stdout);
  scanf("%d", &res);
  ros.push_back(res);
  if (i3 + 1 <= n) {
    printf("or %d %d\n", i3, i3+1);
    fflush(stdout);
    scanf("%d", &res);
    ros.push_back(res);
  }
  for (int i = 30; i >= 0; --i) {
    solve2(ras[0], ros[0], i, i1, i2);
    solve2(ras[1], ros[1], i, i2, i3);
    solve2(ras[2], ros[2], i, i1, i3);
    solve2(ras[0], ros[0], i, i1, i2);
    solve2(ras[1], ros[1], i, i2, i3);
    solve2(ras[2], ros[2], i, i1, i3);
    if (i3+1<=n) {
      solve2(ras[3], ros[3], i, i3, i3+1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 30; ++j) {
      a[i][j] = -1;
    }
  }
  if (n == 3) {
    solve(1, 2, 3);
  } else {
    for (int i = 1; i <= n; i += 4) {
      if (i + 3 <= n) {
        solve(i, i+1, i+2);
      } else {
        break;
      }
    }
    if (n % 4 != 0) {
      int m = n/4*4;
      for (int i = m+1; i <= n; ++i) {
        int ra = 0, ro = 0;
        printf("and %d %d\n", m, i);
        fflush(stdout);
        scanf("%d", &ra);
        printf("or %d %d\n", m, i);
        fflush(stdout);
        scanf("%d", &ro);
        for (int j = 30; j >= 0; --j) {
          if (a[m][j]) {
            if (ra & (1<<j)) a[i][j] = 1;
            else a[i][j] = 0;
          } else {
            if (ro & (1<<j)) a[i][j] = 1;
            else a[i][j] = 0;
          }
        }
      }
    }
  }
  vector<int> ans;
  ans.clear();
  for (int i = 1; i <= n; ++i) {
    ans.push_back(0);
    for (int j = 30; j >= 0; --j) {
      ans[i-1] = ans[i-1]*2 + a[i][j];
    }
  }
  sort(ans.begin(), ans.end());
  printf("finish %d\n", ans[k-1]);
  return 0;
}
