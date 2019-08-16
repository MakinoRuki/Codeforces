// 按照b的正负划分，正的就贪心去选。负的按照a2-b1<=a1-b2排序之后背包dp。
// 排序依据是如果1在2前更优，则r+b1-a2>=r+b2-a1。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, r;
vector<pair<int, int> > ab[2];
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return b.first - a.second <= a.first - b.second;
}
int main() {
	cin>>n>>r;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin>>a>>b;
		if (b >= 0) {
			ab[0].push_back(make_pair(a, b));
		} else {
			ab[1].push_back(make_pair(a, b));
		}
	}
	sort(ab[0].begin(), ab[0].end());
	int ans = 0;
	set<pair<int, int> > S;
	S.clear();
	int i = 0;
	while(true) {
		while(i < ab[0].size() && ab[0][i].first <= r) {
			S.insert(make_pair(-ab[0][i].second, i));
			i++;
		}
		if (S.empty()) break;
		auto top = *S.begin();
		ans++;
		r -= top.first;
		S.erase(top);
	}
//	cout<<ans<<endl;
	sort(ab[1].begin(), ab[1].end(), cmp);
	int dp[2][r + 1];
	memset(dp, -1, sizeof(dp));
	int m = ab[1].size();
	dp[0][r] = ans;
	for (int i = 0; i < m; ++i) {
		int now = i & 1;
		memset(dp[now ^ 1], -1, sizeof(dp[now ^ 1]));
		for (int j = 0; j <= r; ++j) {
			if (dp[now][j] >= 0) {
				dp[now ^ 1][j] = max(dp[now ^ 1][j], dp[now][j]);
				int x = ab[1][i].first;
				int y = ab[1][i].second;
				if (j >= x && j + y >= 0) {
					dp[now ^ 1][j + y] = max(dp[now ^ 1][j + y], dp[now][j] + 1);
				}
			}
		}
	}
	for (int i = 0; i <= r; ++i) {
		ans = max(ans, dp[m&1][i]);
	}
	cout<<ans<<endl;
	return 0;
}
