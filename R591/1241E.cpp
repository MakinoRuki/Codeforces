#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 500005
using namespace std;
typedef long long ll;
int n, k;
int q;
vector<pair<int, int>> edges[N];
ll dp[N][2];
void dfs(int u, int p) {
	dp[u][0] = 0;
	vector<ll> ws;
	ws.clear();
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		int w = edges[u][i].second;
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += dp[v][0];
		if (dp[v][1]+w-dp[v][0] > 0) {
			ws.push_back(dp[v][1]+w-dp[v][0]);
		}
	}
	sort(ws.begin(), ws.end(), [](ll& a, ll & b) {
		return a > b;
	});
	for (int i = 0; i < min(k, (int)ws.size()); ++i) {
		dp[u][0] += ws[i];
	}
	dp[u][1] = dp[u][0];
	if (k <= ws.size()) {
		dp[u][1] -= ws[k-1];
	}
}
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		scanf("%d%d", &n, &k);
		int u, v, w;
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			edges[u].push_back(make_pair(v, w));
			edges[v].push_back(make_pair(u, w));
		}
		dfs(1, 0);
		printf("%lld\n", dp[1][0]);
	}
	return 0;
}
