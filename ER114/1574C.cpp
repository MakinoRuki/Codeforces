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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
ll a[N];
int main() {
  cin>>n;
  ll tot=0LL;
  vector<ll> v;
  v.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    tot += (ll)a[i];
    v.push_back(a[i]);
  }
  //sort(a+1, a+n+1);
  sort(v.begin(), v.end());
  cin>>m;
  while(m-->0) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    auto id = upper_bound(v.begin(), v.end(), x) - v.begin();
    if (id == 0) {
      ll det = tot - v[0];
      if (det < y) {
        printf("%lld\n", y-det);
      } else {
        puts("0");
      }
    } else if (id == n) {
      ll ans = x - v[n-1];
      ll det = tot - v[n-1];
      if (det < y) {
        printf("%lld\n", y-det + ans);
      } else {
        printf("%lld\n", ans);
      }
    } else {
      ll ans1 = x - v[id-1];
      ll det=tot-v[id-1];
      if (det < y) ans1+=y-det;
      ll ans2 = 0LL;
      det = tot-v[id];
      if (det < y) ans2 += y-det;
      printf("%lld\n", min(ans1, ans2));
    }
    // ll l = 0, r = x+y;
    // while(l < r) {
    //   ll mid=(l+r)/2;
    //   ll tot2 = tot + mid;
    //   ll det = 0;
    //   if (id == 0) {
    //     tot2 -= v[0];
    //     det = v[0];
    //   } else {
    //     tot2 -= x;
    //     det = v[id-1];
    //   }
    //   if (tot2 >= y && tot2 >= tot - det) {
    //     r = mid;
    //   } else {
    //     l = mid+1;
    //   }
    // }
    // printf("%lld\n", r);
  }
  return 0;
}
