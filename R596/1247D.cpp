#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
int n,k;
int a[N];
map<vector<pair<int,int>>, int> cnt;
int main() {
	cin>>n>>k;
	cnt.clear();
	ll ones = 0;
	ll cpw = 0;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		if (a[i] == 1) {
			ones++;
			continue;
		}
		vector<pair<int, int>> tmp;
		tmp.clear();
		int x = a[i];
		for (int j =2; j * j <= x; ++j) {
			if (x % j == 0) {
				int num=0;
				while(x % j == 0) {
					x /= j;
					num++;
				}
				if (num% k)tmp.push_back(make_pair(j, num%k));
			}
		}
		if (x > 1) {
			tmp.push_back(make_pair(x, 1));
		}
		if (tmp.size()) {
			sort(tmp.begin(), tmp.end());
			cnt[tmp]++;
		} else {
			cpw++;
		}
	}
	ll ans = 0;
	if (ones >= 2) {
		ans += ones*(ones-1)/2;
	}
	if (cpw >= 2) {
		ans += cpw * (cpw-1)/2;
	}
	ans += ones * cpw;
	ll res1 = 0;
	ll res2=0;
	for (auto v : cnt) {
		auto vs = v.first;
		// cout<<"vs="<<endl;
		// for (int i = 0; i < vs.size(); ++i) {
		// 	cout<<i<<" "<<vs[i].first<<" "<<vs[i].second<<endl;
		// }
		vector<pair<int,int>> vt;
		vt.clear();
		for (int i = 0; i < vs.size(); ++i) {
			vt.push_back(make_pair(vs[i].first, k-vs[i].second));
		}
		sort(vt.begin(), vt.end());
		// cout<<"vt="<<endl;
		// for (int i = 0; i < vt.size(); ++i) {
		// 	cout<<i<<" "<<vt[i].first<<" "<<vt[i].second<<endl;
		// }
		bool ok = false;
		for (int i = 0; i < vt.size(); ++i) {
			if (vt[i] != vs[i]) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			if (v.second > 1) {
				res1 += (ll)v.second*(ll)(v.second-1)/2LL;
			}
		} else {
			res2 += (ll)v.second * (ll)cnt[vt];
		}
	}
	res2 /= 2;
	ans += res1+res2;
	cout<<ans<<endl;
	return 0;
}
