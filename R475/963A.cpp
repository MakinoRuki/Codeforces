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
#define M 20005
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t;
ll n;
ll a,b,k;
string s;
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int main() {
	cin>>n>>a>>b>>k;
	cin>>s;
	ll ans = 0LL;
	ll sum=0LL;
	for (ll i = 0; i < k; ++i) {
		if (s[i] == '+') {
			sum = (sum + getpw(a, n-i) * getpw(b, i) % mod) % mod;
		} else {
			sum = (sum - getpw(a, n-i) * getpw(b, i) % mod + mod) % mod;
		}
	}
//	cout<<sum<<endl;
	ll q = (n+1)/k;
	ll pw = getpw(b, k) * getpw(a, k*(mod-2)) % mod;
	if (pw == 1) {
		ans = (ans + (q * sum % mod)) % mod;
	} else {
		if (a < b) {
			ll x = (getpw(pw, q) - 1 + mod) % mod;
			ll y = (pw -1+mod)%mod;
			x = x * getpw(y, mod-2)%mod;
			ans = (ans + x * sum % mod) % mod;
		} else {
			ll x = (1 - getpw(pw, q) + mod) % mod;
			ll y = (1 - pw + mod) % mod;
			x = x * getpw(y, mod-2) % mod;
			ans = (ans + x*sum%mod)%mod;
		}
	// 	ll y;
	// //	ll tmp = getpw(b, k) * getpw(a, (mod-2)*k) % mod;
	// //	cout<<"tmp="<<tmp<<endl;
	// 	if (a < b) {
	// 		ll x = ((ll)a * getpw(b, q) % mod - getpw(a, q+1) + mod)% mod;
	// 		y = (ll)(b-a) * getpw(a, q) % mod;
	// 		y = getpw(y, mod-2) % mod;
	// 		x = x * y % mod;
	// 		x = getpw(x, k) % mod;
	// 		ans = (ans + x * sum % mod+ mod) % mod;
	// 	} else {
	// 		ll x = (getpw(a, q+1) - (ll)a * getpw(b, q) % mod + mod)% mod;
	// 		y = (ll)(a-b) * getpw(a, q) % mod;
	// 		y = getpw(y, mod-2) % mod;
	// 		x = x * y % mod;
	// 		x = getpw(x,k)%mod;
	// 		ans = (ans + x * sum % mod+ mod) % mod;
	// 	}
	}
	cout<<ans<<endl;
	return 0;
}
