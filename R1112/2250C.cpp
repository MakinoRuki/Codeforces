
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

int l[N], r[N];
int u[N], v[N];

bool check(int m) {
  int cnt = 0;

  for (int i = 1; i <= n; ++i) {
    if (cnt == m) return true;

    int j = cnt+1;
    int right_rank = m-j+1;

    bool left_ok = !(l[i] <= j && j <= r[i]);
    bool right_ok = !(u[i] <= right_rank && right_rank <= v[i]);

    if (left_ok && right_ok) {
      cnt++;
    }
  }

  return cnt == m;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d%d", &l[i], &r[i], &u[i], &v[i]);
    }

    int ans = 0;

    for (int m = n; m >= 1; --m) {
      if (check(m)) {
        ans = m;
        break;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
