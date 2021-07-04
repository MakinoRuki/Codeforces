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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
int a[N];
vector<int> edges[N];
ll dp[N][2];
ll ans;
void dfs(int u, int p, int b) {
	bool odd = false;
	if ((1<<b) & a[u]) {
		dp[u][1] = 1;
		odd = true;
	} else {
		dp[u][0] = 1;
	}
	ll t0 = 0LL, t1 = 0LL;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==p) continue;
		dfs(v, u, b);
		if (odd) {
			ans += dp[v][0] * t0 * (1LL<<b);
			ans += dp[v][1] * t1 * (1LL<<b);
			dp[u][0] += dp[v][1];
			dp[u][1] += dp[v][0];
		} else {
			ans += dp[v][0] * t1 * (1LL<<b);
			ans += dp[v][1] * t0 * (1LL<<b);
			dp[u][0] += dp[v][0];
			dp[u][1] += dp[v][1];
		}
		t0 += dp[v][0];
		t1 += dp[v][1];
	}
	ans += dp[u][1] * (1LL<<b);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ans = 0LL;
	for (int i = 20; i >= 0; --i) {
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = 0;
			dp[i][1] = 0;
		}
		dfs(1, 0, i);
	}
	printf("%lld\n", ans);
  return 0;
}
