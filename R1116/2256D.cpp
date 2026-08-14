
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

int n, m, q;
int k, w;
int t;

char s[N];

ll fac[N];
ll invFac[N];

ll quickPow(ll x, ll y) {
  ll ans = 1;

  while (y) {
    if (y & 1) {
      ans = ans * x % mod2;
    }

    x = x * x % mod2;
    y >>= 1;
  }

  return ans;
}

ll C(int x, int y) {
  if (y < 0 || y > x) {
    return 0;
  }

  return fac[x] * invFac[y] % mod2
         * invFac[x - y] % mod2;
}

int main() {
  const int maxN = 1000000;

  fac[0] = 1;

  for (int i = 1; i <= maxN; ++i) {
    fac[i] = fac[i - 1] * i % mod2;
  }

  invFac[maxN] = quickPow(fac[maxN], mod2 - 2);

  for (int i = maxN; i >= 1; --i) {
    invFac[i - 1] = invFac[i] * i % mod2;
  }

  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    int cnt[2] = {0, 0};
    int seg[2] = {0, 0};

    for (int i = 1; i <= n; ++i) {
      int x = s[i] - '0';

      ++cnt[x];

      if (i == 1 || s[i] != s[i - 1]) {
        ++seg[x];
      }
    }

    ll ans = 1;

    // 将cnt[x]个相同字符分配给seg[x]个非空连续段。
    for (int x = 0; x <= 1; ++x) {
      if (cnt[x] > 0) {
        ans = ans * C(cnt[x] - 1, seg[x] - 1) % mod2;
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
