#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000010
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[2][25][3];
int n;
int main() {
	cin>>n;
	memset(dp, 0, sizeof(dp));
	int bits = 0;
	while((1<<bits) <= n) {
		bits++;
	}
	bits--;
	dp[1][bits][0] = 1;
	if ((1<<(bits-1)) * 3 <= n) {
		dp[1][bits-1][1] = 1;
	}
	for (int i = 1; i < n; ++i) {
		int now = (i+1)&1;
		memset(dp[now], 0, sizeof(dp[now]));
		for (int j = 0; j <= bits; ++j) {
			for (int k = 0; k <= 1; ++k) {
				int n2 = (1<<j);
				int n3 = (k == 0 ? 1 : 3);
				int tmp = n2 * n3;
				dp[now][j][k] = (dp[now][j][k] + dp[i&1][j][k] * (n / tmp - i) % mod) % mod;
				if (j) {
					ll cnt = n / (n2 / 2 * n3) - n / tmp;
					dp[now][j-1][k] = (dp[now][j-1][k] + dp[i&1][j][k] * cnt % mod) % mod;
				}
				if (k) {
					ll cnt = n / (n2 * (n3 / 3)) - n/ tmp;
					dp[now][j][k-1] = (dp[now][j][k-1] + dp[i&1][j][k] * cnt % mod) % mod;
				}
			}
		}
	}
	cout<<dp[n&1][0][0]<<endl;
	return 0;
}
