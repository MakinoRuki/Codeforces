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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string a, b;
int dp[N][N];
int main() {
	cin>>n>>m;
	cin>>a>>b;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j]=-inf;
		}
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int maxv=-inf;
			if (dp[i-1][j]>maxv) {
				maxv=dp[i-1][j];
			}
			if (dp[i][j-1]>maxv) {
				maxv=dp[i][j-1];
			}
			if (dp[i-1][j-1] > -inf && a[i-1]==b[j-1]) {
				maxv=max(maxv, dp[i-1][j-1]+4);
			}
			if (a[i-1]==b[j-1]) {
				maxv=max(maxv, 4+i+j);
			}
			dp[i][j]=max(dp[i][j], maxv);
		//	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			if (dp[i][j]>-inf) ans = max(ans, dp[i][j]-i-j-2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
