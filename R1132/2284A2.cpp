
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    ll x = 0, y = 0;

    // 使用三角形面积公式[2S=|(x_B-x_A)(y_C-y_A)-(y_B-y_A)(x_C-x_A)|.]
    for (int i = n; i >= 1; --i) {
      ll val = 1LL << a[i];

      if (x <= y) {
        x += val;
      } else {
        y += val;
      }
    }

    printf("%lld\n", x * y);
  }

  return 0;
}
