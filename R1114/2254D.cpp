
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

ll b[N];
ll ans[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    vector<pair<ll, int> > vec;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
      vec.push_back(make_pair(b[i], i));
    }

    sort(vec.begin(), vec.end());

    bool ok = true;
    ll sum = 0;
    ll last = 0;

    int l = 0;

    while (l < n) {
      int r = l;

      while (r + 1 < n && vec[r + 1].first == vec[l].first) {
        ++r;
      }

      ll shadow = vec[l].first;
      ll cnt = r - l + 1;
      ll value;

      // 当前影子必须等于前面所有较小元素之和。
      if (shadow != sum) {
        ok = false;
        break;
      }

      if (r + 1 < n) {
        ll nextShadow = vec[r + 1].first;
        ll delta = nextShadow - shadow;

        if (delta % cnt != 0) {
          ok = false;
          break;
        }

        value = delta / cnt;

        // 不同影子对应的原数组元素必须严格递增。
        if (value <= last) {
          ok = false;
          break;
        }
      } else {
        // 最后一组没有后继约束，取最小的合法值。
        value = last + 1;
      }

      for (int i = l; i <= r; ++i) {
        ans[vec[i].second] = value;
      }

      last = value;

      if (r + 1 < n) {
        sum += value * cnt;
      }

      l = r + 1;
    }

    if (!ok) {
      printf("-1\n");
      continue;
    }

    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", ans[i], " \n"[i == n]);
    }
  }

  return 0;
}
