
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }

    int ans = 0;

    // 最终剩余的值一定等于某两个原始元素的异或值。
    // 任意两个元素都可以被保留到最后，因此枚举所有数对。
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        ans = max(ans, a[i] ^ a[j]);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
