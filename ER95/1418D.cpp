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
#define N 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
int p[N];
int main() {
	cin>>n>>q;
	map<int,int> ds;
	ll tot=0;
	set<int> ps;
	ds.clear();
	ps.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		ps.insert(p[i]);
	}
	sort(p+1, p+n+1);
	for (int i = 2; i <= n; ++i) {
		ds[p[i]-p[i-1]]++;
		tot += (ll)(p[i]-p[i-1]);
	}
	if (ds.empty()) {
		cout<<0<<endl;
	} else {
		ll maxv=(*ds.rbegin()).first;
		printf("%lld\n", tot-maxv);
	}
	for (int i = 1; i <= q; ++i) {
		int t,x;
		scanf("%d%d", &t, &x);
		if (t==0) {
			auto itr = ps.lower_bound(x);
			auto itr2=itr;
			auto itr3=itr;
			if (itr!=ps.begin()) {
				itr2--;
				int det=x-(*itr2);
				ds[det]--;
				tot -= det;
				if (ds[det]==0) {
					ds.erase(det);
				}
			}
			itr3++;
			if (itr3!=ps.end()) {
				int det=(*itr3)-x;
				ds[det]--;
				if (ds[det]==0) {
					ds.erase(det);
				}
				tot -= det;
			}
			if (itr!=ps.begin() && itr3!=ps.end()) {
				int det=(*itr3)-(*itr2);
				ds[det]++;
				tot += det;
			}
			ps.erase(x);
		} else {
			if (ps.empty()) {
				ps.insert(x);
			} else {
				auto itr=ps.upper_bound(x);
				if (itr==ps.begin()) {
					int det=(*itr)-x;
					ds[det]++;
					tot += det;
				} else {
					if (itr==ps.end()) {
						auto itr2=itr;
						itr2--;
						int det=x-(*itr2);
						ds[det]++;
						tot += det;
					} else {
						auto itr2=itr;
						itr2--;
						int det=(*itr)-(*itr2);
					//	cout<<"det="<<det<<" "<<tot<<endl;
						ds[det]--;
						if (ds[det]==0) {
							ds.erase(det);
						}
						tot -= det;
						ds[x-(*itr2)]++;
						tot += (x-(*itr2));
						ds[(*itr)-x]++;
						tot += (*itr)-x;
					}
				}
				ps.insert(x);
			}
		}
		if (ds.empty()) {
			cout<<0<<endl;
		} else {
			ll maxv=(*ds.rbegin()).first;
			printf("%lld\n", tot-maxv);
		}
	}
	return 0;
}
