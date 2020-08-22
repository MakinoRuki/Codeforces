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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll y, x;
int main() {
	cin>>n>>x>>y;
	vector<pair<ll,int>> vs;
	vs.clear();
	for (int i = 1; i <= n; ++i) {
		ll l, r;
		scanf("%lld%lld", &l, &r);
		vs.push_back(make_pair(l, 1));
		vs.push_back(make_pair(r, -1));
	}
	sort(vs.begin(), vs.end());
	int i = 0;
	ll ans = 0LL;
	ll unused = 0LL;
	ll used = 0LL;
	ll tot = 0LL;
	deque<pair<ll, int>> dq;
	while(i < vs.size()) {
		int j;
		ll cnt1=0;
		ll cnt2=0;
		for (j = i; j < vs.size(); ++j) {
			if (vs[j].first != vs[i].first) {
				break;
			} else {
				if (vs[j].second==1) cnt1++;
				else cnt2++;
			}
		}
		if (tot) {
			ll pre = vs[i-1].first;
			ll cur = vs[i].first;
			ll x2 = (cur-pre)*y;
			ans = (ans + x2%mod*tot%mod) % mod;
		}
		ll req = cnt1;
		while(!dq.empty()) {
			ll pre = dq.front().first;
			ll cur = vs[i].first;
			ll x2 = (cur-pre)*y;
			if (x2>x) {
				dq.pop_front();
			} else {
				break;
			}
		}
		while(req && !dq.empty()) {
			ll pre = dq.back().first;
			ll cur = vs[i].first;
			ll x2 = (cur-pre)*y;
			ll det = min(req, (ll)dq.back().second);
			ans = (ans + x2%mod*det%mod)%mod;
			req -= det;
			tot += det;
			dq.back().second -=det;
			if (dq.back().second == 0) {
				dq.pop_back();
			}
		}
		if (req) {
			ans = (ans + x*req%mod) % mod;
			tot += req;
		}
		if (cnt2) {
			tot -= cnt2;
			dq.push_back(make_pair(vs[i].first, cnt2));
		}
		// tot += cnt1;
		// ll req = tot;
		// if (used) {
		// 	ll pre = vs[i-1].first;
		// 	ll cur = vs[i].first;
		// 	ll x2 = (cur-pre)*y;
		// 	ans = (ans + x2%mod*used % mod) % mod;
		// 	req -= min(req, used);
	 //  }
	 // //  if (unused) {
	 // //  	ll pre = vs[i-1].first;
		// // 	ll cur = vs[i].first;
		// // 	ll x2 = (cur-pre)*y;
		// // 	if (x2 > x) {
		// // 		unused = 0LL;
		// // 	}
		// // }
		// while(!dq.empty()) {
		// 	ll pre = dq.front().first;
		// 	ll cur = vs[i].first;
		// 	ll x2 = (cur-pre)*y;
		// 	if (x2>x) {
		// 		unused -= dq.front().second;
		// 		dq.pop_front();
		// 	} else {
		// 		break;
		// 	}
		// }
		// if (req) {
		// 	// if (unused) {
		// 	// 	ll pre = vs[i-1].first;
		// 	// 	ll cur = vs[i].first;
		// 	// 	ll x2 = (cur-pre)*y;
		// 	// 	ll det = min(unused, req);
		// 	// 	ans = (ans + x2*det%mod)%mod;
		// 	// 	req -= det;
		// 	// 	unused -= det;
		// 	// 	used += det;
		// 	// }
		// 	while(unused && req) {
		// 		ll pre = dq.front().first;
		// 		ll cur = vs[i].first;
		// 		ll x2 = (cur-pre)*y;
		// 		ll det = min((ll)dq.front().second, req);
		// 		ans = (ans + x2*det%mod)%mod;
		// 		req -= det;
		// 		unused -= det;
		// 		used += det;
		// 		dq.front().second -= det;
		// 		if (dq.front().second == 0) {
		// 			dq.pop_front();
		// 		}
		// 	}
		// 	if (req) {
		// 		ans = (ans + x*req%mod)%mod;
		// 		used += req;
		// 	}
		// }
		
		// // if (req) {
		// // 	if (unused) {
		// // 		ll det = min(req, unused);
		// // 		if (x2 < x) {
		// // 			ans = (ans + det*x2%mod)%mod;
		// // 			req -= det;
		// // 			unused -= det;
		// // 			used += det;
		// // 		} else {
		// // 			ans = (ans + det*x%mod) % mod;
		// // 			req -= det;
		// // 			used += det;
		// // 		}
		// // 	}
		// // 	if (req) {
		// // 		ans = (ans + req*x%mod)%mod;
		// // 		used += req;
		// // 	}
		// // }
		// tot -= cnt2;
		// if (cnt2) {
		// 	used -= cnt2;
		// 	unused += cnt2;
		// 	dq.push_back(make_pair(vs[i].first, cnt2));
		// }
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}
