#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int t, n;
int l[N], r[N];
vector<int> edges[N];
ll dp[N][2];
void dfs(int u, int p) {
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
	//	found=true;
		dfs(v, u);
		dp[u][0] += max(dp[v][0]+(ll)abs(l[v]-l[u]), dp[v][1]+(ll)abs(r[v]-l[u]));
		dp[u][1] += max(dp[v][0]+(ll)abs(l[v]-r[u]), dp[v][1]+(ll)abs(r[v]-r[u]));
	}
//	cout<<"u="<<u<<" "<<dp[u][0]<<" "<<dp[u][1]<<endl;
	// if (!found) {
	// 	dp[u][0] = l[u];
	// 	dp[u][1] = r[u];
	// }
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &l[i], &r[i]);
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
	//	cout<<"ddd"<<endl;
	//	memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = 0;
			dp[i][1] = 0;
		}
		dfs(1, 0);
		ll ans = max(dp[1][0], dp[1][1]);
		printf("%lld\n", ans);
	}
	return 0;
}
