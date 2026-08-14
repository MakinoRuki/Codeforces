
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

ll v[N];
ll a[N];
ll b[N];

int cnt[N * 2];
ll sum[N * 2];

void update(int rt, int l, int r, int pos, ll val) {
  if (l == r) {
    ++cnt[rt];
    sum[rt] += val;
    return;
  }

  int mid = (l + r) >> 1;

  if (pos <= mid) {
    update(rt << 1, l, mid, pos, val);
  } else {
    update(rt << 1 | 1, mid + 1, r, pos, val);
  }

  cnt[rt] = cnt[rt << 1] + cnt[rt << 1 | 1];
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// 从最大的数开始取，凑出至少 need 的和
// 返回最少需要取多少个
int query(int rt, int l, int r, ll need) {
  if (need <= 0) {
    return 0;
  }

  if (l == r) {
    ll val = b[l];

    return (need + val - 1) / val;
  }

  int mid = (l + r) >> 1;

  // 优先拿右边，也就是较大的数
  if (sum[rt << 1 | 1] >= need) {
    return query(rt << 1 | 1, mid + 1, r, need);
  }

  return cnt[rt << 1 | 1] +
         query(rt << 1, l, mid,
               need - sum[rt << 1 | 1]);
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &v[i]);
    }

    int tot = n * m;

    for (int i = 1; i <= tot; ++i) {
      scanf("%lld", &a[i]);
      b[i] = a[i];
    }

    sort(b + 1, b + tot + 1);

    int len = unique(b + 1, b + tot + 1) - b - 1;

    for (int i = 1; i <= len * 4; ++i) {
      cnt[i] = 0;
      sum[i] = 0;
    }

    int ans = m;

    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= m; ++j) {
        int id = (i - 1) * m + j;

        int pos = lower_bound(b + 1, b + len + 1, a[id]) - b;

        update(1, 1, len, pos, a[id]);
      }

      // 当前线段树中正好是第 i...n 行的所有块
      // 这些块都可以降低第 i 层的稳定值
      if (sum[1] >= v[i]) {
        int need = query(1, 1, len, v[i]);

        ans = min(ans, need);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
