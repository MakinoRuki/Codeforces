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
#define N 50
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
ll getpw(ll a, ll b) {
	ll res = 1LL;
	while(b) {
		if (b&1) res=res*a%mod2;
		a = a*a%mod2;
		b/=2;
	}
	return res;
}
int main() {
	cin>>n>>m;
	if (n==2) {
		cout<<0<<endl;
		return 0;
	}
	ll res = 1LL;
	for (int i = m; i > m-n+1; --i) {
		res = res*(ll)i%mod2;
	}
	for (int i = 1; i < n; ++i) {
		res = res * getpw((ll)i, mod2-2) % mod2;
	}
	res = res * getpw(2LL, (ll)n-3) % mod2;
	res = res * (ll)(n-2) % mod2;
	cout<<res<<endl;
	return 0;
}
