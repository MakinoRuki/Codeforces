
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
ll dp[M];
ll bell[M];
ll stir[M];

void init() {
  dp[0] = 1;

  for (int i = 1; i <= 5000; ++i) {
    if (i >= 2) {
      dp[i] = (dp[i] + dp[i - 2]) % mod2;
    }

    if (i >= 3) {
      dp[i] = (dp[i] + dp[i - 3]) % mod2;
    }
  }

  stir[0] = 1;
  bell[0] = 1;

  for (int i = 1; i <= 5000; ++i) {
    for (int j = i; j >= 1; --j) {
      stir[j] = (stir[j - 1] + j * stir[j]) % mod2;
    }

    stir[0] = 0;

    for (int j = 1; j <= i; ++j) {
      bell[i] = (bell[i] + stir[j]) % mod2;
    }
  }
}

int main() {
  init();
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    int cnt0 = 0, cnt1 = 0;
    ll ways = 1;

    for (int i = 1; i <= n; ) {
      int j = i;

      while (j < n && s[j] != s[j + 1]) {
        ++j;
      }

      int len = j - i + 1;

      if (len == 1) {
        if (s[i] == '0') {
          ++cnt0;
        } else {
          ++cnt1;
        }
      } else {
        ways = ways * dp[len] % mod2;
      }

      i = j + 1;
    }

    int ans = 2 * n - cnt0 - cnt1;
    ways = ways * bell[cnt0] % mod2;
    ways = ways * bell[cnt1] % mod2;

    printf("%d %lld\n", ans, ways);
  }

  return 0;
}
