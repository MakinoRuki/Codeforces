
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
    scanf("%d", &n);
    scanf("%s", s + 1);

    ll sum = 0;
    int cnt = 0;
    bool flag = false;

    for (int i = 1; i <= n; ++i) {
      if (s[i] == '1') {
        ++cnt;
      } else {
        sum += cnt;

        if (cnt % 2 == 1) {
          flag = true;
        }
      }
    }

    cnt = 0;

    for (int i = n; i >= 1; --i) {
      if (s[i] == '0') {
        ++cnt;
      } else {
        if (cnt % 2 == 1) {
          flag = true;
        }
      }
    }

    if (sum % 2 == 1 || flag) {
      printf("Alice\n");
    } else {
      printf("Bob\n");
    }
  }

  return 0;
}
