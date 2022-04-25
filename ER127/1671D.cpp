#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x;
    scanf("%d%lld", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll ans = 0LL;
    for (int i = 2;i <=n; ++i) {
      ans += (ll)abs(a[i] - a[i-1]);
    }
    ll d1 = 0LL;
    ll mx = (ll)abs(a[1] - 1);
    for (int i = 1; i < n; ++i) {
      //mx = min(mx, (ll)abs(min(a[i], a[i+1]) - 1) * 2LL);
      ll v1 = min(a[i], a[i+1]);
      ll v2 = max(a[i], a[i+1]);
      if (v1 <= 1 && v2 >= 1) {
        mx = min(mx, 0LL);
      } else {
        mx = min(mx, abs(v1-1) * 2LL);
      }
    }
    mx = min(mx, abs(a[n] - 1LL));
    d1 += mx;
    mx = (ll)abs(a[1] - x);
    for (int i = 1; i < n; ++i) {
      //mx = min(mx, (ll)abs(min(a[i], a[i+1]) - 1) * 2LL);
      ll v1 = min(a[i], a[i+1]);
      ll v2 = max(a[i], a[i+1]);
      if (v1 <= x && v2 >= x) {
        mx = min(mx, 0LL);
      } else {
        mx = min(mx, abs(v2-x) * 2LL);
      }
    }
    mx = min(mx, abs(a[n] - x));
    d1 += mx;
    ll d2 = 0LL;
    mx = (ll)(x-1) + min(abs(a[1]-x), abs(a[1]-1LL));
    mx = min(mx, (ll)(x-1) + min(abs(a[n]-x), abs(a[n]-1LL)));
    for (int i = 1; i < n; ++i) {
      ll v1 = min(a[i], a[i+1]);
      ll v2 = max(a[i], a[i+1]);
      ll det = (ll)(x-1) + abs(x-v2) + abs(1-v1);
      det = max(0LL, det - abs(v1-v2));
      mx = min(mx, det);
    }
    d2 = mx;
    ans += min(d1, d2);
    printf("%lld\n", ans);
  }
  return 0;
}
