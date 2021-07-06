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
#define M 22
#define N 32
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int l, r;
vector<int> edges[N];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
ll ans[N][2];
int deg[N];
void dfs(int u, int pd, int p, ll x, ll y, ll det) {
	ans[u][0] = x;
	ans[u][1] = y;
	set<int> ss;
	ss.clear();
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		for (int d = 0; d < 4; ++d) {
			if (ss.find(d) != ss.end() || d == pd) {
				continue;
			}
			ss.insert(d);
		//	cout<<u<<" "<<v<<" "<<x + dx[d]*det<<" "<<y + dy[d]*det<<endl;
			dfs(v, 3-d, u, x + dx[d]*det, y + dy[d]*det, det/2);
			break;
		}
	}
}
int main() {
	cin>>n;
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i] > 4) {
			puts("NO");
			return 0;
		}
	}
	dfs(1, -1, 0, 0, 0, (1LL<<30));
	puts("YES");
	for (int i = 1; i <= n; ++i) {
		printf("%lld %lld\n", ans[i][0], ans[i][1]);
	}
  return 0;
}
