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
int n, m, k;
vector<pair<pair<int, int>, int>> edges;
vector<pair<int, int>> edges2[N];
map<pair<int,int>, ll> ds;
bool vis[N];
ll dis[N];
void bfs(int s) {
	if (edges2[s].empty()) return;
	dis[s] = 0;
	vis[s] = true;
	queue<int> q;
	q.push(s);
	set<int> ps;
	ps.clear();
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		vis[cur] = false;
		ps.insert(cur);
		for (int i = 0; i < edges2[cur].size(); ++i) {
			int v = edges2[cur][i].first;
			ll w = edges2[cur][i].second;
			if (dis[v] > dis[cur]+w) {
				dis[v] =dis[cur]+w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	for (auto p : ps) {
		if (p==s) continue;
		int u = min(s, p);
		int v = max(s, p);
		ds[make_pair(u,v)] = dis[p];
	}
	for (auto p : ps) {
		dis[p] = 1LL<<62;
		vis[p] = false;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	edges.clear();
	for (int i = 0; i < m; ++i) {
		int x,y,w;
		scanf("%d%d%d", &x, &y, &w);
		edges.push_back(make_pair(make_pair(x, y), w));
	}
	vector<pair<int, int>> rk;
	rk.clear();
	for (int i = 0; i < m; ++i) {
		rk.push_back(make_pair(edges[i].second, i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < min(m, k); ++i) {
		int id = rk[i].second;
		int u = edges[id].first.first;
		int v = edges[id].first.second;
		int w = edges[id].second;
		edges2[u].push_back(make_pair(v, w));
		edges2[v].push_back(make_pair(u, w));
	}
	ds.clear();
	for (int i = 1; i <= n; ++i) {
		vis[i] = false;
		dis[i] = 1LL<<62;
	}
	for (int i = 1; i <= n; ++i) {
		bfs(i);
	}
	vector<ll> rk2;
	rk2.clear();
	for (auto v : ds) {
		rk2.push_back(v.second);
	}
	sort(rk2.begin(), rk2.end());
	cout<<rk2[k-1]<<endl;
	return 0;
}
