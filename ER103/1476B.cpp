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
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, k;
ll p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &p[i]);
    }
    ll l = 0, r = 1000000000000000LL;
    while(l < r) {
      ll mid = (l+r)/2;
      ll pre = p[0];
      int i;
      for (i = 1;  i< n; ++i) {
        if (p[i] * 100LL > (ll)k * (pre + mid)) {
          break;
        }
        pre += p[i];
      }
      if (i >= n) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%lld\n", r);
  }
  return 0;
}
