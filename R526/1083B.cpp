#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
string s, t;
ll dp[N][2][2];
void update(ll& cur, ll val) {
	cur += val;
	if (cur > k) cur = k;
}
int main() {
	cin>>n>>k;
	cin>>s>>t;
	memset(dp, 0LL, sizeof(dp));
	dp[0][0][0] = 1LL;
	ll ans = 0LL;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='a' && t[i]=='a') {
			update(dp[i+1][0][0], dp[i][0][0]);
			update(dp[i+1][0][1], dp[i][0][1]);
			update(dp[i+1][1][1], dp[i][0][1]);
			update(dp[i+1][1][0], dp[i][1][0]);
			update(dp[i+1][1][1], dp[i][1][1]);
			update(dp[i+1][1][1], dp[i][1][1]);
		} else if (s[i] == 'b' && t[i] == 'b') {
			update(dp[i+1][0][0], dp[i][0][0]);
			update(dp[i+1][0][1], dp[i][0][1]);
			update(dp[i+1][1][1], dp[i][1][0]);
			update(dp[i+1][1][0], dp[i][1][0]);
			update(dp[i+1][1][1], dp[i][1][1]);
			update(dp[i+1][1][1], dp[i][1][1]);
		} else if (s[i]=='a' && t[i]=='b') {
			update(dp[i+1][0][1], dp[i][0][0]);
			update(dp[i+1][1][0], dp[i][0][0]);
			update(dp[i+1][0][1], dp[i][0][1]);
			update(dp[i+1][1][1], dp[i][0][1]);
			update(dp[i+1][1][1], dp[i][1][0]);
			update(dp[i+1][1][0], dp[i][1][0]);
			update(dp[i+1][1][1], dp[i][1][1]);
			update(dp[i+1][1][1], dp[i][1][1]);
		} else {
			update(dp[i+1][0][1], dp[i][0][1]);
			update(dp[i+1][1][0], dp[i][1][0]);
			update(dp[i+1][1][1], dp[i][1][1]);
			update(dp[i+1][1][1], dp[i][1][1]);
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j1 = 0; j1 < 2; ++j1) {
	// 		for (int j2 = 0; j2 < 2; ++j2) {
	// 			cout<<i<<" "<<j1<<" "<<j2<<" "<<dp[i][j1][j2]<<endl;
	// 		}
	// 	}
	// }
	for (int i = 1; i <= n; ++i) {
		ll res = 0LL;
		for (int j1=0; j1<2; ++j1) {
			for (int j2 = 0; j2 < 2; ++j2) {
				res += dp[i][j1][j2];
				if (res>k) res=k;
			}
		}
		ans += res;
	}
	printf("%lld\n", ans);
	return 0;
}
