#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 500005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    int res = 0;
    for (int i = 0; i < 30; ++i) {
      printf("? %d %d\n", (1<<i)-res, (3<<i)-res);
      fflush(stdout);
      scanf("%d", &x);
      if (!((1<<i) & x)) {
        res |= (1<<i);
      }
    }
    printf("! %d\n", res);
    fflush(stdout);
  }
  return 0;
}
