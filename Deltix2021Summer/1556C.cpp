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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t;
int a[N];
int main() {
//  cin>>t;
 // for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans= 0LL;
    ll det = 0LL;
    for (int i = 1; i <= n; i += 2) {
      if (i+1>n) break;
      ans += min(a[i], a[i+1]);
      if (a[i] >= a[i+1]) {
        det = a[i]-a[i+1];
        ll tot = 0LL;
        for (int j = i+2; j <= n; j+=2) {
          if (j+1>n) break;
          if (a[j+1] < a[j]+tot) {
            tot += a[j] - a[j+1];
            continue;
          }
          ll det2 = a[j+1]-(tot+a[j]);
          tot = 0LL;
          ans += min(det, det2) + 1;
          if (det < det2) break;
          det -= det2;
        }
      }
    }
    printf("%lld\n", ans);
 // }
  return 0;
}
