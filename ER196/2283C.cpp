
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

int n, t;
int d[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    int m = 0;

    for (int i = 1; i <= n; ++i) {
      d[i] = 1;
      m ^= i * 2;
    }

    int len = 0;

    while ((1 << len) <= n) {
      ++len;
    }

    for (int i = len; i >= 1; --i) {
      if ((m & (1 << i)) == 0) {
        int v = 1 << (i - 1);
        d[v] = 0;
        m ^= v * 2;
        m ^= v;
      }
    }

    for (int i = 1; i <= n; ++i) {
      printf("%d%c", d[i], i == n ? '\n' : ' ');
    }
  }

  return 0;
}
