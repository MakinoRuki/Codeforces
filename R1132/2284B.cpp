
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

int n, k, t;
int a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    reverse(a + 1, a + k + 1);

    ll sum = 0;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      if (1LL * a[i] * (i - 1) >= sum) {
        ++cnt;
      }

      sum += a[i];
    }

    if (cnt != k) {
      printf("NO\n");
      continue;
    }

    printf("YES\n");

    for (int i = 1; i <= n; ++i) {
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
  }

  return 0;
}
