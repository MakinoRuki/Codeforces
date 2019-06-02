#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
#define N 300010
typedef long long ll;
int n;
vector<pii> s;
vector<int> t;
int main() {
	cin>>n;
	s.clear();
	t.clear();
	int x;
	for (int i = 0; i < n; ++i) {
		cin>>x;
		s.push_back({x, i});
	}
	for (int i = 0; i < n; ++i) {
		cin>>x;
		t.push_back(x);
	}
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	vector<pair<int, int> > diffs;
	diffs.clear();
	vector<pair<pair<int, int>, int> > ans;
	ans.clear();
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		int diff = t[i]-s[i].first;
		if (diff > 0) {
			diffs.push_back({diff, s[i].second});
		}
		while(diff < 0) {
			if (diffs.size() == 0) {
				ok = false;
				break;
			}
			int det = min(diffs.back().first, -diff);
			diff += det;
			diffs.back().first -= det;
			ans.push_back({{diffs.back().second, s[i].second}, det});
			if (diffs.back().first == 0) {
				diffs.pop_back();
			}
		}
	}
	if (diffs.size()) {
		ok = false;
	}
	if (!ok) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}
