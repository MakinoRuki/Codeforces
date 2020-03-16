#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 205
using namespace std;
typedef long long ll;
int n,k;
int a[N];
vector<int> edges[N];
int dp[N][N];
int lev[N];
void dfs(int u, int p) {
	lev[u] = 0;
	dp[u][0] = a[u];
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u);
		int tmp[N];
		for (int j = 0; j <= max(lev[u], lev[v]+1); ++j) {
			tmp[j] = 0;
		}
		for (int j = 0; j <= lev[u]; ++j) {
			for (int x = max(0, k - j); x <= lev[v]; ++x) {
				tmp[min(j, x+1)] = max(tmp[min(j, x+1)], dp[u][j] + dp[v][x]); 
			}
		}
		for (int j = 0; j <= lev[v]; ++j) {
			tmp[j+1] = max(tmp[j+1], dp[v][j]);
		}
		lev[u] = max(lev[u], lev[v]+1);
		for (int j = 0; j <= lev[u]; ++j) {
			dp[u][j] = max(dp[u][j], tmp[j]);
		}
		for (int j = lev[u]-1; j >= 0; --j) {
			dp[u][j] = max(dp[u][j], dp[u][j+1]);
		}
	}
}
int main() {
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	memset(dp, 0, sizeof(dp));
	dfs(1, 0);
	cout<<dp[1][0]<<endl;
	return 0;
}
