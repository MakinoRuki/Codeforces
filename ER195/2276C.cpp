
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
int sum[N];
int cnt[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < k; ++i) {
      cnt[i] = 0;
    }

    sum[0] = 0;

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      sum[i] = (sum[i - 1] + x) % k;
    }

    ll ans = 0;

    for (int i = k + 1; i <= n; ++i) {
      ++cnt[sum[i - k - 1]];
      ans += cnt[sum[i]];
    }

    printf("%lld\n", ans);
  }

  return 0;
}
