
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

int n, k, t;
int a[N];
bool mark[N];

int calc() {
  for (int i = 0; i <= n; ++i) {
    mark[i] = false;
  }

  for (int i = 1; i <= n - k + 1; ++i) {
    mark[a[i]] = true;
  }

  int ans = 0;

  while (mark[ans]) {
    ++ans;
  }

  return ans;
}

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    int ans = calc();
    int x = -1, y = -1;

    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        swap(a[i], a[j]);

        int cur = calc();

        if (cur > ans) {
          ans = cur;
          x = i;
          y = j;
        }

        swap(a[i], a[j]);
      }
    }

    if (x == -1) {
      printf("-1\n");
    } else {
      printf("%d %d\n", x, y);
    }
  }

  return 0;
}
