
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base = 337;

int n, t;
char s[N];
int dp[N][3];
int nxt5[N], nxt6[N];
ll val[N], coef[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 0; i <= n + 1; ++i) {
      val[i] = 0;
      coef[i] = 0;
    }

    for (int j = 0; j < 3; ++j) {
      dp[n + 1][j] = n + 1;
    }

    nxt5[n + 1] = n + 1;
    nxt6[n + 1] = n + 1;

    for (int i = n; i >= 1; --i) {
      for (int j = 0; j < 3; ++j) {
        dp[i][j] = dp[i + 1][j];
      }

      nxt5[i] = nxt5[i + 1];
      nxt6[i] = nxt6[i + 1];

      if (s[i] == '2') {
        dp[i][0] = i;
        dp[i][2] = dp[i + 1][1];
      }

      if (s[i] == '0') {
        dp[i][1] = dp[i + 1][0];
      }

      if (s[i] == '5') {
        nxt5[i] = i;
      }

      if (s[i] == '6') {
        nxt6[i] = i;
      }
    }

    for (int l = 1; l <= n; ++l) {
      int p = dp[l][2];

      if (p == n + 1) {
        continue;
      }

      int p5 = nxt5[p + 1];
      int p6 = nxt6[p + 1];

      if (p5 >= p6) {
        continue;
      }

      val[l] += p6 - p5;
      val[p5 + 1] -= p6 - p5;

      val[p5 + 1] += p6;
      val[p6] -= p6;

      coef[p5 + 1] -= 1;
      coef[p6] += 1;
    }

    for (int i = 1; i <= n; ++i) {
      val[i] += val[i - 1];
      coef[i] += coef[i - 1];

      ll bad = val[i] + 1LL * i * coef[i];
      ll ans = 1LL * i * (n - i + 1) - bad;

      printf("%lld%c", ans, " \n"[i == n]);
    }
  }

  return 0;
}
