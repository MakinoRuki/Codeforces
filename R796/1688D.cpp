#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    ll tot = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    if (k >= n) {
      ll res = tot;
      res -= (ll)n*(ll)(n+1)/2;
      res += (ll)n*(ll)k;
      printf("%lld\n", res);
    } else {
      ll res = 0LL;
      ll sum = 0LL;
      for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (i-k >= 1) {
          sum -= a[i-k];
        }
        if (i >= k) {
          res=max(res, sum+(ll)k*(ll)(k-1)/2);
        }
      }
      printf("%lld\n", res);
    }
  }
  return 0;
}
