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
#define N 1000005
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
int op[N];
int num[N];
int res[N];
int dfs1(int u, int p) {
	if (op[u] == 0) {
		return num[u];
	}
	if (op[u] == 4) {
		return num[u] = !dfs1(edges[u][0], u);
	}
	if (op[u]==1) {
		return num[u] = dfs1(edges[u][0], u) & dfs1(edges[u][1], u);
	}
	if (op[u]==2) {
		return num[u] = dfs1(edges[u][0],u) | dfs1(edges[u][1], u);
	}
	if (op[u]==3) {
		return num[u] = dfs1(edges[u][0],u) ^ dfs1(edges[u][1], u);
	}
}
void dfs2(int u, int p, int pre) {
	if (op[u] == 0) {
		res[u] = pre;
		return;
	}
	if (op[u] == 4) {
		dfs2(edges[u][0], u, pre);
		return ;
	}
	int v1=edges[u][0];
	int v2=edges[u][1];
	if (op[u]==1) {
		if (num[v1]&&num[v2]) {
			dfs2(v1, u, pre);
			dfs2(v2, u, pre);
		} else if (!num[v1] && !num[v2]) {
			dfs2(v1, u, 0);
			dfs2(v2, u, 0);
		} else {
			dfs2(v1, u, (num[v1] ? 0 : pre));
			dfs2(v2, u, (num[v2] ? 0 : pre));
		}
	} else if (op[u] == 2) {
		if (num[v1] && num[v2]) {
			dfs2(v1, u, 0);
			dfs2(v2, u, 0);
		} else if (!num[v1] && !num[v2]) {
			dfs2(v1, u, pre);
			dfs2(v2, u, pre);
		} else {
			dfs2(v1, u, (num[v1] ? pre : 0));
			dfs2(v2, u, (num[v2] ? pre : 0));
		}
	} else {
		dfs2(v1, u, pre);
		dfs2(v2, u, pre);
	}
}
int main() {
	cin>>n;
	memset(num, -1, sizeof(num));
	for (int i = 1; i <= n; ++i) {
		string oo;
		cin>>oo;
		if (oo == "IN") {
			int x;
			scanf("%d", &x);
			num[i] = x;
			op[i]=0;
		} else if (oo != "NOT") {
			int x, y;
			scanf("%d%d", &x, &y);
			edges[i].push_back(x);
			edges[i].push_back(y);
			if (oo=="AND") op[i]=1;
			if (oo=="OR") op[i]=2;
			if (oo=="XOR") op[i]=3;
		} else {
			int x;
			scanf("%d", &x);
			edges[i].push_back(x);
			op[i]=4;
		}
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (int i = 1; i <= n; ++i) {
		if (op[i]==0) {
			cout<<(res[i]^num[1]);
		}
	}
	cout<<endl;
	return 0;
}
