#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500020
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
ll getpw(ll cur) {
	ll b = mod-2;
	ll res=1LL;
	while(b) {
		if (b&1) res=res*cur%mod;
		cur=cur*cur%mod;
		b/=2;
	}
	return res;
}
// Ei represents expectation value to get n+1 place when currently at i.
// Ei = 1 + pi * Ei+1 + (1-pi) * E1
// En+1 = 0
// En = E1 - 1/pn-1 - 1/pn-1pn-2 - 1/pn-1pn-2...p1
// E1 = (p1 + p1p2 + ... +p1...pn-1) / (p1...pn)
int main() {
	cin>>n;
	ll ans = 0LL;
	ll cur = 1LL;
	for (int i = 0; i < n; ++i) {
		int p;
		cin>>p;
		ll p2 = (ll)p * getpw(100) % mod;
		ans = (ans + cur)%mod;
		cur = cur * p2 % mod;
	}
	ans = ans * getpw(cur) % mod;
	cout<<ans<<endl;
	return 0;
}
