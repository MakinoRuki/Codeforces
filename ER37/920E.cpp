#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#define M 1000005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
int par[N];
vector<int> edges[N];
list<int> ls;
int find(int x) {
	return x== par[x] ? x : par[x] = find(par[x]);
}
bool vis[N];
int bfs(int st) {
	int cnt=0;
	queue<int> q;
	q.push(st);
	cnt++;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		set<int> ss(edges[u].begin(), edges[u].end());
		auto itr = ls.begin();
		while(itr != ls.end()) {
			auto v = *itr;
			if (ss.find(v) == ss.end()) {
				cnt++;
				q.push(v);
				ls.erase(itr++);
			} else {
				itr++;
			}
		}
	}
	return cnt;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		par[i]= i;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
		int pu = find(u);
		int pv = find(v);
		if (pu != pv) {
			par[pu] = pv;
		}
	}
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		par[i] = find(i);
		if (par[i] == i) cnt++;
	}
	if (cnt > 1) {
		puts("1");
		printf("%d\n", n);
		return 0;
	}
	memset(vis, false, sizeof(vis));
	int tot=0;
	vector<int> ans;
	ans.clear();
	ls.clear();
	for (int i = 1; i <= n; ++i) {
		ls.push_back(i);
	}
	while(!ls.empty()) {
		auto u = *ls.begin();
		ls.erase(ls.begin());
		tot++;
		ans.push_back(bfs(u));
	}
	printf("%d\n", tot);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d", ans[i]);
		if (i < ans.size()-1) cout<<" ";
		else cout<<endl;
	}
  return 0;
}

