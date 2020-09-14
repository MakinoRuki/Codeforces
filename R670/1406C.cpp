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
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
vector<int> edges[N];
vector<pair<int,int>> es;
int son[N];
int cur;
void dfs(int u, int p, vector<int>& vs) {
	int maxv=0;
	int tot=0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs(v, u, vs);
		maxv=max(maxv, son[v]);
		tot += son[v];
	}
	maxv=max(maxv, n-tot-1);
	if (maxv<cur) {
		cur=maxv;
		vs.clear();
		vs.push_back(u);
	} else if (maxv==cur) {
		vs.push_back(u);
	}
	son[u] = tot+1;
}
int dfs2(int u, int p) {
	int tot=1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		tot += dfs2(v, u);
	}
	return tot;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		es.clear();
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			son[i]=0;
		}
		for (int i = 1; i < n; ++i) {
			int x,y;
			scanf("%d%d", &x, &y);
			es.push_back(make_pair(x,y));
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		cur=n;
		vector<int> vs;
		vs.clear();
		dfs(1, 0, vs);
		if (vs.size() ==1) {
			int x=es[0].first;
			int y=es[0].second;
			printf("%d %d\n", x,y);
			printf("%d %d\n", x, y);
		} else {
			//cout<<vs.size()<<" "<<vs[0]<<" "<<vs[1]<<endl;
			int x=vs[0];
			int y=vs[1];
			int id=-1;
			int maxv=-1;
			for (int i = 0; i < edges[y].size(); ++i) {
				int v=edges[y][i];
				if (v==x) continue;
				int res=dfs2(v, y);
				if (res>maxv) {
					id=v;
					maxv=res;
				}
			}
			printf("%d %d\n", y, id);
			printf("%d %d\n", x, id);
		}
	}
	return 0;
}
