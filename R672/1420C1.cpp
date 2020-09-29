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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
int t;
int a[N];
int cnt[40];
ll dp[N][3];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = -(1LL<<60);
			}
		}
		dp[0][1]=0;
		for (int i = 0; i < n; ++i) {
			if (dp[i][1] >= 0) {
				dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
				dp[i+1][0] = max(dp[i+1][0], dp[i][1]+(ll)a[i+1]);
			}
			if (dp[i][0]>=0) {
				dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
				dp[i+1][1] = max(dp[i+1][1], dp[i][0]-(ll)a[i+1]);
			}
		}
		ll ans=max(dp[n][0],dp[n][1]);
		printf("%lld\n", ans);
	}
	return 0;
}
