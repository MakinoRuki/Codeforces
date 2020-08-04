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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll a, m;
vector<ll> ps;
vector<ll> rs;
ll getpw(ll x, ll y, ll md) {
	ll res=1LL;
	while(y) {
		if (y%2) res=res*x%md;
		x=x*x%md;
		y/=2;
	}
	return res;
}
ll getgcd(ll x, ll y) {
	return y==0?x:getgcd(y,x%y);
}
ll getres(vector<ll>& pv, vector<ll>& rv, ll ub) {
	ll M = 1LL;
	for (int i = 0; i < pv.size(); ++i) {
		M *= pv[i];
	//	cout<<"p="<<pv[i]<<" "<<rv[i]<<endl;
	}
	ll res = 0LL;
	for (int i = 0; i < pv.size(); ++i) {
		ll Mi = M/pv[i];
		ll ti = getpw(Mi, pv[i]-2, pv[i]);
		res = (res + Mi*ti%M*rv[i]%M)%M;
	}
	if (res <= ub) {
		return (ub-res)/M+1;
	}
	return 0;
}
int main() {
	// int c1=0,c2=0,c3=0;
	// for (int i = 0; i <= 110; ++i) {
	// 	if (i%3==2) c1++;
	// 	if (i%37==26) c2++;
	// 	if (i%3==2 && i%37==26) c3++;
	// }
	// cout<<c1<<" "<<c2<<" "<<c3<<endl;
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &a, &m);
		ll d = getgcd(a,m);
		a/=d;
		m/=d;
		ps.clear();
		rs.clear();
		ll tm = m;
		for (ll x = 2; x*x <= tm; ++x) {
			if (tm%x==0) {
				ps.push_back(x);
				rs.push_back((x-a%x+x)%x);
				while(tm%x==0) tm/=x;
			}
		}
		if (tm>1) {
			ps.push_back(tm);
			rs.push_back((tm-a%tm+tm)%tm);
		}
		int sz = ps.size();
		ll ans = 1LL;
		ll ub = ((m*d)-1)/d;
	//	cout<<"ub="<<ub<<endl;
		ans += ub;
		for (int i = 1; i < (1<<sz); ++i) {
			int cnt=0;
			vector<ll> tps;
			vector<ll> trs;
			for (int j = 0; j < sz; ++j) {
				if ((1<<j)&i) {
					tps.push_back(ps[j]);
					trs.push_back(rs[j]);
				}
			}
			cnt = tps.size();
			if (cnt%2) {
			//	cout<<"cnt="<<cnt<<" "<<ans<<endl;
				ans -= getres(tps, trs, ub);
				//cout<<"res1="<<getres(tps, trs, ub)<<endl;
			} else {
				ans += getres(tps, trs, ub);
				//cout<<"res2="<<getres(tps, trs, ub)<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
