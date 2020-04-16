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
#define N 400005
using namespace std;
typedef long long ll;
int t, n, m;
int x;
ll dp[32][32];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>x>>n>>m;
		for (int i = 0; i <= n; ++i) {
			for (int j =0;j <= m; ++j) {
				dp[i][j] = x+1;
			}
		}
		dp[0][0] = x;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (dp[i][j] < x+1) {
					if (i+1<=n) dp[i+1][j] = min(dp[i+1][j], max(0LL, dp[i][j]/2+10));
					if (j+1<=m) dp[i][j+1] = min(dp[i][j+1], max(0LL, dp[i][j]-10));
				}
			}
		}
		bool ok = false;
		for (int i = 0; i <=n; ++i) {
			for (int j = 0; j <= m; ++j) {
				if (dp[i][j] <= 0) ok = true;
			}
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
