
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

vector<pair<int, int> > v;

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &q);

    v.clear();

    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      v.push_back(make_pair(a[i], i));
    }

    // 先按值排序，值相同时按原下标排序
    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      int original_pos = v[i].second;
      int target_pos = i;

      int x = original_pos ^ target_pos;

      if (x == 0) continue;

      // 找到 x 的最高位所对应的 2 的幂
      int highest_bit = 1;
      while ((highest_bit << 1) <= x) {
        highest_bit <<= 1;
      }

      ans = max(ans, highest_bit);
    }

    printf("%d\n", ans);
  }

  return 0;
}
