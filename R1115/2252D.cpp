
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

ll a[N];
ll d[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    // 考察操作的意义时看对差分数组的影响。
    for (int i = 2; i <= n; ++i) {
      d[i] = a[i] - a[i - 1];
    }

    int l = 2;

    while (l <= n) {
      int r = l;

      while (r + 1 <= n &&
             ((d[r] & 1LL) == (d[r + 1] & 1LL))) {
        ++r;
      }

      sort(d + l, d + r + 1);

      l = r + 1;
    }

    for (int i = 2; i <= n; ++i) {
      a[i] = a[i - 1] + d[i];
    }

    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", a[i], " \n"[i == n]);
    }
  }

  return 0;
}
