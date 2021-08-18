#pragma GCC optimize(2)
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
#define M 22
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<int> edges[N];
int cnt[N][N];
ll dp[N][N];
void dfs(int u, int p) {
	cnt[u][0]++;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u);
		for (int d = 1; d <= n; ++d) {
			cnt[u][d] += cnt[v][d-1];
		}
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		ll ans = 0LL;
		if (k == 2) {
			ans = (ll)n*(ll)(n-1)/2;
			ans %= mod;
			printf("%lld\n", ans);
			continue;
		}
		for (int r = 1; r <= n; ++r) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					cnt[i][j] = 0;
				}
			}
			int sz = (int)edges[r].size();
			for (int i = 0; i <= n; ++i) {
				dp[i][0] = 1;
				for (int j = 1; j <= n; ++j) {
					dp[i][j] = 0;
				}
			}
			for (int i = 0; i < edges[r].size(); ++i) {
				int u = edges[r][i];
				dfs(u, r);
			//	if (r == 2) cout<<"u="<<u<<endl;
				for (int d = 0; d <= n; ++d) {
					for (int j = n; j >= 0; --j) {
						if (j + 1 <= n) {
				//			if (r == 2 && d == 0) cout<<j+1<<" "<<dp[d][j+1]<<endl;
							dp[d][j+1] = (dp[d][j+1] + dp[d][j]*(ll)cnt[u][d]%mod) % mod;
					//		if (r == 2 && d == 0) cout<<j+1<<" "<<dp[d][j+1]<<endl;
						}
					}
				}
			}
		//	cout<<"r="<<r<<endl;
			for (int d = 0; d <= n; ++d) {
			//	cout<<d<<" "<<dp[d][k]<<endl;
				ans = (ans + dp[d][k]) % mod;
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
