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
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int x,y,d;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d%d", &n, &x, &y, &d);
    int det=abs(x-y);
    if (det%d == 0) {
      printf("%d\n", det/d);
    } else {
      int res1=(abs(x-1)+d-1)/d;
      int res2=(abs(x-n)+d-1)/d;
      ll res = (1LL<<60)-1;
      if (abs(1-y)%d==0) {
        res = min(res, (ll)res1 + (ll)abs(1-y)/(ll)d);
      }
      if (abs(n-y)%d==0) {
        res = min(res, (ll)res2 + (ll)abs(n-y)/(ll)d);
      }
      if (res >= (1LL<<60)-1) {
        printf("%d\n", -1);
      } else {
        printf("%lld\n", res);
      }
    }
  }
  return 0;
}
