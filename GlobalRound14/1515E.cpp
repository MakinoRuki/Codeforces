#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#define N 402
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m, x;
int l, r;
int dp[N][N];
int pw[N], comb[N][N];
int main() {
	cin>>n>>m;
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = (int)((ll)pw[i-1]*2LL%(ll)m);
	}
	memset(comb, 0, sizeof(comb));
	for (int i = 0; i <= n; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%m;
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n+1; ++i) {
		for (int j = i-2; j >= 0; --j) {
			int det = i-j-1;
			for (int k = 0; k <= j; ++k) {
				if (dp[j][k] > 0) {
					dp[i][k+det] = (dp[i][k+det]+(int)((ll)dp[j][k]*(ll)comb[k+det][det]%(ll)m*(ll)pw[det-1]%(ll)m))%m;
				}
			}
		}
	}
	int ans=0;
	for (int i = 0; i <= n; ++i) {
		ans = (ans + dp[n+1][i]) % m;
	}
	cout<<ans<<endl;
	return 0;
}
