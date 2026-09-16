
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

char a[N];
char b[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", a + 1);
    scanf("%s", b + 1);

    ll ans = 0;
    bool ok = true;

    // 将奇数下标和偶数下标拆成两个独立序列。
    for (int type = 0; type < 2; ++type) {
      vector<int> va;
      vector<int> vb;

      int pos = 0;

      for (int i = type + 1; i <= n; i += 2) {
        ++pos;

        if (a[i] == '1') {
          va.push_back(pos);
        }

        if (b[i] == '1') {
          vb.push_back(pos);
        }
      }

      if (va.size() != vb.size()) {
        ok = false;
        break;
      }

      for (int i = 0; i < (int)va.size(); ++i) {
        ans += abs(va[i] - vb[i]);
      }
    }

    if (!ok) {
      printf("-1\n");
    } else {
      printf("%lld\n", ans);
    }
  }

  return 0;
}
