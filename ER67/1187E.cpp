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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
int sons[N];
ll tot[N];
void dfs1(int u, int p) {
	sons[u]=1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs1(v, u);
		sons[u] += sons[v];
		tot[u] += tot[v]+sons[v];
	}
}
void dfs2(int u, int p, ll pre) {
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs2(v, u, tot[u]-tot[v]-(ll)sons[v]+pre+(ll)n-(ll)sons[u]);
	}
	tot[u] += pre+(ll)n-(ll)sons[u];
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int u,v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	memset(sons, 0, sizeof(sons));
	memset(tot, 0LL, sizeof(tot));
	dfs1(1, 0);
	dfs2(1, 0, 0LL);
	ll ans=0;
	for (int i = 1; i <= n; ++i) {
		ans=max(ans, tot[i]+n);
	}
	cout<<ans<<endl;
	return 0;
}
