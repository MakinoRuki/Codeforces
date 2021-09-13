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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
ll fac[N];
ll getpw(ll x, ll y) {
  ll res= 1LL;
  while(y) {
    if (y%2) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  fac[0] = 1LL;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * (ll)i % mod2;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int maxv = a[1];
    int cnt=1;
    for (int i = 2; i <= n; ++i) {
      if (a[i] > maxv) {
        maxv = a[i];
        cnt = 1;
      } else if (a[i] == maxv) {
        cnt++;
      }
    }
    if (cnt > 1) {
      printf("%lld\n", fac[n]);
    } else {
      int maxv2 = -1;
      int cnt2 = 0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] < maxv) {
          if (maxv2 < 0 || a[i] > maxv2) {
            maxv2 = a[i];
            cnt2 = 1;
          } else if (a[i] == maxv2) {
            cnt2++;
          }
        }
      }
      if (maxv - maxv2 > 1) {
        puts("0");
      } else {
     //   cout<<cnt2<<endl;
        ll ans = fac[n];
        ll tmp = fac[n] * getpw(fac[cnt2+1], mod2-2) % mod2 * getpw(fac[n-cnt2-1], mod2-2) % mod2;
        tmp = tmp * fac[cnt2] % mod2;
        tmp = tmp * fac[n-cnt2-1] % mod2;
       // cout<<tmp<<endl;
        ans= (ans - tmp + mod2) % mod2;
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
