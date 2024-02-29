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
#include <random>
#include <ctime>
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    int x,y;
    int x1,y1;
    scanf("%d%d", &x, &y);
    bool found=false;
    for (int i = 1; i <= k; ++i) {
      scanf("%d%d", &x1, &y1);
      int dt = abs(x1-x) + abs(y1-y);
      if ((dt % 2) == 0) {
        found=true;
      }
    }
    if (found) puts("NO");
    else puts("YES");
  }
  return 0;
}
