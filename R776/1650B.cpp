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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    int res = r/a+r%a;
    if (r - 1 >= l) {
      res = max(res, (r-1)/a+(r-1)%a);
    }
    if (r % a != 0) {
      int r2 = r - r%a;
      if (r2 >= l) res = max(res, r2/a + r2 %a);
      if (r2 - 1>=l) res = max(res, (r2-1)/a + (r2-1) % a);
    }
    printf("%d\n", res);
  }
  return 0;
}
