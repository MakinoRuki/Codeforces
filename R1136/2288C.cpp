
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      a[i] = (a[i] - 1) / k + 1;
    }

    sort(a + 1, a + n + 1);

    // 留下最大的那个，不参与攻击
    --n;

    int head = 1, cnt = 0;
    ll delta = 0, ans = 0;

    while (head <= n) {
      while (head <= n && a[head] - delta == 1) {
        ++cnt;
        ++head;
      }

      // 剩下的全是1，可以全部免费消灭
      if (head > n) break;

      if (cnt > 0) {
        // 消灭一个1，同时攻击所有非1的
        --cnt;
        ++delta;
      } else {
        // 集体减到最小值变成1
        ll cost = a[head] - delta - 1;
        ans += cost;
        delta += cost;
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
