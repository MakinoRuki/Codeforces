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
#define M 20005
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int t;
ll dp[N][2*N][4];
int getadd(int s1, int s2) {
	if (s1==0) {
		if (s2==1 || s2 ==2 || s2==3) return 1;
		return 0;
	} else if (s1==1) {
		if (s2==2) return 2;
		return 0;
	} else if (s1==2) {
		if (s2==1) return 2;
		return 0;
	} else {
		if (s2 == 3) return 0;
		return 1;
	}
}
int main() {
	cin>>n>>k;
	memset(dp, 0LL, sizeof(dp));
	dp[1][1][0] = 1LL;
	dp[1][2][1] = 1LL;
	dp[1][2][2] = 1LL;
	dp[1][1][3] = 1LL;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int s = 0; s < 4; ++s) {
				for (int s2=0; s2<4; ++s2) {
					int add = getadd(s, s2);
					if (j + add <= k) {
						dp[i+1][j+add][s2] = (dp[i+1][j+add][s2]+dp[i][j][s])%mod2;
					}
				}
			}
		}
	}
	ll ans=0LL;
	for (int i = 0; i < 4; ++i) {
		ans = (ans + dp[n][k][i]) % mod2;
	}
	cout<<ans<<endl;
	return 0;
}
