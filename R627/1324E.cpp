#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,h,l,r;
int a[N];
int dp[N][N];
int main() {
	cin>>n>>h>>l>>r;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < h; ++j) {
			if (dp[i][j] < 0) continue;
			int c1 = (j+a[i])%h;
			dp[i+1][c1] = max(dp[i+1][c1], dp[i][j]+(c1>=l&&c1<=r));
			c1 = (j+a[i]-1+h)%h;
			dp[i+1][c1] = max(dp[i+1][c1], dp[i][j]+(c1>=l&&c1<=r));
		}
	}
	int ans=0;
	for (int i = 0; i < h; ++i) {
		ans = max(ans, dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}
