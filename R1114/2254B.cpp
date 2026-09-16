
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

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    scanf("%s", s + 1);

    int cnt = 1;

    for (int i = 2; i <= n; ++i) {
      if (s[i] != s[i - 1]) {
        ++cnt;
      }
    }

    int dec = 0;

    // 删除长度为1的段，该段会消失。
    // 如果左右两段字符相同，它们还会合并成一段。
    for (int i = 2; i < n; ++i) {
      if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
        dec = max(dec, 1);

        if (s[i - 1] == s[i + 1]) {
          dec = 2;
          break;
        }
      }
    }

    printf("%d\n", cnt - dec);
  }

  return 0;
}
