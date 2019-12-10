#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_set>
#define N 100020
using namespace std;
typedef long long ll;
int n,m;
int a[N];
int x[82], s[82];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		cin>>x[i]>>s[i];
	}
	int dp[N];
	memset(dp, 0, sizeof(dp));
  // 对于每个位置，可能有三种线段去cover它。
  // r<i和l<=i&&i<=r用来更新dp；l>i时dp[i]=i，也就是初始化的最大值。
	for (int i = 1; i <= m; ++i) {
		dp[i] = i;
		for (int j = 1; j <= n; ++j) {
			if (x[j]-s[j]<=i && x[j]+s[j]>=i) {
				dp[i] = min(dp[i], dp[max(0, x[j]-s[j]-1)]);
			} else if (x[j]+s[j] < i) {
				dp[i] = min(dp[i], dp[max(0, 2 * x[j]-i-1)] + i - x[j] - s[j]);
			}
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
