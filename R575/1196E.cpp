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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int q, b, w;
int main() {
	cin>>q;
	for (int c = 1; c <= q; ++c) {
		scanf("%d%d", &b, &w);
		vector<pair<int, int>> ans;
		ans.clear();
		if (b > w) {
			int d = b-w;
			if (d > 2 * w + 1) {
				cout<<"NO"<<endl;
				continue;
			}
			for (int i = 1; i <= w; ++i) {
				ans.push_back(make_pair(2, 2*i-1));
				ans.push_back(make_pair(2, 2*i));
			}
			for (int i = 1; i <= min(d, w); ++i) {
				ans.push_back(make_pair(3, 2*i));
			}
			d -= min(d, w);
			for (int i = 1; i <= min(d, w); ++i) {
				ans.push_back(make_pair(1, 2*i));
			}
			d -= min(d, w);
			if (d) {
				ans.push_back(make_pair(2, 2*w+1));
			}
		} else {
			int d = w-b;
			if (d > 2*b+1) {
				cout<<"NO"<<endl;
				continue;
			}
			for (int i =1; i <= b; ++i) {
				ans.push_back(make_pair(3, 2*i-1));
				ans.push_back(make_pair(3, 2*i));
			}
			for (int i = 1; i <= min(d, b); ++i) {
				ans.push_back(make_pair(4, 2*i));
			}
			d -= min(d, b);
			for (int i = 1; i <= min(d, b); ++i) {
				ans.push_back(make_pair(2, 2*i));
			}
			d -= min(d, b);
			if (d) {
				ans.push_back(make_pair(3, 2*b+1));
			}
		}
		cout<<"YES"<<endl;
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}
