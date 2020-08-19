#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 300005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int w[N];
vector<pair<int,int>> edges[N];
ll dp[N][2];
int idx[N][2];
ll ans;
void dfs1(int u, int p) {
	dp[u][0] = w[u];
	idx[u][0] = u;
	dp[u][1] = w[u];
	idx[u][1] = u;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v==p) continue;
		ll c = edges[u][i].second;
		dfs1(v, u);
		if (dp[v][0]-c>=0) {
			if (dp[v][0]-c+w[u] > dp[u][0]) {
				dp[u][0] = dp[v][0]-c+w[u];
				idx[u][0] = v;
			} else if (dp[v][0]-c+w[u] > dp[u][1]) {
				dp[u][1] = dp[v][0]-c+w[u];
				idx[u][1] = v;
			}
		}
	}
	ans = max(ans, max(dp[u][0], dp[u][1]));
}
void dfs2(int u, int p, ll cv) {
	ans = max(ans, cv+(ll)w[u]);
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v==p) continue;
		ll c = edges[u][i].second;
		if (v == idx[u][0]) {
			ll cur = max(cv+w[u],dp[u][1]);
			dfs2(v, u, cur>c ? cur-c : 0);
		} else {
			ll cur = max(cv+w[u], dp[u][0]);
			dfs2(v, u, cur>c ? cur-c : 0);
		}
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		edges[u].push_back(make_pair(v,c));
		edges[v].push_back(make_pair(u,c));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = -(1LL<<61);
		}
	}
	ans = -(1LL<<61);
	dfs1(1, 0);
	dfs2(1,0,0LL);
	printf("%lld\n", ans);
	return 0;
}
