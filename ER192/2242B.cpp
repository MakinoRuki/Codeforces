

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
#define M 1805
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base=337;

int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
int pm[N];
int c[N];

int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    if (n < 3) {
      printf("NO\n");
      continue;
    }

    b[0] = 0;
    c[0] = 0;

    for (int i = 1; i <= n; ++i) {
      b[i] = b[i - 1] + (a[i] == 1 ? 1 : -1);
      c[i] = c[i - 1] + (a[i] == 3 ? -1 : 1);
    }

    pm[n] = -inf;
    for (int i = n - 1; i >= 1; --i) {
      pm[i] = max(pm[i + 1], c[i]);
    }

    bool ok = false;

    for (int i = 1; i <= n - 2; ++i) {
      if (b[i] >= 0) {
        if (pm[i + 1] >= c[i]) {
          ok = true;
          break;
        }
      }
    }

    printf(ok ? "YES\n" : "NO\n");
  }
  return 0;
}
