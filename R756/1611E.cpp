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
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
string s;
int t;
int n, k;
int a[N];
vector<int> edges[N];
//bool fs[N];
int p[N];
int dis[N];
int vis[N];
void dfs(int u, int pp, int d) {
	dis[u] = d;
	p[u] = pp;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if(v== pp) continue;
		dfs(v, u, d+1);
	}
}
void dfs2(int u, int pp, set<int>& ss, bool& found) {
	if (vis[u] > 0) {
		ss.insert(u);
		return;
	}
	bool leaf = true;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == pp) continue;
		leaf = false;
		dfs2(v, u, ss, found);
	}
	if (leaf) {
		found=true;
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		vector<int> fs;
		fs.clear();
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		//	fs[i] = false;
			vis[i] = -1;
		}
		for (int i = 1; i <= k; ++i) {
			int x;
			scanf("%d", &x);
			fs.push_back(x);
		//	fs[x] = true;
		}
		for (int i = 1; i < n; ++i) {
			int u,v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		p[1] = 0;
		dfs(1, 0, 0);
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 0; i < fs.size(); ++i) {
			rk.push_back(make_pair(dis[fs[i]], fs[i]));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i < rk.size(); ++i) {
			int d = dis[rk[i].second];
			d /= 2;
			int cur = rk[i].second;
			int j = 1;
			vis[cur] = cur;
			for (j = 1; j <= d; ++j) {
				if (vis[p[cur]] > 0) {
					break;
				}
				cur = p[cur];
				vis[cur] = rk[i].second;
			}
			// if (j > d) {
			// 	vis[cur] = fs[i];
			// }
		}
		set<int> ss;
		ss.clear();
		bool found=false;
		dfs2(1, 0, ss, found);
		if (found) {
			puts("-1");
		} else {
		//	puts("NO");
			printf("%d\n", (int)ss.size());
		}
	}
  return 0;
}

