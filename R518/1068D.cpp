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
#include <time.h>
#define eps 1e-7
#define M 205
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
ll dp[2][M][2];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, 0LL, sizeof(dp));
	ll sum[M][2][2];
	memset(sum, 0LL, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		int now = i&1;
		for (int j = 0; j <= 200; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[now][j][k] = 0LL;
			}
		}
		int lb = 1, ub = 200;
		if (a[i] > 0) {
			lb = a[i];
			ub = a[i];
		}
		if (i == 1) {
			for (int j = lb; j <= ub; ++j) {
				dp[now][j][0] = 1LL;
			}
		} else if (i == n) {
			for (int j = lb; j <= ub; ++j) {
				dp[now][j][1] = (dp[now][j][1] + sum[j+1][1][1]) % mod2;
				dp[now][j][1] = (dp[now][j][1] + (dp[now^1][j][0] + dp[now^1][j][1])%mod2) % mod2;
			}
		} else {
			for (int j = lb; j <= ub; ++j) {
				dp[now][j][0] = (dp[now][j][0] + (sum[j-1][0][0]+sum[j-1][0][1])%mod2)%mod2;
				dp[now][j][1] = (dp[now][j][1] + sum[j+1][1][1]) % mod2;
				dp[now][j][1] = (dp[now][j][1] + (dp[now^1][j][0]+dp[now^1][j][1])%mod2)%mod2;
			}
		}
		for (int j = 0; j <= 200; ++j) {
			for (int j1 = 0; j1 < 2; ++j1) {
				for (int j2 = 0; j2 < 2; ++j2) {
					sum[j][j1][j2] = 0LL;
				}
			}
		}
		for (int j = 1; j <= 200; ++j) {
			sum[j][0][0] = (sum[j-1][0][0] + dp[now][j][0]) % mod2;
			sum[j][0][1] = (sum[j-1][0][1] + dp[now][j][1]) % mod2;
		}
		for (int j = 200; j >= 1; --j) {
			sum[j][1][0] = (sum[j+1][1][0] + dp[now][j][0]) % mod2;
			sum[j][1][1] = (sum[j+1][1][1] + dp[now][j][1]) % mod2;
		}
	}
	ll ans = sum[200][0][1];
	printf("%lld\n", ans);
  return 0;
}
