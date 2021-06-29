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
int t, n, m;
int k;
int q;
string s;
ll fac[N];
ll getpw(ll x, ll y) {
	ll res = 1LL;
	while(y) {
		if (y&1) res = res * x % mod;
		x= x*x % mod;
		y /= 2;
	}
	return res;
}
ll getres(int x, int y) {
	ll a = fac[y] * fac[x-y] % mod;
	ll res = fac[x] * getpw(a, mod-2) % mod;
	return res;
}
int main() {
	cin>>s;
	n = (int)s.size();
	fac[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i-1] * (ll)i % mod;
	}
	int l = 0, r = 0;
	ll ans = 0LL;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ')') r++;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			l++;
			ans= (ans + getres(l+r-1, l)) % mod;
		} else {
			r--;
		}
	}
	cout<<ans<<endl;
  return 0;
}
