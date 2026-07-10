
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
const int base=337;

int n, m, q;
ll k, w;
int t;
int sa[M], sb[M];
int pre[M][10];
int cur[M];
int add[10];

int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    string a, b;
    cin >> a;
    cin >> b;

    n = a.size();
    m = b.size();

    a = " " + a;
    b = " " + b;

    sa[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sa[i] = (sa[i - 1] + a[i] - '0') % 10;
    }

    sb[0] = 0;
    for (int i = 1; i <= m; ++i) {
      sb[i] = (sb[i - 1] + b[i] - '0') % 10;
    }

    for (int j = 0; j <= m; ++j) {
      for (int r = 0; r < 10; ++r) {
        pre[j][r] = -inf;
      }
    }

    for (int j = 0; j <= m; ++j) {
      pre[j][0] = 0;
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        cur[j] = -inf;
      }

      for (int j = 1; j <= m; ++j) {
        int r = (sa[i] - sb[j] + 10) % 10;

        if (pre[j - 1][r] > -inf) {
          cur[j] = pre[j - 1][r] + 1;
        }
      }

      for (int r = 0; r < 10; ++r) {
        add[r] = -inf;
      }

      for (int j = 1; j <= m; ++j) {
        int r = (sa[i] - sb[j] + 10) % 10;

        if (cur[j] > add[r]) {
          add[r] = cur[j];
        }

        for (int x = 0; x < 10; ++x) {
          if (add[x] > pre[j][x]) {
            pre[j][x] = add[x];
          }
        }
      }

      if (i == n) {
        ans = cur[m];
      }
    }

    if (ans <= -inf) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}
