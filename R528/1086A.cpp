#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 5005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int xa, ya, xb, yb, xc, yc;
int main() {
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	vector<pair<int,int>> ps = {{xa,ya}, {xb,yb}, {xc,yc}};
	sort(ps.begin(), ps.end());
	vector<pair<int,int>> ans;
	ans.clear();
	for (int x = ps[0].first; x < ps[1].first; ++x) {
		ans.push_back(make_pair(x, ps[0].second));
	}
//	cout<<ans.size()<<endl;
	for (int x = ps[1].first+1; x <= ps[2].first; ++x) {
		ans.push_back(make_pair(x, ps[2].second));
	}
//	cout<<ans.size()<<endl;
	int ymin = ps[0].second;
	int ymax = ps[0].second;
	for (int i = 0; i <= 2; ++i) {
		ymin=min(ymin, ps[i].second);
		ymax=max(ymax, ps[i].second);
	}
	for (int y = ymin; y <= ymax; ++y) {
		ans.push_back(make_pair(ps[1].first, y));
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
