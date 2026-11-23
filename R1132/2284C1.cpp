
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
int a[N];
int nxt[N];
bool mark[N];

void init() {
  int lim = 200000;
  mark[0] = mark[1] = true;

  for (int i = 2; i * i <= lim; ++i) {
    if (mark[i]) {
      continue;
    }

    for (int j = i * i; j <= lim; j += i) {
      mark[j] = true;
    }
  }

  // 对于x来说，2x之内必有一个素数。
  for (int i = lim; i >= 2; --i) {
    if (!mark[i]) {
      nxt[i] = i;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }
}

int main() {
  init();
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i) {
      printf("%d%c", nxt[a[i]], i == n ? '\n' : ' ');
    }
  }

  return 0;
}
