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
#include <list>
#define N 200005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
ll a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    ll l = 1, r = 2000000000000LL;
    ll ans=0LL;
    while(l < r) {
      ll mid = (l+r+1)/2LL;
      ll sum=0LL;
      ll cnt=0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] <= mid) {
          sum += mid-a[i];
        } else {
          cnt++;
        }
      }
      if (sum <= k) {
        ll dt = k-sum;
        cnt = min(cnt+dt, (ll)n);
        ans = max(ans, (mid-1)*(ll)n+1+cnt);
        l = mid;
      } else {
        r = mid-1;
      }
    }
    ll sum=0LL;
    ll cnt=0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] <= r) {
        sum += r-a[i];
      } else {
        cnt++;
      }
    }
    if (sum <= k) ans = max(ans, (r-1)*(ll)n+1+cnt);
    printf("%lld\n", ans);
  }
  return 0;
}
