#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
unordered_map<int, unordered_set<int>> edges;
int dis[N];
void dfs(int cur) {
	for (auto v : edges[cur]) {
		dfs(v);
		dis[cur] = max(dis[cur], dis[v] + 1);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int p;
		cin>>p;
		edges[p].insert(i);
	}
	vector<int> ps;
	ps.clear();
	vector<int> os;
	os.clear();
	memset(dis, 0, sizeof(dis));
	dfs(0);
	int cur = 0;
	while(true) {
		ps.push_back(cur);
		if (edges[cur].size() == 0) {
			break;
		} else if (edges[cur].size() == 1) {
			cur = *edges[cur].begin();
		} else {
			int v=-1;
			for (auto x : edges[cur]) {
				if (v < 0) v = x;
				else {
					if (dis[x] > dis[v]) {
						v = x;
					}
				}
			}
			while(edges[cur].size() > 1) {
				os.push_back(v);
				edges[cur].erase(v); 
				int u = *edges[cur].begin();
				edges[u].insert(v);
				dis[u] = max(dis[u], dis[v]+1);
				v= u;
			}
			cur = v;
		}
	}
	for (int i = 0; i < ps.size(); ++i) {
		cout<<ps[i];
		if (i < ps.size()-1) cout<<" ";
		else cout<<endl;
	}
	cout<<os.size()<<endl;
	for (int i = os.size()-1; i >= 0; --i) {
		cout<<os[i];
		if (i > 0) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
