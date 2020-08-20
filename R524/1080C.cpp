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
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
ll n, m;
ll a1,b1,a2,b2;
ll a3,b3,a4,b4;
ll get1(ll x, ll y) {
	if (x%2) {
		return (y-x)/2+1;
	} else {
		x++;
		if (x<=y) {
			return (y-x)/2+1;
		}
		return 0;
	}
}
ll get2(ll x, ll y) {
	if (x%2==0) {
		return (y-x)/2+1;
	} else {
		x++;
		if (x<=y) {
			return (y-x)/2+1;
		}
		return 0;
	}
}
ll getbc(ll a, ll b, ll c, ll d) {
	ll oc = 0LL;
	ll ec = 0LL;
	if (a%2) {
		oc += (c-a)/2+1;
		ec += (c-a+1)-oc;
	} else {
		ec += (c-a)/2+1;
		oc += (c-a+1)-ec;
	}
	return oc * get2(b,d) + ec * get1(b,d);
}
ll getwc(ll a, ll b, ll c, ll d) {
	ll oc = 0LL;
	ll ec = 0LL;
	if (a%2) {
		oc += (c-a)/2+1;
		ec += (c-a+1)-oc;
	} else {
		ec += (c-a)/2+1;
		oc += (c-a+1)-ec;
	}
	return oc*get1(b,d) + ec*get2(b,d);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld",&n,&m);
		scanf("%lld%lld%lld%lld",&a1,&b1,&a2,&b2);
		scanf("%lld%lld%lld%lld",&a3,&b3,&a4,&b4);
		ll bn = 0LL, wn = 0LL;
		bn += getbc(1,1,m,n);
		wn += getwc(1,1,m,n);
	//	cout<<bn<<" "<<wn<<endl;
		bn -= getbc(a1,b1,a2,b2);
		wn -= getwc(a1,b1,a2,b2);
	//	cout<<bn<<" "<<wn<<endl;
		bn -= getbc(a3,b3,a4,b4);
		wn -= getwc(a3,b3,a4,b4);
	//	cout<<bn<<" "<<wn<<endl;
		wn += (a2-a1+1)*(b2-b1+1);
		bn += (a4-a3+1)*(b4-b3+1);
	//	cout<<bn<<" "<<wn<<endl;
		ll a5 = max(a1,a3);
		ll a6 = min(a2,a4);
		ll b5 = max(b1,b3);
		ll b6 = min(b2,b4);
		if (a5<=a6 && b5<=b6) {
		//	cout<<"a5="<<a5<<" "<<b5<<" "<<a6<<" "<<b6<<endl;
			wn += getwc(a5,b5,a6,b6);
			bn += getbc(a5,b5,a6,b6);
		//	cout<<bn<<" "<<wn<<endl;
			wn -= (a6-a5+1)*(b6-b5+1);
		}
		printf("%lld %lld\n", wn, bn);
	}
	return 0;
}
