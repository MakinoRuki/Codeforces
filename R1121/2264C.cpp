
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;

int n;
int t;
ll a[N];
ll dp[N][2];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    sort(a + 1, a + n + 1);

    dp[n][0] = 0;
    dp[n][1] = 1;

    ll sum = a[n] % mod;

    for (int i = n - 1; i >= 1; --i) {
      ll cnt = n - i;
      ll value = (sum - cnt * a[i] % mod + mod) % mod;

      dp[i][0] = (cnt * dp[i + 1][0] + dp[i + 1][1] * value) % mod;
      dp[i][1] = cnt * dp[i + 1][1] % mod;

      sum = (sum + a[i]) % mod;
    }

    printf("%lld\n", dp[1][0]);
  }

  return 0;
}
