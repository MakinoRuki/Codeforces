
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

ll a[N];
ll pre[N];
int b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    pre[0] = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }

    sort(b + 1, b + m + 1);

    // 相同长度的帖子只需要保留一个。
    k = unique(b + 1, b + m + 1) - (b + 1);

    ll ans = 0;
    int last = 0;

    // 每两个相邻操作位置之间形成一个区间。
    // 每个区间都可以独立选择是否翻转，因此取区间和的绝对值。
    for (int i = 1; i <= k; ++i) {
      ll sum = pre[b[i]] - pre[last];
      ans += abs(sum);
      last = b[i];
    }

    // 最大操作位置右边的元素无法被翻转。
    ans += pre[n] - pre[last];

    printf("%lld\n", ans);
  }

  return 0;
}
