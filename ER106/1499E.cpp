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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 25
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll dp[N][N][2];
int main() {
	string x,y;
	cin>>x>>y;
	n = x.size();
	m = y.size();
	memset(dp, 0LL, sizeof(dp));
	dp[n][m-1][1] = 1LL;
	for (int i = m-2; i >= 0; --i) {
		dp[n][i][1] = 1LL;
		if (y[i] != y[i+1]) {
			dp[n][i][1] = (dp[n][i][1] + dp[n][i+1][1]) % mod2;
		}
	}
	dp[n-1][m][0] = 1LL;
	for (int i = n-2; i >= 0; --i) {
		dp[i][m][0] = 1LL;
		if (x[i] != x[i+1]) {
			dp[i][m][0]= (dp[i][m][0] + dp[i+1][m][0]) % mod2;
		}
	}
	ll ans = 0LL;
	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (i+1<n && x[i] != x[i+1]) {
				dp[i][j][0] = (dp[i][j][0] + dp[i+1][j][0]) % mod2;
			}
			if (j<m && x[i] != y[j]) {
				dp[i][j][0] = (dp[i][j][0] + dp[i+1][j][1]) % mod2;
				if (i+1<n) dp[i][j][0] = (dp[i][j][0] + dp[n][j][1]) % mod2;
			}
		//	if (i==3 && j==4) cout<<"x="<<dp[i][j][1]<<endl;
			if (j+1<m && y[j] != y[j+1]) {
				dp[i][j][1] = (dp[i][j][1] + dp[i][j+1][1]) % mod2;
			}
		//	if (i==3 && j==4) cout<<"w="<<dp[i][j][1]<<endl;
			if (i<n && y[j] != x[i]) {
				dp[i][j][1] = (dp[i][j][1] + dp[i][j+1][0]) % mod2;
				if (j+1<m) dp[i][j][1] = (dp[i][j][1] + dp[i][m][0]) % mod2;
			}
		//	if (i==3 && j==4) cout<<"y="<<dp[i][j][1]<<endl;
			ans = (ans + dp[i][j][0]) % mod2;
			ans = (ans + dp[i][j][1]) % mod2;
		//	cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
		//	dp[i][j][0] = (dp[i][j][0] + 1LL) % mod2;
		//	dp[i][j][1] = (dp[i][j][1] + 1LL) % mod2;
		}
	}
	printf("%lld\n", ans);
  return 0;
}
