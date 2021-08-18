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
int t, n, m, k;
int a[N];
ll fac[N];
ll pw[N];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
ll comb(int x, int y) {
	ll res = fac[x] * getpw(fac[y], mod-2) % mod;
	res = res * getpw(fac[x-y], mod-2) % mod;
	return res;
}
int main() {
	fac[0] = 1LL;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i-1]*(ll)i % mod;
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		pw[0] = 1LL;
		for (int i = 1; i <= k; ++i) {
			pw[i] = pw[i-1] * getpw(2LL, n) % mod;
		}
		ll s1 = 0LL, s2 = 0LL;
		for (int i = 0; i <= n; ++i) {
			if (i%2) {
				s1 = (s1 + comb(n, i)) % mod;
			} else {
				s2 = (s2 + comb(n, i)) % mod;
			}
		}
		ll eq = 0LL;
		if (n%2) eq = 1LL;
		eq = (eq + s2) % mod;
		if (n%2 == 0) eq = (eq - 1 + mod) % mod;
		ll gt = 0LL;
		if (n%2 == 0) {
			gt = 1LL;
		}
		ll ans = 0LL;
		ll res = 1LL;
		for (int i = k-1; i >= 0; --i) {
			ll tmp = res * gt % mod;
			tmp = tmp * pw[i] % mod;
			ans = (ans + tmp) % mod;
			res = res * eq % mod;
		}
		ans = (ans + res) % mod;
		printf("%lld\n", ans);
	}
  return 0;
}
