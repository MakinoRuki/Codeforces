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
ll mod = 1000000007LL;
int n, m, k;
vector<int> edges[N];
int p[N];
int dis[N];
ll num[N];
void bfs(int s) {
	for (int i = 1; i <= n; ++i) {
		dis[i] = 1000000000;
		num[i] = 0;
	}
	queue<int> q;
	bool vis[N];
	memset(vis, false, sizeof(vis));
	q.push(s);
	dis[s] = 0;
	vis[s] = true;
	while(!q.empty()) {
		int cur= q.front();
		q.pop();
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v = edges[cur][i];
			if (!vis[v]) {
				vis[v] = true;
				dis[v] = dis[cur]+1;
				num[v]++;
				q.push(v);
			} else if (dis[v] == dis[cur]+1) {
				num[v]++;
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin>>u>>v;
		edges[v].push_back(u);
	}
	cin>>k;
	for (int i = 1; i <= k; ++i) {
		cin>>p[i];
	}
	bfs(p[k]);
	int minv = 0;
	int maxv = 0;
	for (int i = 1; i < k; ++i) {
		if (dis[p[i+1]] + 1 > dis[p[i]]) {
			minv++;
			maxv++;
		} else if (num[p[i]] > 1) {
			maxv++;
		}
	}
	cout<<minv<<" "<<maxv<<endl;
	return 0;
}
