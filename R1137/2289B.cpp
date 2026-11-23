
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
int a[N], b[N];
int cnt[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
    }

    int l = 1, r = n - k + 1;
    int diff = 0, ans = 0;

    for (int i = l; i <= r; ++i) {
      if (cnt[a[i]] == 0) ++diff;
      ++cnt[a[i]];
    }

    while (true) {
      if (diff == 1) ++ans;
      if (r == n) break;

      --cnt[a[l]];
      if (cnt[a[l]] == 0) --diff;
      ++l;

      ++r;
      if (cnt[a[r]] == 0) ++diff;
      ++cnt[a[r]];
    }

    printf("%d\n", ans);
  }

  return 0;
}
