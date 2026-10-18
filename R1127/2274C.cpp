
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
int a[N];

bool check(int x) {
  ll sum = 0;

  for (int i = 1; i <= x; ++i) {
    sum += 1LL * i * (x / i);

    if (sum >= n) {
      return true;
    }
  }

  return false;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int lef = 1;
    int rig = n;

    while (lef < rig) {
      int mid = (lef + rig) / 2;

      if (check(mid)) {
        rig = mid;
      } else {
        lef = mid + 1;
      }
    }

    int x = lef;
    int r = n;
    int cnt = 0;
    int id = 0;

    for (int i = x; i >= 1; --i) {
      int c = min(x / i, r / i);

      for (int j = 1; j <= c; ++j) {
        ++id;

        for (int k = 1; k <= i; ++k) {
          a[++cnt] = id;
        }
      }

      r -= c * i;
    }

    printf("%d\n", x);

    for (int i = 1; i <= n; ++i) {
      printf("%d%c", a[i], " \n"[i == n]);
    }
  }

  return 0;
}
