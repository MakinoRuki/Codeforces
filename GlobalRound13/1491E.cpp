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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
vector<pair<int,int>> es;
vector<pair<int,int>> edges[N];
bool vis[N];
vector<int> fs;
int sons[N];
void dfs2(int u, int p, int id, int& eid, int& uid) {
	sons[u] = 1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		int x = edges[u][i].second;
		if (v==p) continue;
		if (vis[x]) continue;
		dfs2(v, u, id, eid, uid);
		if (sons[v] == fs[id-1] || sons[v] == fs[id-2]) {
			eid = x;
			uid = v;
		}
		sons[u] += sons[v];
	}
}
bool dfs(int u, int p, int id) {
//	cout<<"u="<<u<<" "<<id<<endl;
	if (id <= 1) return true;
	int eid = -1, uid = -1;
	dfs2(u, p, id, eid, uid);
//	cout<<eid<<endl;
	if (eid < 0) return false;
	vis[eid] = true;
	int vid;
	if (es[eid-1].first == uid) {
		vid = es[eid-1].second;
	} else {
		vid = es[eid-1].first;
	}
	int id1 = (sons[uid] == fs[id-1] ? id - 1: id -2);
	int id2 = (sons[uid] == fs[id-1] ? id - 2 : id-1);
	if (!dfs(uid, vid, id1)) return false;
	if (!dfs(u, p, id2)) return false;
	return true;
}
int main() {
	cin>>n;
	es.clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		es.push_back(make_pair(u, v));
		edges[u].push_back(make_pair(v, i));
		edges[v].push_back(make_pair(u, i));
	}
	fs.clear();
	fs.push_back(1);
	fs.push_back(1);
	while(true) {
		int x = fs[fs.size()-1] + fs[fs.size()-2];
		if (x > n) break;
		fs.push_back(x);
	}
	memset(vis, false, sizeof(vis));
	if ((fs.empty() || fs.back()!=n) || !dfs(1, 0, (int)fs.size()-1)) {
		puts("NO");
	} else {
		puts("YES");
	}
  return 0;
}
