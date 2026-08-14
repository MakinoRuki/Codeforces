
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

vector<pair<int, int> > v;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n - 1; ++i) {
      scanf("%d", &a[i]);
    }

    if (n == 1) {
      puts("1");
      continue;
    }

    bool ok = true;

    for (int i = 1; i <= n - 1; ++i) {
      if (a[i] < 1 || a[i] >= n) {
        ok = false;
      }
    }

    v.clear();

    for (int i = 1; i <= n - 1; ) {
      int j = i;

      while (j <= n - 1 && a[j] == a[i]) {
        j++;
      }

      // first = 这一段的最大值
      // second = 这一段的长度
      v.push_back(make_pair(a[i], j - i));

      i = j;
    }

    int sz = v.size();
    int peak = -1;

    for (int i = 0; i < sz; ++i) {
      if (v[i].first == n - 1) {
        if (peak != -1) {
          ok = false;
        }
        peak = i;
      }
    }

    if (peak == -1) {
      ok = false;
    }

    if (ok) {
      for (int i = 0; i < peak; ++i) {
        if (v[i].first >= v[i + 1].first) {
          ok = false;
        }
      }

      for (int i = peak; i + 1 < sz; ++i) {
        if (v[i].first <= v[i + 1].first) {
          ok = false;
        }
      }
    }

    // 同一个值不能同时出现在峰值左右两边
    if (ok) {
      set<int> s;

      for (int i = 0; i < sz; ++i) {
        if (s.count(v[i].first)) {
          ok = false;
          break;
        }
        s.insert(v[i].first);
      }
    }

    if (!ok) {
      printf("0\n");
      continue;
    }

    // 按最大值从小到大处理自由位置
    sort(v.begin(), v.end());

    ll ans = 2;
    int used = 0;

    for (int i = 0; i < sz; ++i) {
      int x = v[i].first;
      int len = v[i].second;

      int need = len - 1;

      // 小于 x 的数字共有 x-1 个
      // 其中 i 个是已经确定为其他段最大值的数字
      // used 个已经填入之前的自由位置
      int cnt = x - 1 - i - used;

      if (cnt < need) {
        ok = false;
        break;
      }

      // P(cnt, need)
      for (int j = 0; j < need; ++j) {
        ans = ans * (cnt - j) % mod2;
      }

      used += need;
    }

    if (!ok) {
      printf("0\n");
    } else {
      printf("%lld\n", ans);
    }
  }

  return 0;
}
