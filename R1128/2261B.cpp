
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int lef = inf;
    int rig = 0;

    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);

      lef = min(lef, x);
      rig = max(rig, x);
    }

    ll ans = rig;

    for (int i = 30; i >= 0; --i) {
      if (((lef >> i) & 1) != ((rig >> i) & 1)) {
        ans |= (1LL << (i + 1)) - 1;
        break;
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
