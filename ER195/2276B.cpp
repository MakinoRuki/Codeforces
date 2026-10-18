
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
char s[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    bool add = false;
    bool sub = false;

    for (int l = 1; l <= n; ) {
      int r = l;

      while (r < n && s[r + 1] == s[l]) {
        ++r;
      }

      if (r - l + 1 >= 3) {
        add = true;
      }

      if (l == r && l > 1 && r < n) {
        sub = true;
      }

      l = r + 1;
    }

    printf("%d\n", 1 + add + sub);
  }

  return 0;
}
