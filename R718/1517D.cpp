#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 502
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t, n, m, k;
int a[N][N];
int b[N][N];
int dp[22][N][N];
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[0][i][j] = 0;
		}
	}
	if (k%2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("%d", -1);
				if (j < m) cout<<" ";
				else cout<<endl;
			}
		}
		return 0;
	}
	for (int s = 1; s <= k/2; ++s) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[s][i][j] = inf;
				if (i-1>=1) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i-1][j]+b[i-1][j]);
				if (j-1>=1) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i][j-1]+a[i][j-1]);
				if (i+1<=n) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i+1][j]+b[i][j]);
				if (j+1<=m) dp[s][i][j] = min(dp[s][i][j], dp[s-1][i][j+1]+a[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d", 2*dp[k/2][i][j]);
			if (j < m) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

/*myturn.ca.gov*/
