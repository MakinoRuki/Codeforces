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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n,m,r,k;
ll getrres(ll x) {
	ll a1=max(0LL,x-r+1);
	ll a2=min(n-1-r+1,x);
	if (a1<=a2) return a2-a1+1;
	return 0;
}
ll getcres(ll y) {
	ll b1=max(0LL,y-r+1);
	ll b2=min(m-1-r+1,y);
	if (b1<=b2) return b2-b1+1;
	return 0;
}
ll getres2(ll a, ll b) {
	ll rc=0;
	ll cc=0;
	if (n-a>=r-1 && n-a>=n-r && n-a<n) {
		rc++;
	}
	if (r==a) {
		if (n-r-1>=r-1) {
			rc += n-2*r+1;
		}
	}
	if (n-r+1==a) {
		if (r-2>=n-r) {
			rc += r-2-n+r+1;
		}
	}
	if (a-1<r-1 && a-1<n-r && a-1>=0) {
		rc++;
	}
	if (m-b>=r-1 && m-b>=m-r && m-b<m) {
		cc++;
	}
	if (r==b) {
		if (m-r-1>=r-1) {
			cc += m-2*r+1;
		}
	}
	if (m-r+1==b) {
		if (r-2>=m-r) {
			cc += r-2-m+r+1;
		}
	}
	if (b-1<r-1 && b-1<m-r && b-1>=0) {
		cc++;
	}
	//if (a==1 && b==1) cout<<"rc="<<rc<<" "<<cc<<endl;
	return rc*cc;
}
int main() {
	cin>>n>>m>>r>>k;
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		ll tmp=getrres(i)*getcres(j);
	// 		printf("%lld", tmp);
	// 		if (tmp<10) cout<<"   ";
	// 		else if (tmp<100) cout<<"  ";
	// 		else cout<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// vector<pair<ll,ll>> rk;
	// rk.clear();
	ll r1,r2,c1,c2;
	if (n%2) {
		r1=r2=n/2;
	} else {
		r2=n/2;
		r1=r2-1;
	}
	if (m%2) {
		c1=c2=m/2;
	} else {
		c2=m/2;
		c1=c2-1;
	}
	ll a=getrres(r1);
	ll b=getcres(c1);
	double tot=0.0;
	priority_queue<pair<ll,pair<ll,ll>>> pq;
	pq.push(make_pair(a*b,make_pair(a,b)));
	set<pair<ll,pair<ll,ll>>> vis;
	vis.clear();
	while(true) {
		if (k<=0) {
			break;
		}
		if (pq.empty()) {
			break;
		}
		auto top=pq.top();
		pq.pop();
		if (vis.find(top) != vis.end()) {
			continue;
		}
		vis.insert(top);
		ll a=top.second.first;
		ll b=top.second.second;
		ll res=getres2(a,b);
	//	cout<<a<<" "<<b<<" "<<res<<endl;
		if (res<=k) {
			tot += res*a*b;
			k -= res;
		} else {
			tot += k*a*b;
			k = 0;
			break;
		}
		if (a-1>0) pq.push(make_pair((a-1)*b, make_pair(a-1,b)));
		if (b-1>0) pq.push(make_pair(a*(b-1), make_pair(a,b-1)));
	}
	// while(k) {
	// 	ll res=getres2(a,b);
	// 	cout<<a<<" "<<b<<" "<<res<<endl;
	// 	if (res<=k) {
	// 		tot += a*b*res;
	// 		k -= res;
	// 	} else {
	// 		tot += a*b*k;
	// 		break;
	// 	}
	// 	if (b-1<0 || a>b) {
	// 		a--;
	// 	} else {
	// 		b--;
	// 	}
	// }
	// priority_queue<pair<ll,
	ll k2=1;
	if (n-r>=0) {
		k2 *= (n-r+1);
	} else {
		k2 *= 0;
	}
	if (m-r>=0) {
		k2 *= (m-r+1);
	} else {
		k2 *= 0;
	}
	if (k2==0) {
		double res=0.0;
		printf("%.10lf\n", res);
		return 0;
	}
	// // for (int i = 0; i < rk.size(); ++i) {
	// // 	cout<<rk[i].first<<" "<<rk[i].second<<endl;
	// // }
	// for (int i = 0; i < rk.size(); ++i) {
	// 	ll x=rk[i].first;
	// 	ll y=rk[i].second;
	// 	if (y<=k) {
	// 		tot += y*x;
	// 		k-=y;
	// 	} else {
	// 		tot += (ll)k*x;
	// 		break;
	// 	}
	// }
	tot /= (double)k2;
	printf("%.10lf\n", tot);
	return 0;
}
