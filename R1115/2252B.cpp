
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

    int cnt0 = 0;
    int cnt1 = 0;

    for (int i = 1; i <= n; ++i) {
      if (s[i] == '0') {
        ++cnt0;
      } else {
        ++cnt1;
      }
    }

    int len0 = 0;
    int need = 0;

    for (int i = 1; i <= n; ++i) {
      if (s[i] - '0' == need) {
        ++len0;
        need ^= 1;
      }
    }

    int len1 = 0;
    need = 1;

    for (int i = 1; i <= n; ++i) {
      if (s[i] - '0' == need) {
        ++len1;
        need ^= 1;
      }
    }

    int best = -1;

    // 最终保留串中 0 和 1 数量相同
    int len = max(len0 / 2 * 2, len1 / 2 * 2);

    if (len > 0 || n > 0) {
      int del0 = cnt0 - len / 2;
      int del1 = cnt1 - len / 2;

      if (abs(del0 - del1) <= 1) {
        best = max(best, len);
      }
    }

    // 最终保留串中 0 比 1 多一个
    len = len0;

    if (len % 2 == 0) {
      --len;
    }

    if (len >= 1) {
      int keep0 = len / 2 + 1;
      int keep1 = len / 2;

      int del0 = cnt0 - keep0;
      int del1 = cnt1 - keep1;

      if (abs(del0 - del1) <= 1) {
        best = max(best, len);
      }
    }

    // 最终保留串中 1 比 0 多一个
    len = len1;

    if (len % 2 == 0) {
      --len;
    }

    if (len >= 1) {
      int keep0 = len / 2;
      int keep1 = len / 2 + 1;

      int del0 = cnt0 - keep0;
      int del1 = cnt1 - keep1;

      if (abs(del0 - del1) <= 1) {
        best = max(best, len);
      }
    }

    if (best == -1) {
      printf("-1\n");
    } else {
      printf("%d\n", n - best);
    }
  }

  return 0;
}
