
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

int x, y;
int a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d", &n, &x, &y);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    int g = __gcd(x, y);
    bool flag = true;

    // 每次移动的距离都是g的倍数，
    // 因此元素所在位置模g的余数不会改变。
    for (int i = 1; i <= n; ++i) {
      if (abs(i - a[i]) % g != 0) {
        flag = false;
      }
    }

    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
