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
#include <queue>
#include <cmath>
#define N 300002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll a,b,p,x;
ll getpw(ll aa, ll rr, ll pp) {
	ll res=1LL;
	while(rr) {
		if (rr&1) res=res*aa%pp;
		aa=aa*aa%pp;
		rr/=2;
	}
	return res;
}
int main() {
	cin>>a>>b>>p>>x;
	ll ans=0LL;
	ll res=b%p;
	if (p==2) {
		if (res==1) {
			ans = x/2;
			if (x%2) ans++;
		} else {
			ans = x/2;
		}
		cout<<ans<<endl;
		return 0;
	}
	for (ll r1=0; r1<p-1; ++r1) {
		ll res1=getpw(a, r1, p);
		ll r2=getpw(res1, p-2, p);
		r2=res*r2%p;
		ll t2=getpw(p-1, p-2, p);
		ll t1=getpw(p, p-3, p-1);
		ll m=p*(p-1);
		ll r=(r1*t1%m*p%m+r2*t2%m*(p-1)%m)%m;
		if (r>0) {
			if (x>=r) {
				ans += (x-r)/m+1;
			}
		} else {
			if (x>=m) {
				ans += (x-m)/m+1;
			}
		}
	}
	// for (int i=1;i<=x;++i) {
	// 	int res=1;
	// 	for (int j = 1; j <=i;++j) {
	// 		res*=a;
	// 	}
	// 	res*=i;
	// 	if (res%p==b){
	// 		cout<<"i="<<i<<endl;
	// 	}
	// }
	cout<<ans<<endl;
	return 0;
}
