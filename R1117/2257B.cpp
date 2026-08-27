
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
ll b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; ++i) {
      scanf("%lld", &b[i]);
    }

    // 从第i座山移动到第i+1座山需要承受
    // a[i] - a[i + 1] + 1次攻击。
    // 再加上最后一座山被削到0所需的a[n]次攻击，
    // 总次数会化简为a[1] + n - 1。
    ll cntBea = a[1] + n - 1;
    ll cntVer = b[1] + m - 1;

    // Bea先手，因此承受次数相同时，Ver会先认输。
    if (cntBea >= cntVer) {
      printf("1\n");
    } else {
      printf("2\n");
    }
  }

  return 0;
}
