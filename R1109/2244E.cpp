
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

char s[N];

int pre[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);

    pre[0] = 0;

    // pre[i]表示前i对相邻灯泡中，状态相同的灯泡对数量。
    for (int i = 1; i < n; ++i) {
      pre[i] = pre[i - 1] + (s[i] == s[i + 1]);
    }

    while (q--) {
      int l, r;
      scanf("%d%d%d", &l, &r, &k);

      // 区间[l, r]中的相邻关系对应下标[l, r - 1]。
      int cnt = pre[r - 1] - pre[l - 1];
      int need = (cnt + 1) / 2;

      if (need <= k) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }

  return 0;
}
