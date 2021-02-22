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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll dp[N][M];
vector<pair<int,int>> edges[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 50; ++j) {
			dp[i][j] = (1LL<<60)-1;
		}
	}
	dp[1][0] = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
	}
	priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> pq;
	pq.push(make_pair(0, make_pair(1, 0)));
	while(!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		ll d = top.first;
		int u = top.second.first;
		int w = top.second.second;
		if (d > dp[u][w]) {
			continue;
		}
		for (int i = 0; i < edges[u].size(); ++i) {
			int v = edges[u][i].first;
			int w2 = edges[u][i].second;
			if (w == 0) {
				if (dp[v][w2] > dp[u][w] + (ll)w2*(ll)w2) {
					dp[v][w2] = dp[u][w] + (ll)w2*(ll)w2;
					pq.push(make_pair(dp[v][w2], make_pair(v, w2)));
				}
			} else {
				if (dp[v][0] > dp[u][w] + (ll)w2*(ll)w2 + 2LL*(ll)w*(ll)w2) {
					dp[v][0] = dp[u][w] + (ll)w2*(ll)w2 + 2LL*(ll)w*(ll)w2;
					pq.push(make_pair(dp[v][0], make_pair(v, 0)));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%lld", (dp[i][0] >= (1LL<<60)-1) ? -1 : dp[i][0]);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
