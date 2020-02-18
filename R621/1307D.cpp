#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n, m, k;
vector<int> edges[N];
int a[N];
ll dis[2][N];
void bfs(int s, int id) {
	queue<int> q;
	bool vis[N];
	for (int i = 1; i <= n; ++i) {
		dis[id][i] = 1000000000;
	}
	memset(vis, false, sizeof(vis));
	dis[id][s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v = edges[cur][i];
			if (!vis[v]) {
				dis[id][v] = dis[id][cur]+1;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		int x,y;
		cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	bfs(1, 0);
	bfs(n, 1);
	//cout<<dis[0][n]<<" "<<dis[1][1]<<endl;
	ll ans = dis[0][n];
	set<pair<ll, int>> ds;
	ds.clear();
	// for (int i = 1; i <= k; ++i) {
	// 	ds.insert(make_pair(dis[1][a[i]], i));
	// }
	vector<pair<ll, int>> rks;
	rks.clear();
	for (int i = 1; i <= k; ++i) {
		rks.push_back(make_pair(dis[0][a[i]]-dis[1][a[i]], i));
	}
	sort(rks.begin(), rks.end());
	int j = k;
	ll tmp=0;
	for (int i = k; i >= 1; --i) {
		int id1 = rks[i-1].second;
		while(j > i) {
			int id2 = rks[j-1].second;
			ds.insert(make_pair(dis[1][a[id2]], a[id2]));
			j--;
		}
		if (!ds.empty()) {
			ll tmp2 = dis[0][a[id1]] + (*ds.rbegin()).first + 1;
			tmp= max(tmp, tmp2);
		}
	}
	ans = min(ans, tmp);
	cout<<ans<<endl;
	return 0;
}
