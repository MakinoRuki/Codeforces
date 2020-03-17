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
#define N 100005
using namespace std;
typedef long long ll;
int t, n;
vector<pair<int, int>> edges[N];
vector<pair<int, int>> es;
ll cnt[N];
int ans[N];
int son[N];
void dfs(int u, int p) {
	son[u] = 1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v==p) continue;
		int id = edges[u][i].second;
		dfs(v, u);
		cnt[id] = son[v] * (ll)(n-son[v]);
		son[u] += son[v];
	}
}
int main() {
	cin>>n;
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin>>u>>v;
		edges[u].push_back(make_pair(v,i));
		edges[v].push_back(make_pair(u,i));
		es.push_back(make_pair(u,v));
	}
	for (int i = 0; i <= n; ++i) {
		son[i]= 0;
	}
	dfs(1, 0);
	vector<pair<ll, int>> rk;
	rk.clear();
	for (int i = 0; i < n-1; ++i) {
		rk.push_back(make_pair(cnt[i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = n-2; i >= 0; --i) {
		ans[rk[i].second] = i;
	}
	for (int i = 0; i < n-1; ++i) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
