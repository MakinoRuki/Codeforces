
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;

int n;
int t;
int a[N];
int d[N];
int lef[N];
ll dp[N];
ll dp1[N];
ll sum[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 0; i <= n + 1; ++i) {
      d[i] = 0;
      lef[i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);

      ll l = 1LL * a[i] * i + 1;
      ll r = min(1LL * n, l + i - 1);

      if (l <= r) {
        ++d[l];
        --d[r + 1];
      }

      for (int j = 0; j < a[i]; ++j) {
        int l = j * i + 1;
        int r = min(n, (j + 1) * i);

        lef[r] = max(lef[r], l);
      }
    }

    dp[0] = dp1[0] = sum[0] = 1;

    int cnt = 0;
    int L = 0;

    for (int i = 1; i <= n; ++i) {
      cnt += d[i];

      dp1[i] = (cnt == 0 ? dp[i - 1] : 0);
      sum[i] = (sum[i - 1] + dp1[i]) % mod;
      dp[i] = (dp[i - 1] + dp1[i]) % mod;

      if (lef[i] > L) {
        ll value = sum[lef[i] - 1];

        if (L > 0) {
          value = (value - sum[L - 1] + mod) % mod;
        }

        dp[i] = (dp[i] - value + mod) % mod;
        L = lef[i];
      }
    }

    printf("%lld\n", dp[n]);
  }

  return 0;
}
