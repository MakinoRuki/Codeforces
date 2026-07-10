
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
#define M 1805
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base=337;

int n, m, q;
ll k, w;
int t;
int a[N];
ll b[N];

int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%lld", &n, &k);

    m = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ) {
      int j = i;
      while (j <= n && a[j] == a[i]) {
        j++;
      }
      b[++m] = j - i;
      i = j;
    }

    sort(b + 1, b + m + 1);

    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
      sum += b[i];
    }

    ll ans = 0;
    ll rem = m;
    ll last = 0;

    int i = 1;
    while (i <= m) {
      ll now = b[i];

      ll l = last;
      ll r = now - 1;

      if (rem > 0) {
        ll diff = sum - k;
        if (diff % rem == 0) {
          ll z = diff / rem;

          if (max(l, z) <= r) {
            ans++;
          }
        }
      }

      while (i <= m && b[i] == now) {
        sum -= b[i];
        rem--;
        i++;
      }

      last = now;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
