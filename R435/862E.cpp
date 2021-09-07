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
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, q, k;
ll a[N];
ll b[N];
void calc(vector<ll>& rk, ll tot) {
  auto itr = upper_bound(rk.begin(), rk.end(), tot);
  if (itr == rk.begin()) {
    printf("%lld\n", (*itr)-tot);
  } else if (itr == rk.end()) {
    printf("%lld\n", tot-rk.back());
  } else {
    auto itr2 = itr;
    itr2--;
    ll ans = min(tot-(*itr2), (*itr)-tot);
    printf("%lld\n", ans);
  }
}
int main() {
  cin>>n>>m>>q;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%lld", &b[i]);
  }
  ll tot = 0LL;
  for (int i = 1; i <= n; ++i) {
    if (i % 2) tot += a[i];
    else tot -= a[i];
  }
  vector<ll> rk;
  rk.clear();
  ll tot2=0LL;
  for (int i = 1; i <= m; ++i) {
    if (i <= n) {
      if (i%2) tot2 += b[i];
      else tot2 -= b[i];
    } else {
      tot2 -= b[i-n];
      tot2 = -tot2;
      if (n%2) tot2 += b[i];
      else tot2 -= b[i];
    }
    if (i >= n) rk.push_back(tot2);
  }
  sort(rk.begin(), rk.end());
  calc(rk, tot);
  while(q-->0) {
    int l, r;
    ll x;
    scanf("%d%d%lld", &l, &r, &x);
    if ((r-l+1)%2==0) {
      calc(rk, tot);
    } else {
      if (l%2) tot+=x;
      else tot -=x;
      calc(rk, tot);
    }
  }
  return 0;
}
