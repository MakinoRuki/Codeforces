#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
vector<pair<int,int>> edges[N];
int ans[N];
int vis[N];
int id[N];
vector<pair<int,int>> es;
int cnt;
bool dfs(int u) {
	if (vis[u] < 0) return false;
	if (vis[u] == 1) return true;
	vis[u] = -1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (!dfs(v)) return false;
	}
	vis[u] = 1;
	return true;
}
void dfs2(int u) {
	id[u] = ++cnt;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v= edges[u][i].first;
		if (id[v]==0) {
			dfs2(v);
		}
	}
}
int main() {
	cin>>n>>m;
	es.clear();
	for (int i = 1; i <= m; ++i) {
		ans[i] = -1;
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(make_pair(v, i));
		es.push_back(make_pair(u,v));
	}
	memset(vis, 0, sizeof(vis));
	int k=1;
	for (int i =1; i <= n; ++i) {
		if (vis[i]==0 && !dfs(i)) {
			k = 2;
			break;
		}
	}
	if (k==1) {
		cout<<1<<endl;
		for (int i = 1; i <= m; ++i) {
			cout<<1;
			if (i < m) cout<<" ";
			else cout<<endl;
		}
	} else {
		memset(id, 0, sizeof(id));
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (id[i] == 0) {
				dfs2(i);
			}
		}
		cout<<2<<endl;
		for (int i = 0; i < es.size(); ++i) {
			int u = es[i].first;
			int v = es[i].second;
			if (id[u] < id[v]) {
				cout<<1;
			} else {
				cout<<2;
			}
			if (i < es.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
