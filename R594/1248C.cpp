#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
ll dp[N][2][3];
int main() {
	cin>>n>>m;
	memset(dp, 0, sizeof(dp));
	dp[1][0][1] = 1LL;
	for (int i = 1; i < max(n, m); ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 1; k <= 2; ++k) {
				if (k == 1) {
					dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % mod;
					dp[i+1][!j][k] = (dp[i+1][!j][k] + dp[i][j][k]) % mod;
				} else {
					dp[i+1][!j][1] = (dp[i+1][!j][1] + dp[i][j][k]) % mod;
				}
			}
		}
	}
	ll ans = 0LL;
	for (int i = 0; i < 2; ++i) {
		for (int j =1; j <= 2; ++j) {
			ans = (ans + dp[n][i][j]) % mod;
			ans = (ans + dp[m][i][j]) % mod;
		}
	}
	// for (int i = 0; i < 2; ++i) {
	// 	for (int j =1 ; j <= 2; ++j) {
	// 		cout<<i<<" "<<j<<" "<<dp[n][i][j]<<endl;
	// 	}
	// }
	// for (int i = 0; i < 2; ++i) {
	// 	for (int j =1 ; j <= 2; ++j) {
	// 		cout<<i<<" "<<j<<" "<<dp[m][i][j]<<endl;
	// 	}
	// }
	ans = (ans - 1 + mod) % mod;
	ans = ans * 2LL % mod;
	cout<<ans<<endl;
	return 0;
}
