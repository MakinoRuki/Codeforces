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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
ll a[N];
ll b[N];
ll c[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
    }
    for (int i = n; i >= 1; --i) {
      if (i == n) {
        c[i] = b[i];
      } else {
        c[i] = max(b[i], c[i+1]-(a[i+1]-a[i]));
      }
    }
    ll tot=0LL;
    ll pre = 0;
    for (int i = 1; i <= n; ++i) {
      if (i == 1) {
        pre = c[i];
        tot += (c[i]+1)*c[i]/2;
      } else {
        if (c[i] <= a[i]-a[i-1]) {
          pre=c[i];
          tot += (c[i]+1)*c[i]/2;
        } else {
          ll det = a[i]-a[i-1];
          tot += det * pre + (det+1)*det/2;
          pre += det;
        }
      }
    }
    printf("%lld\n", tot);
  }
  return 0;
}
