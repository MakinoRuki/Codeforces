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
#define N 3002
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
string s;
string t;
int n, m;
ll dp[N][N];
int main() {
	cin>>s>>t;
	n = s.size();
	m = t.size();
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		if (i <= m) {
			if (s[0] == t[i-1]) dp[1][i] = 2LL;
		} else {
			dp[1][i] = 2LL;
		}
	}
	for (int i =1; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j] > 0) {
				char c = s[i];
				if (j-1 >= 1) {
					if (j-1<=m) {
						if (c == t[j-2]) dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
					} else {
						dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
					}
				}
				if (j+i<=n) {
					if (j+i>=1 && j+i<=m) {
						if (c == t[j+i-1]) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
					} else {
						dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
					}
				}
				// if (j-2>=0 && (c == t[j-2])) dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j])%mod;
				// if (j+i-1<=m-1 && (c==t[j+i-1])) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
			}
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <= n; ++j) {
	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	// 	}
	// }
	ll ans = 0LL;
	for (int i = m; i <= n; ++i) {
		ans = (ans + dp[i][1]) % mod;
	}
	cout<<ans<<endl;
	return 0;
}
