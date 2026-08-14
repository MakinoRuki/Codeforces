
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
ll dp[N];
ll bit[N];

void update(int x, ll value) {
  for (int i = x; i <= n; i += i & -i) {
    bit[i] = max(bit[i], value);
  }
}

ll query(int x) {
  ll ans = 0;

  for (int i = x; i >= 1; i -= i & -i) {
    ans = max(ans, bit[i]);
  }

  return ans;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      bit[i] = 0;
    }

    // first表示位置j开始满足j+a[j]<i的临界信息，
    // second表示位置j。
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> que;

    ll ans = 0;

    // 只要同时满足i-j>a[i] && i-j>a[j]即可。
    for (int i = 1; i <= n; ++i) {
      // 将所有满足j+a[j]<i的位置加入BIT。
      while (!que.empty() && que.top().first < i) {
        int j = que.top().second;
        que.pop();

        update(j, dp[j]);
      }

      // 还需要满足j<i-a[i]，
      // 即j<=i-a[i]-1。
      ll limit = 1LL * i - a[i] - 1;

      dp[i] = a[i];

      if (limit >= 1) {
        dp[i] += query((int)limit);
      }

      ans = max(ans, dp[i]);

      // 当处理到的位置大于i+a[i]时，
      // 位置i才可以作为前一个被选择的位置。
      que.push({1LL * i + a[i], i});
    }

    printf("%lld\n", ans);
  }

  return 0;
}
