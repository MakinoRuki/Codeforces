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
#define N 100005
using namespace std;
typedef long long ll;
int n, p, k;
int s[N][8];
ll dp[2][1<<7];
int main() {
	cin>>n>>p>>k;
	vector<pair<int, int>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		rk.push_back(make_pair(a, i));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < p; ++j) {
			scanf("%d", &s[i][j]);
		}
	}
	sort(rk.begin(), rk.end());
	reverse(rk.begin(), rk.end());
	memset(dp, -1, sizeof(dp));
	int now = 0;
	dp[now][0] = 0;
	for (int i = 0; i < n; ++i) {
		memset(dp[now^1], -1, sizeof(dp[now^1]));
		int id = rk[i].second;
		for (int j = 0; j < (1<<p); ++j) {
			if (dp[now][j] < 0) continue;
			for (int z = 0; z < p; ++z) {
				if ((1<<z) & j) continue;
				dp[now^1][j | (1<<z)] = max(dp[now^1][j|(1<<z)], dp[now][j] + s[id][z]);
			}
			int det = i - __builtin_popcount(j);
			if (det < k) {
				dp[now^1][j] = max(dp[now^1][j], dp[now][j] + rk[i].first);
			} else {
				dp[now^1][j] = max(dp[now^1][j], dp[now][j]);
			}
		}
		now ^= 1;
	}
	cout<<dp[n&1][(1<<p)-1]<<endl;
	return 0;
}
