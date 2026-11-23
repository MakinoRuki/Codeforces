
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

int n, x, t;
int a[N];

bool check(int k) {
  int cnt = 0;
  ll pos = -2000000000LL;

  for (int i = 1; i <= n; ++i) {
    if (i > 1 && a[i] - a[i - 1] <= k) {
      continue;
    }

    if (i < n && a[i + 1] - a[i] <= k) {
      continue;
    }

    if (abs(a[i] - pos) <= k) {
      continue;
    }

    ++cnt;

    if (cnt > x) {
      return false;
    }

    pos = min(1000000000LL, (ll)a[i] + k);

    if (pos == a[i]) {
      --pos;
    }
  }

  return true;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &x);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    int l = 1, r = 1000000000;

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    printf("%d\n", l);
  }

  return 0;
}
