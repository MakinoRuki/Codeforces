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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n;
ll k;
ll l1, r1;
ll l2, r2;
ll getres(int len) {
	ll a=l1, b=r1;
	ll c=l2, d=r2;
	if (a > c) {
		swap(a,c);
		swap(b,d);
	}
	if (len <= 0) return 0;
	ll ans = 0LL;
	if (b>=d) {
		ll d1 = d-c;
		ll d2 = b-a;
		if (len <= d1) return 0;
		ll det = len-d1;
		if (det <= d2-d1) {
			return det;
		}
		det -= (d2-d1);
		return d2-d1+det*2;
	} else {
		ll det=len;
		if (b < c) {
			ll d0 = c-b;
			if (d-c+c-a >= det) {
				return det+d0;
			} else {
				det -= (d-a);
				return d0+d-a+det*2;
			}
		} else {
			if (det<=b-c) return 0;
			if (det <= d-a) {
				return det-(b-c);
			} else {
				det -= d-a;
				return d-b+c-a+det*2;
			}
		}
	}
	return ans;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld", &n, &k);
		scanf("%lld%lld", &l1, &r1);
		scanf("%lld%lld", &l2, &r2);
		ll len = max(r2,r1)-min(l1,l2);
		ll cur = min(r2,r1)-max(l1,l2);
		cur = max(cur, 0LL);
		ll cost = min(r2,r1)-max(l1,l2);
		if (cost < 0) {
			cost = -cost;
		} else {
			cost = 0;
		}
		ll ans = 0LL;
		k -= cur*n;
		if (k <= 0) {
			cout<<0<<endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (k <= 0) break;
			if (i==1) {
				ll det = min(k, len-cur);
				ans += cost + det;
				k -= det;
			} else {
				ll det = min(k, len-cur);
				if (det*2 < cost+det) {
					ans += det*2;
					k -= det;
				} else {
					ans += cost+det;
					k -= det;
				}
			}
		}
		if (k > 0) {
			ans += k*2;
		}
		// ll ans;
		// if (len*n >= k) {
		// 	ll cur = min(r2,r1)-max(l1,l2);
		// 	if (cur*n >= k) {
		// 		cout<<0<<endl;
		// 		continue;
		// 	}
		// 	cur = max(cur, 0LL);
		// 	ll det = k-cur*n;
		// 	ll x = det/(len-cur);
		// 	ll r = det%(len-cur);
		// 	cout<<"x="<<x<<" "<<r<<" "<<len<<endl;
		// 	ans = getres(len)*x + getres(r+cur);
		// } else {
		// 	ll det = k-len*n;
		// 	ans = getres(len)*n + det*2;
		// }
		//cout<<"r2="<<getres(2)<<" "<<"r1="<<getres(1)<<endl;
		printf("%lld\n", ans);
	}
  return 0;
}
