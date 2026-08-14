

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
char str[N];

int pre[4][N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &q);

    scanf("%s", s + 1);
    scanf("%s", str + 1);

    for (int type = 0; type < 4; ++type) {
      pre[type][0] = 0;
    }

    // 先把00删掉看能不能众数相等OR先把11删掉看能不能众数相等是不对的。
    // 这样相当于只用00或者只用11去消化不match的01/10对。
    // 但我们其实可以用00和11一起去消化。
    for (int i = 1; i <= n; ++i) {
      for (int type = 0; type < 4; ++type) {
        pre[type][i] = pre[type][i - 1];
      }

      int x = s[i] - '0';
      int y = str[i] - '0';

      int type = x * 2 + y;
      ++pre[type][i];
    }

    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);

      int c00 = pre[0][r] - pre[0][l - 1];
      int c01 = pre[1][r] - pre[1][l - 1];
      int c10 = pre[2][r] - pre[2][l - 1];
      int c11 = pre[3][r] - pre[3][l - 1];

      if (abs(c01 - c10) <= c00 + c11) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }

  return 0;
}
