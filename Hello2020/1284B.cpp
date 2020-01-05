#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 52
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int n;
vector<vector<int>> s;
map<int, int> cnt;
int main() {
	cin>>n;
	s.clear();
	for (int i = 0; i < n; ++i) {
		int l;
		cin>>l;
		vector<int> tmp;
		tmp.clear();
		for (int j = 1; j <= l; ++j) {
			int x;
			cin>>x;
			tmp.push_back(x);
		}
		s.push_back(tmp);
	}
	int has=0;
	cnt.clear();
	vector<int> ids;
	ids.clear();
	for (int i = 0; i < n; ++i) {
		int j;
		int minv = s[i][0];
		int maxv = s[i][0];
		for (j = 1; j < s[i].size(); ++j) {
			if (s[i][j] > minv) {
				break;
			} else {
				minv = min(minv, s[i][j]);
			}
			maxv = max(maxv, s[i][j]);
		}
		if (j < s[i].size()) {
			has++;
		} else {
			cnt[maxv]++;
			ids.push_back(i);
		}
	}
	//cout<<has<<endl;
	//ll ans = 2LL * (ll)n * (ll)has - (ll)has*(ll)(has+1)/2LL;
	ll nhas = ids.size();
	ll ans = ((ll)n*(ll)(n-1)/2 - nhas*(nhas-1)/2) * 2LL + (ll)has;
	//cout<<has<<" "<<ans<<endl;
	for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
		if (itr == cnt.begin()) continue;
		auto itr2 = itr;
		itr2--;
		itr->second += itr2->second;
	}
	for (int i = 0; i < ids.size(); ++i) {
		int minv = s[ids[i]][0];
		for (int j = 1; j < s[ids[i]].size(); ++j) {
			minv = min(minv, s[ids[i]][j]);
		}
		auto itr = cnt.upper_bound(minv);
	//	cout<<i<<" "<<ids[i]<<" "<<itr->first<<" "<<itr->second<<endl;
		if (itr == cnt.begin()) {
			ans += (ll)(n-has);
		} else {
			itr--;
		//	cout<<itr->first<<" "<<itr->second<<endl;
			ans += (ll)(ids.size()-itr->second);
		}
	}
	cout<<ans<<endl;
	return 0;
}
