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
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
map<ll,ll> cnt;
ll solve(ll qr, ll x) {
  ll ans = 0LL;
  ll r1 = (qr+x)/2;
  ll p1 = x-r1;
  if (cnt.find(r1) != cnt.end() && cnt.find(p1) != cnt.end()) {
    if (r1 != p1) {
      ans = cnt[r1] * cnt[p1];
    } else {
      ans = cnt[r1] * (cnt[r1]-1) / 2LL;
    }
  }
  return ans;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    scanf("%d", &q);
    while(q-->0) {
      ll x,y;
      scanf("%lld%lld", &x, &y);
      ll dt = x*x - 4*y;
      ll ans = 0LL;
      ll qr = (ll)sqrt(dt);
      if (((qr * qr) == dt)) {
        if ((qr+x)%2==0) {
          ans += solve(qr, x);
        }
      }
      printf("%lld", ans);
      if (q > 1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
