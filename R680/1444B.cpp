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
#define N 300002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
ll p, q;
ll a[N];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod2;
		x=x*x%mod2;
		y/=2;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2*n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+2*n+1);
	ll ans=0LL;
	ll pw=1LL;
	for (int i = 2*n-1; i > n; --i) {
		pw=pw*(ll)i%mod2;
	}
	for (int i = 1; i <= 2*n; ++i) {
		if (i<=n) {
			ans=(ans-a[i]+mod2)%mod2;
		} else {
			ans=(ans+a[i])%mod2;
		}
	}
	ans=ans*pw%mod2;
	ans=ans*2LL%mod2;
	for (int i = 1; i < n; ++i) {
		ans=ans*getpw(i, mod2-2)%mod2;
	}
	//ans=ans*(ll)n%mod2;
	printf("%lld\n", ans);
	return 0;
}
