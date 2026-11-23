
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
int a[N], b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);

    int cnta = 0, cntb = 0;

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnta += a[i] % 2;
    }

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      cntb += b[i] % 2;
    }

    bool flag = true;

    if (cnta < cntb && k % 2 == 0) {
      flag = false;
    }

    if (cnta > cntb && k % 2 == 1) {
      flag = false;
    }

    printf("%s\n", flag ? "YES" : "NO");
  }

  return 0;
}
