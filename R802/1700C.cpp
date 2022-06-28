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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll d1 = a[1];
    ll x = -(1LL<<61)+1;
    ll d2 = 0LL;
    for (int i = 1; i <= n; ++i) {
      if (a[i] - d2 <= d1) {
        d1 = a[i] - d2;
        x = max(x, -d1);
      } else {
        d2 = a[i] - d1;
        x = max(x, -d2);
      }
    }
    x = max(x, 0LL);
    ll ans = a[1] + x + x + d2;
    printf("%lld\n", ans);
  }
  return 0;
}
