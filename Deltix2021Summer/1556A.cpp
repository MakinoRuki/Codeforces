#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 3000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
int c,d;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &c, &d);
    if (c == d) {
      if (c == 0) puts("0");
      else puts("1");
    } else {
      if (abs(c-d) % 2) {
        puts("-1");
      } else {
        puts("2");
      }
    }
  }
  return 0;
}
