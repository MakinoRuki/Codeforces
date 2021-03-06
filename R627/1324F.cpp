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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n,h,l,r;
int a[N];
vector<int> edges[N];
int dp[N];
void dfs(int u, int p) {
	dp[u] = (a[u]?1:-1);
	for (int i= 0; i < edges[u].size(); ++i) {
		int v= edges[u][i];
		if (v ==p)continue;
		dfs(v,u);
		if (dp[v] >= 0) dp[u] += dp[v];
	}
}
void dfs2(int u, int p) {
	if (p > 0) {
		int v = dp[p];
		if (dp[u] >= 0) v-=dp[u];
		if (v>=0) dp[u] += v;
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p)continue;
		dfs2(v,u);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	for (int i = 1; i <= n; ++i) {
		cout<<dp[i];
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
