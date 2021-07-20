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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, l, r;
string s;
ll fac[N];
ll getpw(ll a, ll b) {
	ll res = 1LL;
	while(b) {
		if (b&1) {
			res = res * a % mod;
		}
		a=a*a % mod;
		b/=2;
	}
	return res;
}
ll comb(ll a, ll b) {
	if (a < 0 || b < 0) {
		return 0LL;
	}
	if (a < b) return 0LL;
	ll res = fac[a];
	res = res * getpw(fac[b], mod-2) % mod;
	res = res * getpw(fac[a-b], mod-2) % mod;
	return res;
}
int main() {
	fac[0] = 1LL;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i-1] * (ll)i % mod;
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &l, &r);
		ll ub = min(1-l, r-n);
		ll ans = 0LL;
		if (ub >= 1) {
			ll cur = comb(n, n/2);
			if (n%2) {
				cur = (cur + comb(n, n/2+1)) % mod;
			}
			ans = (ans + ub * cur % mod) % mod;
		}
		for (ll k = ub + 1; ; ++k) {
			ll lb = max(1LL, l+k);
			ll rb = min(r-k, (ll)n);
			if (lb - 1 > rb) {
				break;
			}
			ll det = rb-lb+1;
			ll cur = comb(det, n/2-(lb-1));
			if (n%2) {
				cur = (cur + comb(det, n/2+1-(lb-1)))%mod;
			}
			ans = (ans + cur) % mod;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
