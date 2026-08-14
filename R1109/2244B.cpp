

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

ll a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }

    ll pre = 0;
    bool flag = true;

    // 为了给后面的书堆留下尽可能多的书，
    // 第i堆只保留最少的i本，多余的书全部向右移动。
    for (int i = 1; i <= n; ++i) {
      ll cur = pre + a[i];

      if (cur < i) {
        flag = false;
      } else {
        pre = cur - i;
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
