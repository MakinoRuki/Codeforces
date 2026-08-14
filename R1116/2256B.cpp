
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    ll ans = 0;

    // 分别枚举奇数位置序列和偶数位置序列的第一个值。
    for (int oddFirst = 0; oddFirst <= 1; ++oddFirst) {
      for (int evenFirst = 0; evenFirst <= 1; ++evenFirst) {
        bool flag = true;

        for (int i = 1; i <= n; ++i) {
          int value;

          if (i & 1) {
            // 奇数位置1,3,5,...上的值需要交替。
            value = oddFirst ^ (((i - 1) / 2) & 1);
          } else {
            // 偶数位置2,4,6,...上的值需要交替。
            value = evenFirst ^ (((i - 2) / 2) & 1);
          }

          if (s[i] != '?' && s[i] - '0' != value) {
            flag = false;
            break;
          }
        }

        if (flag) {
          ++ans;
        }
      }
    }

    printf("%lld\n", ans % mod2);
  }

  return 0;
}
