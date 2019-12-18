#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
int t, k;
vector<pair<int, int> > edges[N];
int sons[N];
ll minv, maxv;
void dfs1(int u, int p) {
	sons[u]++;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v == p) continue;
		dfs1(v, u);
		sons[u] += sons[v];
	}
}
// 对于每一条边，minv是所有pair尽量在同侧，只有两侧都是奇数个点的时候才必经过此边一次；
// maxv则是所有pair尽量在不同侧，那么就是min(sons[u],n-sons[u])。
void dfs2(int u, int p) {
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		int w = edges[u][i].second;
		if (v == p) continue;
		ll s1 = sons[v];
		ll s2 = 2 * k - s1;
		if (s1 & 1) minv += (ll)w;
		maxv += (ll)min(s1, s2) * (ll)w;
		dfs2(v, u);
	}
}
int main() {
	cin>>t;
	for (int cas =1 ; cas <= t; ++cas) {
		cin>>k;
		for (int i = 1; i <= 2 * k; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < 2 * k; ++i) {
			int u, v, w;
			cin>>u>>v>>w;
			edges[u].push_back(make_pair(v, w));
			edges[v].push_back(make_pair(u, w));
		}
		minv = 0;
		maxv = 0;
		memset(sons, 0, sizeof(sons));
		dfs1(1, 0);
		dfs2(1, 0);
		cout<<minv<<" "<<maxv<<endl;
	}
	return 0;
}
