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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int h[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &h[i]);
    }
    ll n2 = 0, n1 = 0;
    sort(h+1, h+n+1);
    ll ans = -1;
    for (int j = 0; j < 3; ++j) {
      ll l = 0, r = 1000000000000000LL;
      while(l < r) {
        ll mid = (l+r)/2;
        ll n2, n1;
        if (mid % 2) {
          n1 = (mid+1)/2;
          n2 = mid/2;
        } else {
          n1 = mid/2;
          n2 = mid/2;
        }
        int i;
        for (i = 1; i <= n; ++i) {
          ll det = h[n]+j - h[i];
          ll x2 = min(n2, det/2);
          det -= x2 * 2;
          n2 -= x2;
          if (det > 0) {
            ll y2 = min(n1, det);
            det -= y2;
            n1 -= y2;
          }
          if (det > 0) {
            break;
          }
        }
        if (i <= n) {
          l = mid+1;
        } else {
          r = mid;
        }
      }
      ans = (ans < 0 ? r : min(ans, r));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
