#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n;
int a[N], t[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin>>t[i];
	}
	vector<pair<int, int>> rks;
	rks.clear();
	for (int i = 1; i <= n; ++i) {
		rks.push_back(make_pair(a[i], t[i]));
	}
	sort(rks.begin(), rks.end());
	int cur = rks[0].first;
	ll tot=0LL;
	ll sum = 0LL;
	set<pair<int, int>> ss;
	ss.clear();
	int i = 0;
	while(i < n) {
		while(i < n && rks[i].first == cur) {
			ss.insert(make_pair(rks[i].second, i));
			sum += rks[i].second;
			i++;
		}
		if (ss.empty()) {
			cur = rks[i].first;
			continue;
		}
		sum -= (*ss.rbegin()).first;
		ss.erase(*ss.rbegin());
		tot += sum;
		cur++;
	}
	while(ss.size() > 1) {
		sum -= (*ss.rbegin()).first;
		ss.erase(*ss.rbegin());
		tot += sum;
	}
	cout<<tot<<endl;
	return 0;
}
