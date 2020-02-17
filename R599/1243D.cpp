#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
int n, m;
unordered_map<int, unordered_set<int>> edges;
unordered_set<int> vis;
void dfs(int u) {
	vector<int> tmp;
	for (auto v : vis) {
		if (edges[u].find(v) == edges[u].end()) {
			tmp.push_back(v);
		}
	}
	// 准备要dfs到v之前，先把v从vis中删掉。
	for (int i = 0; i < tmp.size(); ++i) {
		vis.erase(tmp[i]);
	}
	for (int i = 0; i < tmp.size(); ++i) {
		dfs(tmp[i]);
	}
}
int main() {
	cin>>n>>m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin>>u>>v;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	for (int i = 1; i <= n; ++i) {
		vis.insert(i);
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		if (vis.find(i) != vis.end()) {
			vis.erase(i);
			ans++;
			dfs(i);
		}
	}
	cout<<ans-1<<endl;
	return 0;
}
