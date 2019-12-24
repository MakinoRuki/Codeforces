#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#define N 200005
using namespace std;
typedef long long ll;
int t, n, m, a, b;
vector<int> edges[N];
bool vis[2][N];
void dfs(int x, int y, int z) {
	vis[z][x]=true;
	for (int i = 0; i < edges[x].size(); ++i) {
		int v = edges[x][i];
		if (!vis[z][v] && v != y) {
			dfs(v, y, z);
		}
	}
}
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		cin>>n>>m>>a>>b;
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		memset(vis, false, sizeof(vis));
		dfs(a, b, 0);
		dfs(b, a, 1);
		ll at=0;
		ll bt = 0;
		for (int i =1; i <= n; ++i) {
			if (i == a || i == b) continue;
			if (vis[0][i] && !vis[1][i]) at++;
			else if (!vis[0][i] && vis[1][i]) bt++;
		}
		cout<<at*bt<<endl;
	}
	return 0;
}
