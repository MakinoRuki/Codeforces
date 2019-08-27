// 对于任一bit，含有的数超过3个就是3。
// 否则对于每一个bit最多两个数字连边，最多60条边求删掉某条边的最短路。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
int n;
ll a[N];
vector<int> edges[N];
int dis[N];
bool vis[N];
vector<int> bfs(int s, int t) {
	dis[s] = 0;
	vis[s] = true;
	queue<int> q;
	q.push(s);
	vector<int> res;
	res.clear();
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < edges[u].size(); ++i) {
			int v = edges[u][i];
			if ((u == s && v == t) || (u == t && v == s)) continue;
			if (!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[u]+1;
				q.push(v);
				res.push_back(v);
			}
		}
	}
	return res;
}
int main() {
	cin>>n;
	map<ll, vector<int> > cnt;
	cnt.clear();
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		for (int j = 0; j <= 60; ++j) {
			if ((1LL << j) & a[i]) {
				if (cnt[1LL<<j].size() < 3) cnt[1LL<<j].push_back(i);
			}
		}
	}
	bool ok = false;
	for (int j = 0; j <=60; ++j) {
		if (cnt[1LL<<j].size() >= 3) {
			cout<<3<<endl;
			ok = true;
			break;
		}
	}
	if (!ok) {
		for (int j = 0; j <= 60; ++j) {
			if (cnt[1LL<<j].size() > 1) {
				int u = cnt[1LL<<j][0];
				int v = cnt[1LL<<j][1];
				edges[u].push_back(v);
				edges[v].push_back(u);
			}
		}
		int ans = n+1;
		for (int i = 0; i < n; ++i) {
			dis[i] = inf;
		}
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < edges[i].size(); ++j) {
				int u = edges[i][j];
				vector<int> res = bfs(i, u);
				if (dis[u] < inf) ans = min(ans, dis[u]+1);
				for (int j = 0; j < res.size(); ++j) {
					int u = res[j];
					dis[u] = inf;
					vis[u] = false;
				}
				dis[i] = inf;
				vis[i] = false;
			}
		}
		cout<<(ans > n ? -1 : ans)<<endl;
	}
	return 0;
}
