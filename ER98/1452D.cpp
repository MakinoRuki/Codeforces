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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll fac[N];
ll fac2[N];
ll getpw(ll a, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) res=res*a%mod2;
		a=a*a%mod2;
		b/=2;
	}
	return res;
}
int main() {
	cin>>n;
	ll ans=0LL;
	ll a=-1,b=-1;
	ll cur=0;
	fac[0]=1LL;
	fac2[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i]=fac[i-1]*(ll)i%mod2;
		fac2[i]=getpw(fac[i], mod2-2)%mod2;
	}
	for (int i = 1; i <= n; i++) {
		if ((n-i)%2==0) {
			ll x=(n-i)/2;
			ll a = x+i-1;
			ll b=i-1;
			ll cur=fac[a]*fac2[b]%mod2*fac2[a-b]%mod2;
			ans=(ans+cur)%mod2;
			// if (a<0 && b<0) {
			// 	ll tmp=getcomb(x+i-1,i-1);
			// 	cur=tmp;
			// 	a = x+i-1;
			// 	b = i-1;
			// 	ans=(ans+tmp)%mod2;
			// } else {
			// 	ll cur2=cur*(a+1)%mod2*(a-b)%mod2;
			// 	cur2=cur2*getpw(b+1, mod2-2)%mod2;
			// 	cur2=cur2*getpw(b+2, mod2-2)%mod2;
			// 	ans=(ans+cur2)%mod2;
			// 	a=x+i-1;
			// 	b=i-1;
			// 	cur=cur2;
			// }
		}
	}
	ll pw=1LL;
	for (int i = 1; i <= n; ++i) {
		pw=pw*getpw(2LL, mod2-2)%mod2;
	}
	ans=ans*pw%mod2;
	printf("%lld\n", ans);
	return 0;
}
