
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

char s[N];
char str[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);

    int len = 2 * n;

    for (int i = 1; i <= len; ++i) {
      str[i] = s[i];
    }

    // 双方在前k-1轮都不需要传递土豆。
    // 最后一轮中，每个形如10的位置都会同时变成01。
    for (int i = 1; i <= len; ++i) {
      int nxt = i % len + 1;

      if (s[i] == '1' && s[nxt] == '0') {
        str[i] = '0';
        str[nxt] = '1';
      }
    }

    int red = 0;
    int blue = 0;

    // 红队得分等于被淘汰的蓝队成员数量，即偶数位置的土豆数。
    // 蓝队得分等于被淘汰的红队成员数量，即奇数位置的土豆数。
    for (int i = 1; i <= len; ++i) {
      if (str[i] == '1') {
        if (i & 1) {
          ++blue;
        } else {
          ++red;
        }
      }
    }

    printf("%d %d\n", red, blue);
  }

  return 0;
}
