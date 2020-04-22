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
#define N 502
using namespace std;
typedef long long ll;
int n;
int c[N];
int dp[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = (i > j ? 0 : 1000000000);
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			if (i==j) dp[i][j] = 1;
			else {
				if (c[i]==c[j]) {
					if (i+1==j) dp[i][j] = 1;
					else dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
				}
				for (int k = i; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = i; j <= n; ++j) {
	// 		cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	// 	}
	// }
	cout<<dp[1][n]<<endl;
	return 0;
}
