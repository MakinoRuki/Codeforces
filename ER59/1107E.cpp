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
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
int a[N];
ll dp[N][N][N];
ll dfs(int l, int r, int p) {
	if (l>r) return 0;
	if (l==r) return dp[l][r][p]=a[p];
	if (dp[l][r][p]>=0) {
		return dp[l][r][p];
	}
	dp[l][r][p]=dfs(l+1, r, 1)+a[p];
	for (int i = l+1; i <= r; ++i) {
		if (s[i-1]==s[l-1]) {
			dp[l][r][p] = max(dp[l][r][p], dfs(l+1,i-1,1)+dfs(i,r,p+1));
		}
	}
	return dp[l][r][p];
}
int main() {
	cin>>n>>s;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1, n, 1);
	printf("%lld\n", dp[1][n][1]);
	return 0;
}
