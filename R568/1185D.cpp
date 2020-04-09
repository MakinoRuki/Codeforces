#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int a[N];
int main() {
	cin>>n;
	vector<pair<int, int>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		rk.push_back(make_pair(a[i], i));
	}
	sort(rk.begin(), rk.end());
	map<int, int> cnt;
	cnt.clear();
	if (n == 2) {
		cout<<1<<endl;
	} else {
		for (int i = 1; i < n; ++i) {
			cnt[rk[i].first-rk[i-1].first]++;
		}
		int id = -1;
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				cnt[rk[1].first-rk[0].first]--;
				if (cnt[rk[1].first-rk[0].first] == 0) cnt.erase(rk[1].first-rk[0].first);
				if (cnt.size()==1) id = rk[0].second;
				cnt[rk[1].first-rk[0].first]++;
			} else if (i == n-1) {
				cnt[rk[n-1].first-rk[n-2].first]--;
				if (cnt[rk[n-1].first-rk[n-2].first] == 0) cnt.erase(rk[n-1].first-rk[n-2].first);
				if (cnt.size()==1) id = rk[n-1].second;
				cnt[rk[n-1].first-rk[n-2].first]++;
			} else {
				int det1 = rk[i].first-rk[i-1].first;
				int det2 = rk[i+1].first-rk[i].first;
				int det0 = rk[i+1].first-rk[i-1].first;
				cnt[det1]--;
			//	if (i == 4) cout<<det1<<" "<<cnt[det1]<<endl;
				if (cnt[det1]==0) cnt.erase(det1);
				cnt[det2]--;
			//	if (i == 4) cout<<det2<<" "<<cnt[det2]<<endl;
				if (cnt[det2]==0) cnt.erase(det2);
				cnt[det0]++;
			//	if (i == 4) cout<<det0<<" "<<cnt[det0]<<endl;
				// if (i==4) {
				// 	cout<<"size="<<cnt.size()<<endl;
				// 	for (auto itr : cnt) {
				// 		cout<<itr.first<<" "<<itr.second<<endl;
				// 	}
				// }
				if (cnt.size() == 1) id = rk[i].second;
				cnt[det1]++;
				cnt[det2]++;
				cnt[det0]--;
				if (cnt[det0] == 0) cnt.erase(det0);
			}
		}
		cout<<id<<endl;
	}
	return 0;
}
