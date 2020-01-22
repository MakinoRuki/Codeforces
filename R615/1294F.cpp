#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
vector<int> edges[N];
int dis[N];
int pre[N];
void dfs(int cur, int p, int d) {
	dis[cur] = d;
	pre[cur] = p;
	for (int i = 0; i < edges[cur].size(); ++i) {
		int v = edges[cur][i];
		if (v == p) continue;
		dfs(v, cur, d+1);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dis[1] = 0;
	dfs(1, 0, 0);
	int maxd = 0;
	int idx = 1;
	for (int i = 2; i <= n; ++i) {
		if (dis[i] > maxd) {
			maxd = dis[i];
			idx = i;
		}
	}
	dis[idx] = 0;
	dfs(idx, 0, 0);
	maxd = 0;
	int idx2 = idx;
	for (int i = 1; i <= n; ++i) {
		if (i == idx) continue;
		if (dis[i] > maxd) {
			maxd = dis[i];
			idx2 = i;
		}
	}
	int tot = maxd;
	int cur = idx2;
	int idx3 = -1;
	set<int> path;
	path.clear();
	while(cur != idx) {
		path.insert(cur);
		cur = pre[cur];
	}
	path.insert(cur);
	memset(dis, 0, sizeof(dis));
	for (auto v : path) {
		for (int i = 0; i < edges[v].size(); ++i) {
			if (path.find(edges[v][i]) == path.end()) {
				dfs(edges[v][i], v, 1);
			}
		}
	}
	maxd = 0;
	idx3 = pre[idx2];
	for (int i = 1; i <= n; ++i) {
		if (i != idx && i != idx2 && dis[i] > maxd) {
			maxd = dis[i];
			idx3 = i;
		}
	}
	tot += maxd;
	cout<<tot<<endl;
	cout<<idx<<" "<<idx2<<" "<<idx3<<endl;
	return 0;
}
