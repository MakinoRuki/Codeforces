#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, l, r, k;
string s;
int a[N];
ll getdis(ll h1, ll x, ll y, ll h2) {
	ll d1 = x;
	ll d2 = h1-y;
	if (d1 >= h2 || d2 >= h2) return 0;
	if (h1 - (y-x) < h2) {
		return -1;
	}
	if (h2 -d1 < h2-d2) {
		return h2-d1;
	} else {
		return h2 - d2;
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll w,h;
		ll x1,y1,x2,y2;
		ll ww,hh;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &w, &h, &x1, &y1, &x2, &y2, &ww, &hh);
		ll d1 = 0, d2 = 0;
		d1 = getdis(h, y1, y2, hh);
		d2 = getdis(w, x1, x2, ww);
		ll ans = -1;
		if (d1 >= 0) {
			if (ww <= w) {
				if (ans < 0) ans= d1;
				else ans = min(ans, d1);
			}
		}
		if (d2 >= 0) {
			if (hh <= h) {
				if (ans < 0) ans =d2;
				else ans = min(ans, d2);
			}
		}
		if (ans < 0) puts("-1");
		else printf("%.10lf\n", (double)ans);
	}
  return 0;
}
