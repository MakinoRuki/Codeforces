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
#define M 25
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, k;
ll dp[N][N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[i][j] = 0LL;
			}
		}
		ll ans=1LL;
		if (k == 1) {
			printf("%lld\n", ans);
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][k-1]=1LL;
			ans= (ans+dp[i][k-1]) %mod;
		}
		for (int i = k-2; i >= 1; --i) {
			int det=k-i;
			if (det%2==0) {
				ll tot=dp[1][i+1];
				for (int j = 2; j <= n; ++j) {
					dp[j][i] = tot;
					ans = (ans + dp[j][i]) % mod;
					tot = (tot + dp[j][i+1]) % mod;
				}
			} else {
				ll tot = dp[n][i+1];
				for (int j = n-1; j >= 1; --j) {
					dp[j][i] = tot;
					ans = (ans + dp[j][i]) % mod;
					tot = (tot + dp[j][i+1]) % mod;
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
