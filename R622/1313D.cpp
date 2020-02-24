#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n, m, k;
ll dp[2][257];
int id[N];
int main() {
	cin>>n>>m>>k;
	vector<pair<pair<int, int>, int>> rks;
	rks.clear();
	memset(id, 0, sizeof(id));
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin>>l>>r;
		// Trick : 取到端点怎么办？左端点-1，然后先出再入。
		l--;
		rks.push_back(make_pair(make_pair(l, 1), i));
		rks.push_back(make_pair(make_pair(r, -1), i));
	}
	sort(rks.begin(), rks.end());
	int now = 0;
	memset(dp, -1, sizeof(dp));
	dp[now][0] = 0;
	int pre = 0;
	int st = 0;
	for (int i = 0; i < rks.size(); ++i) {
		for (int j = 0; j < 256; ++j) {
			if (__builtin_popcount(j) % 2 == 1) {
				if (dp[now][j] >= 0) {
					dp[now][j] += (ll)(rks[i].first.first - pre);
				}
			}
		}
		pre = rks[i].first.first;
		now ^= 1;
		for (int j = 0; j < 256; ++j) {
			dp[now][j] = -1;
		}
		if (rks[i].first.second < 0) {
			int x = id[rks[i].second];
			st ^= (1<<x);
			for (int j = 0; j < 256; ++j) {
				if ((1<<x)&j) continue;
				dp[now][j] = max(dp[now^1][j], dp[now^1][j | (1<<x)]);
			}
		} else {
			int x = 0;
			for (x = 0; x < 8; ++x) {
				if ((1<<x)&st) continue;
				break;
			}
			id[rks[i].second] = x;
			st |= (1<<x);
			for (int j = 0; j <256; ++j) {
				if ((1<<x) & j) dp[now][j] = max(dp[now^1][j], dp[now^1][j ^ (1<<x)]);
				else dp[now][j] = max(dp[now][j], dp[now^1][j]);
			}
		}
	}
	for (int j = 0; j < 256; ++j) {
		if (__builtin_popcount(j) % 2 == 1) {
			if (dp[now][j] >= 0) {
				dp[now][j] += m - pre;
			}
		}
	}
	ll ans=0LL;
	for (int i = 0; i < 256; ++i) {
		ans = max(ans, dp[now][i]);
	}
	cout<<ans<<endl;
	return 0;
}
