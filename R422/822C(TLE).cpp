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
int n, x;
vector<pair<int,int>> mp[N];
vector<pair<pair<int,int>, int>> vs;
int main() {
	cin>>n>>x;
	vs.clear();
	vector<pair<int,int>> rk;
	rk.clear();
	for (int i = 1; i <= 200000; ++i) {
		mp[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		vs.push_back(make_pair(make_pair(l,r), c));
	//	cout<<"i="<<i<<" "<<l<<" "<<r<<endl;
	}
	for (int i = 0; i < n; ++i) {
		rk.push_back(make_pair(vs[i].first.first, i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		int id=rk[i].second;
		int len=vs[id].first.second-vs[id].first.first+1;
		mp[len].push_back(make_pair(vs[id].first.first, vs[id].second));
	}
//	cout<<"??"<<endl;
	ll ans=3000000000LL;
	for (int i = 1; i <= x; ++i) {
	//	cout<<"i1="<<i<<endl;
		auto& vv=mp[i];
	//	cout<<"i2="<<i<<endl;
		if (vv.empty()) continue;
		int sz=(int)vv.size();
	//	cout<<"i="<<i<<" "<<sz<<endl;
		
		for (int j = sz-1; j >= 0; --j) {
		//	cout<<i<<" "<<j<<endl;
			if (j==sz-1) {
				continue;
			}
			mp[i][j].second=min(mp[i][j].second, mp[i][j+1].second);
		}
	}
	for (int i = 0; i < n; ++i) {
		int x1=vs[i].first.second-vs[i].first.first+1;
		int x2=x-x1;
		if (x2 >= 0 && x2 <=x && !mp[x2].empty()) {
			auto vv=mp[x2];
		//	int l = 0, r = (int)vv.size();
		//	cout<<"i="<<i<<" "<<l<<" "<<r<<endl;
		//	cout<<"i="<<i<<" "<<x1<<" "<<x2<<" "<<l<<" "<<r<<endl;
			// while(l<r) {
			// 	int mid=(l+r)/2;
			// //	if (i==0) cout<<"mid="<<mid<<" "<<vv[mid].first<<" "<<vv[mid].second<<endl;
			// 	if (vv[mid].first>vs[i].first.second) {
			// 		r=mid;
			// 	} else {
			// 		l=mid+1;
			// 	}
			// }
			int id=upper_bound(vv.begin(), vv.end(), make_pair(vs[i].first.second, inf+1))-vv.begin();
		//	cout<<"i2="<<i<<" "<<r<<endl;
			if (id<(int)vv.size()) {
				ll cur=vs[i].second + vv[id].second;
				ans=min(ans, cur);
			}
		}
	}
	if (ans>=3000000000LL) {
		cout<<-1<<endl;
	} else {
		cout<<ans<<endl;
	}
	return 0;
}
