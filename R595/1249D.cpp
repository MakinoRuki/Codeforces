#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int n,k;
vector<pair<int, pair<int,int>>> rk;
int rg[N];
int main() {
	cin>>n>>k;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin>>l>>r;
		rk.push_back(make_pair(l, make_pair(1, i)));
		rk.push_back(make_pair(r+1, make_pair(-1, i)));
		rg[i] = r+1;
	}
	sort(rk.begin(), rk.end());
	vector<int> ans;
	set<pair<int, int>> ss;
	int i = 0;
	while(i < rk.size()) {
		int j;
		for (j = i; j < rk.size(); ++j) {
			if (rk[j].first != rk[i].first) break;
			if (rk[j].second.first < 0) {
				if (ss.find(make_pair(rk[j].first, rk[j].second.second)) != ss.end()) {
					ss.erase(make_pair(rk[j].first, rk[j].second.second));
				}
			} else {
				ss.insert(make_pair(rg[rk[j].second.second], rk[j].second.second));
			}
		}
		i = j;
		while (ss.size() > k) {
			auto pr = *ss.rbegin();
			ans.push_back(pr.second);
			ss.erase(pr);
		}
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i];
		if (i < ans.size()-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
