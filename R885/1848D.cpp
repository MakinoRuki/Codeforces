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
#include <stack>
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
ll calc(ll x, ll s, ll k, ll c1, ll c2) {
  ll res = (s + 20LL * x + c1) * (k - 4LL*x + c2);
  return res;
}
ll solve(ll k, ll s, ll c, ll r, ll c1, ll c2) {
  if (0 > r) return -1;
  ll x = (5LL*k-s+c)/40LL;
  ll lv = calc(0, s, k, c1, c2);
  ll rv = calc(r, s, k, c1, c2);
  ll res=max(lv, rv);
  if (x-1 >= 0 && x-1 <= r) {
    res = max(res, calc(x-1, s, k, c1, c2));
  }
  if (x >= 0 && x <= r) {
    res = max(res, calc(x, s, k, c1, c2));
  }
  if (x+1>=0 && x+1<=r) {
    res=max(res, calc(x+1, s, k, c1, c2));
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s;
    scanf("%d%d", &s, &k);
    ll ans=0LL;
    if ((s%10)==0) {
      ans = (ll)s * (ll)k;
    } else if ((s%10)==5) {
      if (k==1) {
        ans = (ll)s*(ll)k;
      } else {
        ans = (ll)s*(ll)k;
        s += 5;
        ans = max(ans, (ll)s * (ll)(k-1));
      }
    } else {
      ll tmp = s;
      for (int i = 0; i <= min(6, k-1); ++i) {
        ll dt = k-i;
        ans = max(ans, tmp * dt);
        tmp += tmp%10;
      }
      while(((s % 10)!=2) && k) {
        s += s%10;
        k--;
      }
      if ((s%10)==2) {
        ans = max(ans, solve(k, s, 0, (k-1)/4, 0, 0));
        ans = max(ans, solve(k, s, -7, (k-2)/4, 2, -1));
        ans = max(ans, solve(k, s, -16, (k-3)/4, 6, -2));
        ans = max(ans, solve(k, s, -31, (k-4)/4, 14, -3));
      }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

