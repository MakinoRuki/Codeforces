
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
char s[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);

    int cnt0 = 0, cnt1 = 0;

    for (int i = 1; i <= n; ++i) {
      if (s[i] == '0') ++cnt0;
      else ++cnt1;
    }

    char c = cnt0 <= cnt1 ? '0' : '1';

    for (int i = 1; i <= n && k > 0; ++i) {
      if (s[i] == c) {
        s[i] = c == '0' ? '1' : '0';
        --k;
      }
    }

    cnt0 = cnt1 = 0;
    ll ans = 1;

    for (int i = n; i >= 1; --i) {
      if (s[i] == '0') {
        ++cnt0;
        ans += cnt0;
      } else {
        ++cnt1;
        ans += cnt1;
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}
