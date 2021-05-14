#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <deque>
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m;
int dp[N];
int ans[N];
int main() {
	cin>>n>>m;
	for (int i = 0; i <= m; ++i) {
		dp[i] = inf;
	}
	dp[0] = 0;
	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
		int t, y;
		ll x;
		scanf("%d%lld%d", &t, &x, &y);
		if (t == 1) {
			ll det = (x + 100000 - 1) / 100000;
			for (int j = 0; j + det <= m; ++j) {
				if (dp[j]+1<=y) {
					dp[j+det] = min(dp[j+det], dp[j]+1);
				}
			}
		} else {
			for (int j = 0; j <= m; ++j) {
				ll v = (ll)ceil((double)j * (double)x / 100000.0);
				if (v <= m && dp[j]+1<=y) {
					dp[v] = min(dp[v], dp[j]+1);
				}
			}
		}
		for (int j = 1; j <= m; ++j) {
			if (dp[j] < inf) {
				if (ans[j]<0) ans[j] = i;
				dp[j] = 0;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d", ans[i]);
		if (i < m) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
