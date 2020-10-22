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
#define eps 1e-7
#define M 20005
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int dis[N][2][N];
vector<pair<int,int>> edges[N];
vector<pair<pair<int,int>, int>> es;
int a[N], b[N];
void bfs(int id, int s, int f) {
	bool vis[N];
	for (int i = 1; i <= n; ++i) {
		dis[id][f][i] = inf+2;
		vis[i]=false;
	}
	dis[id][f][s]=0;
	queue<int> q;
	vis[s]=true;
	q.push(s);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		vis[cur]=false;
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v=edges[cur][i].first;
			int w=edges[cur][i].second;
			if (dis[id][f][v]>dis[id][f][cur]+w) {
				dis[id][f][v]=dis[id][f][cur]+w;
				if (!vis[v]) {
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
}
int main() {
	cin>>n>>m>>k;
	es.clear();
	for (int i=1; i <= m; ++i) {
		int x,y,w;
		scanf("%d%d%d", &x, &y, &w);
		edges[x].push_back(make_pair(y,w));
		edges[y].push_back(make_pair(x,w));
		es.push_back(make_pair(make_pair(x,y), w));
	}
	for (int i =1; i <= k; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		bfs(i, a[i], 0);
		bfs(i, b[i], 1);
	}
	int ans=0;
	for (int i = 1; i <= k; ++i) {
		ans += dis[i][0][b[i]];
	}
	for (int i = 1; i <= m; ++i) {
		int x=es[i-1].first.first;
		int y=es[i-1].first.second;
		int w=es[i-1].second;
		int res=0;
		for (int j=1; j <=k; ++j) {
			int res2=dis[j][0][b[j]];
			res2=min(res2, min(dis[j][0][x]+dis[j][1][y], dis[j][0][y]+dis[j][1][x]));
			res += res2;
		}
		ans=min(ans, res);
	}
	cout<<ans<<endl;
	return 0;
}
