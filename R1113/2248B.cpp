
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

int a[N];
int b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }

    if (n < 2 * m) {
      puts("NO");
      continue;
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    bool ok = true;

    for (int i = 1; i <= m; ++i) {
      int x = a[i];
      int y = a[n - m + i];

      if (!(x < b[i] && b[i] < y)) {
        ok = false;
        break;
      }
    }

    puts(ok ? "YES" : "NO");
  }

  return 0;
}
