
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define N 200005
using namespace std;
typedef long long ll;

int n;
int t;
int p[3];
int z[4];
ll ans;
string res;

ll calc(ll x) {
  return x * (x + 1) / 2;
}

void check(int m) {
  int sum = m;

  for (int i = 0; i <= m; ++i) {
    if (z[i] < 0) {
      return;
    }
    sum += z[i];
  }

  if (sum != n) {
    return;
  }

  int now = 0;

  for (int i = 0; i < m; ++i) {
    now += z[i] + 1;

    if ((now & 1) != p[i]) {
      return;
    }
  }

  ll cost = 0;

  for (int i = 0; i <= m; ++i) {
    cost += calc(z[i]);
  }

  for (int i = 0; i + 1 < m; ++i) {
    if (p[i] != p[i + 1]) {
      cost += 1LL * (z[i] + 1) * (z[i + 2] + 1);
    }
  }

  if (m == 3 && p[0] == p[1] && p[1] == p[2]) {
    cost += 1LL * (z[0] + 1) * (z[3] + 1);
  }

  if (cost >= ans) {
    return;
  }

  ans = cost;
  res = string(n, '0');
  now = 0;

  for (int i = 0; i < m; ++i) {
    now += z[i] + 1;
    res[now - 1] = '1';
  }
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    ans = (1LL << 60);

    for (int m = 1; m <= min(3, n); ++m) {
      for (int mask = 0; mask < (1 << m); ++mask) {
        for (int i = 0; i < m; ++i) {
          p[i] = (mask >> i) & 1;
        }

        int type = 0;
        int cnt = 2;

        if (m == 2) {
          type = (p[0] == p[1] ? 1 : 2);
          cnt = (type == 1 ? 3 : 2);
        }

        if (m == 3) {
          if (p[0] == p[1] && p[1] == p[2]) {
            type = 3;
          } else if (p[0] != p[1] && p[1] == p[2]) {
            type = 4;
          } else if (p[0] == p[1] && p[1] != p[2]) {
            type = 5;
          } else {
            type = 6;
          }

          cnt = (type == 6 ? 2 : 3);
        }

        int sum = n + 1 - cnt;
        int mid = sum / cnt;
        int lef = max(0, mid - 4);
        int rig = min(sum, mid + 4);

        for (int x = lef; x <= rig; ++x) {
          int yl = (cnt == 3 ? lef : 0);
          int yr = (cnt == 3 ? rig : 0);

          for (int y = yl; y <= yr; ++y) {
            int w = sum - x - y;

            if (w < 0) {
              continue;
            }

            if (type == 0) {
              z[0] = x;
              z[1] = w;
            } else if (type == 1) {
              z[0] = x;
              z[1] = y;
              z[2] = w;
            } else if (type == 2) {
              z[0] = p[0] ^ 1;
              z[1] = w;
              z[2] = x - 1 - z[0];
            } else if (type == 3) {
              z[0] = p[0] ^ 1;
              z[1] = y;
              z[2] = w;
              z[3] = x - 1 - z[0];
            } else if (type == 4) {
              z[0] = p[0] ^ 1;
              z[1] = y;
              z[2] = x - 1 - z[0];
              z[3] = w;
            } else if (type == 5) {
              z[0] = x;
              z[1] = p[0] ^ p[1] ^ 1;
              z[2] = w;
              z[3] = y - 1 - z[1];
            } else {
              z[0] = p[0] ^ 1;
              z[1] = p[0] ^ p[1] ^ 1;
              z[2] = x - 1 - z[0];
              z[3] = w - 1 - z[1];
            }

            check(m);
          }
        }
      }
    }

    printf("%s\n", res.c_str());
  }

  return 0;
}
