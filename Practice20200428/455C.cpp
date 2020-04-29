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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m, q;
int par[N];
int len[N][2];
vector<int> edges[N];
bool vis[N];
int dis[N];
vector<int> ns;
int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}
void dfs(int u, int p, int d) {
	dis[u] = d;
	ns.push_back(u);
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p) continue;
		dfs(v, u, d+1);
	}
}
void dfs2(int u, int p, int d) {
	dis[u] = d;
	par[u] = p;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p) continue;
		dfs2(v, u, d+1);
	}
}
int main() {
	cin>>n>>m>>q;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		len[i][0]=len[i][1] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		if (edges[i].size() > 0 && !vis[i]) {
			ns.clear();
			dfs(i, 0, 0);
			int id = -1;
			int maxd = 0;
			for (int j = 0; j < ns.size(); ++j) {
				if (dis[ns[j]]>maxd) {
					maxd = dis[ns[j]];
					id = ns[j];
				}
			}
			dfs2(id, 0, 0);
			maxd = 0;
			int id2 = -1;
			for (int j = 0; j < ns.size(); ++j) {
				if (dis[ns[j]] > maxd) {
					maxd = dis[ns[j]];
					id2 = ns[j];
				}
			}
			int cur=id2;
			int cnt=0;
			while(cnt<maxd/2) {
				cur=par[cur];
				cnt++;
			}
			len[cur][0] = maxd;
			len[cur][1] = (maxd+1)/2;
			for (int j = 0; j < ns.size(); ++j) {
				vis[ns[j]] = true;
				par[ns[j]] = cur;
			}
		}
	}

	for (int i = 1; i <= q; ++i) {
		int f,x,y;
		scanf("%d", &f);
		if (f==1) {
			scanf("%d", &x);
			printf("%d\n", len[find(par[x])][0]);
		} else {
			scanf("%d%d", &x, &y);
			int px = find(par[x]);
			int py = find(par[y]);
			if (px == py) {
				//cout<<len[px][0]<<endl;
				continue;
			}
			int ans = max(len[px][0], len[py][0]);
			ans = max(ans, len[px][1]+len[py][1]+1);
			if (len[px][1]>len[py][1]) {
				par[py] = px;
				len[px][0] = ans;
				len[px][1] = max(len[px][1], len[py][1]+1);
			} else {
				par[px] = py;
				len[py][0] = ans;
				len[py][1] = max(len[py][1], len[px][1]+1);
			}
			//cout<<ans<<endl;
		}
	}
	return 0;
}
