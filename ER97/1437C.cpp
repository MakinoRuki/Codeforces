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
#define N 202
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q,n;
int t[N];
int dp[N][2*N];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &t[i]);
		}
		sort(t+1, t+n+1);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= 2*n; ++j) {
				dp[i][j]=inf;
			}
		}
		dp[0][0]=0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= 2* n; ++j) {
				if (dp[i][j]<inf) {
					for (int k = j+1; k <= 2* n; ++k) {
						dp[i+1][k] = min(dp[i+1][k], dp[i][j]+abs(t[i+1]-k));
					}
				}
			}
		}
		int ans=inf;
		for (int i = 1; i <= 2*n; ++i) {
			ans=min(ans, dp[n][i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
