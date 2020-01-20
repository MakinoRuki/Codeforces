#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll x0, y0, ax, ay, bx, by;
ll xs,ys;
ll t;
int main() {
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	vector<pair<ll, ll>> pts;
	pts.clear();
	ll xx = x0;
	ll yy = y0;
	while(true) {
		pts.push_back(make_pair(xx, yy));
		ll tx = ax * xx + bx;
		ll ty = ay * yy + by;
		if (tx < 0 || ty < 0 || (tx-t > xs && ty-t > ys)) {
			break;
		}
		xx = tx;
		yy =ty;
	}
	sort(pts.begin(), pts.end());
// 	if (xs == 1121164464365490LL) {
// 	for (int i = 0; i < pts.size(); ++i) {
// 		cout<<i<<" "<<pts[i].first<<" "<<pts[i].second<<endl;
// 	}
// }
	ll ans = 0;
	for (int i = 0; i < pts.size(); ++i) {
		ll tmp = abs(pts[i].first-xs) + abs(pts[i].second-ys);
		//cout<<i<<" "<<pts[i].first<<" "<<pts[i].second<<" "<<xs<<" "<<ys<<endl;
		ll tmp1 = tmp;
		ll tmp2 = tmp;
		int cnt1 = 1;
		int cnt2= 1;
		if (tmp1>=0 && tmp1<=t) ans = max(ans, 1LL);
		if (tmp2>= 0 && tmp2<=t) ans = max(ans, 1LL);
		for (int j = i + 1; j < pts.size(); ++j) {
			tmp1 += abs(pts[j].first-pts[j-1].first) + abs(pts[j].second-pts[j-1].second);
			if (tmp1 >=0 && tmp1 <= t) {
				if (xs == 1121164464365490LL) {
					cout<<"1:"<<j<<" "<<i<<" "<<tmp1<<endl;
				}
				ans = max(ans, (ll)j-i+1);
			}
			if (tmp1<0 || tmp1>t) break;
			for (int k = i-1; k >= 0; --k) {
				ll ntmp = tmp1 + abs(pts[j].first-pts[k].first) + abs(pts[j].second-pts[k].second);
				if (ntmp>=0 && ntmp <= t) {
					if (xs == 1121164464365490LL) {
						cout<<"2:"<<k<<" "<<j<<" "<<i<<" "<<ntmp<<endl;
					}
					ans = max(ans, (ll)j-k+1);
				}
				if (ntmp<0 || ntmp>t) break;
			}
		}
		for (int j = i-1; j >= 0; --j) {
			tmp2 += abs(pts[j].first-pts[j+1].first) + abs(pts[j].second-pts[j+1].second);
			if (tmp2>=0&&tmp2<=t) {
				if (xs == 1121164464365490LL) {
					cout<<"3:"<<j<<" "<<i<<" "<<tmp2<<endl;
				}
				ans = max(ans, (ll)i-j+1);
			}
			if (tmp2<0||tmp2>t) break;
			for (int k = i+1; k < pts.size(); ++k) {
				ll ntmp = tmp2 + abs(pts[j].first-pts[k].first) + abs(pts[j].second-pts[k].second);
				if (ntmp>=0&&ntmp <= t) {
					if (xs == 1121164464365490LL) {
						cout<<"4:"<<k<<" "<<j<<" "<<i<<" "<<ntmp<<endl;
					}
					ans = max(ans, (ll)k-j+1);
				}
				if (ntmp<0||ntmp>t) break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
