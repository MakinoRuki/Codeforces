
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
int cnt[1005];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 0; i <= 1000; ++i) {
      cnt[i] = 0;
    }

    ll sum = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);

      sum += a[i];
      ++cnt[a[i]];
    }

    int maxCnt = 0;
    int maxValue = 0;

    for (int i = 0; i <= 1000; ++i) {
      if (cnt[i] > maxCnt) {
        maxCnt = cnt[i];
        maxValue = i;
      }
    }

    int rest = n - maxCnt;

    if (maxCnt <= rest + 1) {
      printf("%lld\n", sum);
    } else {
      ll sumOther = sum - 1LL * maxValue * maxCnt;
      ll ans = sumOther + 1LL * maxValue * (rest + 2);

      printf("%lld\n", ans);
    }
  }

  return 0;
}
