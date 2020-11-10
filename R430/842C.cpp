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
int a[N];
vector<int> edges[N];
ll ans[N];
ll getgcd(ll x, ll y) {
	return y==0 ? x : getgcd(y, x%y);
}
void dfs1(int u, int p, ll g) {
	if (u!=1) {
		g= getgcd(g, a[u]);
		ans[u]=g;
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs1(v, u, g);
	}
}
void dfs2(int u, int p, ll g, int cnt) {
	if (a[u] % g != 0) {
		cnt++;
	}
	if (cnt<=1) {
		ans[u]=max(ans[u], g);
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs2(v, u, g, cnt);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	if (n==1) {
		cout<<a[1]<<endl;
	} else {
		ll g=0;
		dfs1(1, 0, g);
		for (int d = 1; d * d <= a[1]; ++d) {
			if (a[1] % d==0) {
				g = d;
				int cnt=0;
				dfs2(1, 0, g, cnt);
				if (a[1]/d != d) {
					g=a[1]/d;
					cnt=0;
					dfs2(1, 0, g, cnt);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%lld", ans[i]);
			if (i<n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

