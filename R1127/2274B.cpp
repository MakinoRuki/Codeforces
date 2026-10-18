
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
ll a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    ll lef = a[1];
    ll rig = a[1];
    ll ans = a[1];

    for (int i = 2; i <= n; ++i) {
      ans = max(ans, a[i] + max(-lef, rig));

      ll x = a[i] + min(0LL, 2 * lef);
      ll y = a[i] + max(0LL, 2 * rig);

      lef = x;
      rig = y;
    }

    printf("%lld\n", ans);
  }

  return 0;
}
