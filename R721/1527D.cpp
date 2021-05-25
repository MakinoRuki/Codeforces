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
#include <time.h>
#define eps 1e-7
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
vector<int> edges[N];
ll ans[N];
ll son[N];
int minv[N];
bool vis[N];
ll tot;
int lu, ru;
int plu, pru;
void find(int k) {
	if (k == lu || k == ru) {
		ll res = 1LL;
		if (son[plu] > son[lu]) {
			res *= son[lu];
		} else {
			res *= n-son[plu];
		}
		if (son[pru] > son[ru]) {
			res *= son[ru];
		} else {
			res *= n-son[pru];
		}
		ans[k] = tot - res;
		tot -= ans[k];
		return;
	}
	for (int i = 0; i < edges[lu].size(); ++i) {
		int v = edges[lu][i];
		if (v == plu) {
			continue;
		}
		if (minv[v] == k) {
			if (pru < 0) pru = v;
			plu = lu;
			lu = v;
			vis[lu] = true;
			find(k);
			return;
		}
	}
	for (int i = 0; i < edges[ru].size(); ++i) {
		int v = edges[ru][i];
		if (v == pru) {
			continue;
		}
		if (minv[v] == k) {
			pru = ru;
			ru = v;
			vis[ru] = true;
			find(k);
			return ;
		}
	}
	// For example, {(1,0),(2,0),(3,2),(0,4)}, k = 4.
	ans[k] = tot;
	tot = 0;
	return ;
}
void dfs(int u, int p) {
	son[u] = 1;
	minv[u] = u;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u);
		son[u] += son[v];
		minv[u] = min(minv[u], minv[v]);
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i) {
			edges[i].clear();
			son[i] = 0;
			ans[i] = 0;
			vis[i] = false;
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		tot=0LL;
		dfs(0, -1);
		for (int i = 0; i < edges[0].size(); ++i) {
			ll tmp = son[edges[0][i]];
			if (tmp >= 2) {
				ans[0] += tmp*(tmp-1)/2;
			}
		}
		tot = (ll)n*(ll)(n-1)/2 - ans[0];
		lu = 0, ru = 0;
		vis[0] = true;
		plu = -1, pru = -1;
		for (int k = 1; k <= n; ++k) {
		  // For example, {(0,1),(1,2),(1,3),(0,4)}, k=4.
			if (vis[k] || tot == 0) {
				ans[k] = 0;
			} else {
				find(k);
			}
		}
		for (int i = 0; i <= n; ++i) {
			printf("%lld", ans[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
