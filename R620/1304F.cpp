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
#define N 52
#define M 40005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int n,m,k;
int mat[N][M];
int sum[N][M];
ll dp[N][M];
int main() {
	cin>>n>>m>>k;
	memset(sum, 0, sizeof(sum));
	memset(mat, 0, sizeof(mat));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin>>mat[i][j];
		}
		for (int j = 1; j <= m+k-1; ++j) {
			sum[i][j] = sum[i][j-1] + mat[i][j];
		}
	}
	memset(dp, 0, sizeof(dp));
	for (int j = 1; j <= m; ++j) {
		dp[2][j] = sum[1][j+k-1]-sum[1][j-1]+sum[2][j+k-1]-sum[2][j-1];
		//cout<<j<<" "<<dp[2][j]<<endl;
	}
	for (int i = 3; i <= n+1; ++i) {
		deque<int> dq;
		ll lmx = 0;
		for (int j = 1; j <= m; ++j) {
			while(!dq.empty() && dq.front() <= j-k) {
				lmx = max(lmx, dp[i-1][dq.front()]);
				dq.pop_front();
			}
			ll curv = dp[i-1][j]-(ll)(sum[i-1][j+k-1]-sum[i-1][j-1]);
			while(!dq.empty()) {
				int idx = dq.back();
				ll prev = dp[i-1][idx] - (ll)(sum[i-1][idx+k-1]-sum[i-1][j-1]);
				if (curv >= prev) {
					dq.pop_back();
				} else {
					break;
				}
			}
			dq.push_back(j);
			int idx = dq.front();
			ll det = sum[i-1][j+k-1]-sum[i-1][j-1]+sum[i][j+k-1]-sum[i][j-1];
			dp[i][j] = max(dp[i][j], lmx+det);
			dp[i][j] = max(dp[i][j], det+dp[i-1][idx]-(ll)(sum[i-1][idx+k-1]-sum[i-1][j-1]));
		}
		while(!dq.empty()) {
			dq.pop_back();
		}
		ll rmx = 0;
		for (int j = m; j>= 1; --j) {
			while(!dq.empty() && dq.front() >= j+k) {
				rmx = max(rmx, dp[i-1][dq.front()]);
				dq.pop_front();
			}
			ll curv = dp[i-1][j]-(ll)(sum[i-1][j+k-1]-sum[i-1][j-1]);
			while(!dq.empty()) {
				int idx = dq.back();
				ll prev = dp[i-1][idx]-(ll)(sum[i-1][j+k-1]-sum[i-1][idx-1]);
				if (curv >= prev) {
					dq.pop_back();
				} else {
					break;
				}
			}
			dq.push_back(j);
			int idx = dq.front();
			ll det = sum[i-1][j+k-1]-sum[i-1][j-1]+sum[i][j+k-1]-sum[i][j-1];
			dp[i][j] = max(dp[i][j], rmx+det);
			dp[i][j] = max(dp[i][j], det+dp[i-1][idx]-(ll)(sum[i-1][j+k-1]-sum[i-1][idx-1]));
		}
		// for (int j = 1; j <= m; ++j) {
		// 	cout<<"**"<<j<<" "<<dp[3][j]<<endl;
		// }
	}
	ll ans=0;
	for (int j = 1; j <= m; ++j) {
		ans = max(ans, dp[n+1][j]);
	}
	cout<<ans<<endl;
	return 0;
}
