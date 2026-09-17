
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

ll h[N];
ll lef[N];
ll rig[N];
ll ans[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int x = 1;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &h[i]);

      lef[i] = 0;
      rig[i] = 0;

      if (h[i] > h[x]) {
        x = i;
      }
    }

    vector<pair<ll, int> > stk;
    const ll INF = (1LL << 60);

    stk.push_back(make_pair(INF, 0));

    // 顺时针从h[x+1]枚举到h[x-1]。
    for (int step = 1; step < n; ++step) {
      int i = (x + step - 1) % n + 1;
      int nxt = i % n + 1;

      ll sum = lef[i] + h[i];
      int cnt = 1;

      while (stk.back().first <= h[i]) {
        ll value = stk.back().first;
        int number = stk.back().second;

        sum += 1LL * number * (h[i] - value);
        cnt += number;

        stk.pop_back();
      }

      stk.push_back(make_pair(h[i], cnt));
      lef[nxt] = sum;
    }

    stk.clear();
    stk.push_back(make_pair(INF, 0));

    // 逆时针从h[x-1]枚举到h[x+1]。
    for (int step = 1; step < n; ++step) {
      int i = (x - step - 1 + n) % n + 1;
      int nxt = i % n + 1;

      ll sum = rig[nxt] + h[i];
      int cnt = 1;

      while (stk.back().first <= h[i]) {
        ll value = stk.back().first;
        int number = stk.back().second;

        sum += 1LL * number * (h[i] - value);
        cnt += number;

        stk.pop_back();
      }

      stk.push_back(make_pair(h[i], cnt));
      rig[i] = sum;
    }

    for (int i = 1; i <= n; ++i) {
      ans[i] = lef[i] + rig[i];
      printf("%lld%c", ans[i], " \n"[i == n]);
    }
  }

  return 0;
}
