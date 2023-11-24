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
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll solve(ll l, ll r, ll y) {
 // cout<<l<<" "<<r<<" "<<y<<endl;
  ll cur = y;
  int z = 1;
  while(cur <= l / y) {
    cur = cur * y;
    z++;
  }
  ll res=0LL;
  while(cur <= r) {
    ll l1 = max(l, cur);
    ll r1 = r;
    if (cur   <= (r + 1)/y) {
      r1 = cur * y - 1;
    }
    if (l1 <= r1) {
      ll dt = (r1-l1+1) % mod;
      res = (res + (ll)z * dt % mod) % mod;
    }
    if (cur  <= r / y) {
      z++;
      cur = cur * y;
    } else {
      break;
    }
  }
  return res;
}
int main() {
  cin>>q;
  for (int i = 1; i <= q; ++i) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll ans = 0LL;
    for (int y = 2; y <= 60; ++y) {
      if ((1LL<<y) > r) break;
      ll l1 = max(l, (1LL<<y));
      ll r1 = min(r, (1LL<<(y+1))-1);
      if (l1 <= r1) ans = (ans + solve(l1, r1, y)) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
