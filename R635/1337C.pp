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
int n, k;
vector<int> edges[N];
int par[N];
int cnt[N];
int len[N];
int sons[N];
void dfs(int u, int p, int x) {
	len[u] = x;
	par[u] = p;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u, x+1);
		sons[u] += sons[v]+1;
	}
}
int main() {
	cin>>n>>k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	memset(par, 0, sizeof(par));
	memset(cnt, 0, sizeof(cnt));
	memset(sons,0, sizeof(sons));
	dfs(1, 0, 0);
//	cout<<"xxx"<<endl;
	set<pair<ll, int>> ss;
	ss.clear();
	ll tot=0LL;
	for (int i = 2; i <= n; ++i) {
		if (edges[i].size()==1) {
			ss.insert(make_pair(-len[i], i));
		}
	}
	for (int i = 1; i <= k; ++i) {
		auto p = *ss.begin();
		tot += -p.first;
		int u = p.second;
		cnt[par[u]]+=cnt[u]+1;
		ss.erase(p);
		if (cnt[par[u]] == sons[par[u]]) {
			int v = par[u];
			ll det = len[v] - sons[v];
			ss.insert(make_pair(-det, v));
		}
	//	cout<<i<<" "<<u<<" "<<tot<<endl;
	//	cout<<i<<" "<<u<<" "<<ss.size()<<endl;
	}
	cout<<tot<<endl;
	return 0;
}
