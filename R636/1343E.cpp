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
#include <queue>
#define N 200005
using namespace std;
typedef long long ll;
int t, n, m, a, b, c;
int p[N];
ll sum[N];
vector<int> edges[N];
int dis[3][N];
bool vis[N];
void bfs(int id, int s) {
	for (int i = 1; i <= n; ++i) {
		dis[id][i] = 1000000000;
		vis[i] = false;
	}
	dis[id][s] = 0;
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 0; i < edges[u].size(); ++i) {
			int v= edges[u][i];
			if (dis[id][v] > dis[id][u]+1) {
				dis[id][v] = dis[id][u]+1;
				if (!vis[v]) {
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m>>a>>b>>c;
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &p[i]);
		}
		sort(p+1, p+m+1);
		sum[0] = 0LL;
		for (int i = 1; i <= m; ++i) {
			sum[i] = sum[i-1]+p[i];
		}
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		bfs(0, a);
		bfs(1, b);
		bfs(2, c);
		ll ans = (1LL<<62)-1;
		if (a == b && b != c) {
			int d = dis[1][c];
			ans = min(ans, sum[d]);
		} else if (a != b && b == c) {
			int d = dis[0][b];
			ans = min(ans, sum[d]);
		} else if (a == c && a != b) {
			int d = dis[1][a];
			ans = min(ans, 2*sum[d]);
		} else {
			for (int i =1 ; i <= n; ++i) {
				int d1 = dis[0][i];
				int d2 = dis[2][i];
				int d0 = dis[1][i];
			//	cout<<d1<<" "<<d0<<" "<<d2<<endl;
				if(d1+d2+d0<=m) ans = min(ans, sum[d1+d2+d0] + sum[d0]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
