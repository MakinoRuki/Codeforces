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
    scanf("%d", &n);
    ll mx=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mx=max(mx, (ll)a[i]);
    }
    ll ans=0LL;
    if (n == 2) {
      ans = max((ll)a[1]+a[2], 2LL*abs(a[1]-a[2]));
    } else if (n >= 4) {
      ans = (ll)n * mx;
    } else {
      ll sum=(ll)a[1]+(ll)a[2]+(ll)a[3];
      ans = max(3LL*a[1], 3LL*a[3]);
      ans = max(ans, sum);
      ans = max(ans, max(3LL*abs(a[1]-a[2]), 3LL*abs(a[2]-a[3])));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
