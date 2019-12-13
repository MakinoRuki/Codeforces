#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#define N 200020
using namespace std;
typedef long long ll;
int k[3];
int a[3][N];
bool has[3][N];
int dp[N][3];
int main() {
	int n=0;
	for (int i = 0; i < 3; ++i) {
		cin>>k[i];
		n += k[i];
	}
	memset(has, false, sizeof(has));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < k[i]; ++j) {
			cin>>a[i][j];
			has[i][a[i][j]] = true;
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = (i == 0 ? 0 : INT_MAX);
		}
	}
	// dp[i,j]=前i个问题放在前j个人那里最少代价。 如果本来不在，则必然+1。
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int t = j; t >= 0; --t) {
				dp[i][j] = min(dp[i][j], dp[i-1][t] + !has[j][i]);
			}
		}
	}
	int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
	cout<<ans<<endl;
	return 0;
}
