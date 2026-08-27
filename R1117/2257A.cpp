
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

bool vis[26];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < 26; ++i) {
      vis[i] = false;
    }

    // 记录所有普通单词的首字母。
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);

      int x = s[0] - 'a';
      vis[x] = true;
    }

    bool flag = true;

    for (int i = 1; i <= m; ++i) {
      scanf("%s", str);

      int len = strlen(str);

      // 缩写中的每个字母都必须是某个初始单词的首字母。
      for (int j = 0; j < len; ++j) {
        int x = str[j] - 'A';

        if (!vis[x]) {
          flag = false;
        }
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
