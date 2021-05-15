#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n;
vector<pair<int,int>> lr;
int l[N], r[N];
int main() {
	cin>>n;
	lr.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		lr.push_back(make_pair(l[i], i));
	}
	sort(lr.begin(), lr.end());
	for (int i = 1; i < lr.size(); ++i) {
		int id = lr[i-1].second;
		int id2 = lr[i].second;
		if (lr[i].first == lr[i-1].first) {
			if (r[id]<=r[id2]) {
				printf("%d %d\n", id, id2);
				return 0;
			}
			if (r[id2]<=r[id]) {
				printf("%d %d\n", id2, id);
				return 0;
			}
		}
	}
	set<pair<int,int>> ss;
	ss.clear();
	for (int i = 0; i < n; ++i) {
		int id = lr[i].second;
		if (!ss.empty()) {
			auto pr = *ss.rbegin();
			int id2 = pr.second;
			if (pr.first >= r[id]) {
				printf("%d %d\n", id, id2);
				return 0;
			}
		}
		ss.insert(make_pair(r[id], id));
	}
	printf("%d %d\n", -1, -1);
	return 0;
}
