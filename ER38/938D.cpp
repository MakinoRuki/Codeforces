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
int n, m;
vector<pair<int, ll>> edges[N];
ll a[N];
ll dis[N];
void bfs(vector<pair<ll,int>>& rk) {
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	//dis[s] = min(dis[s], w);
	for (int i = 0; i < rk.size(); ++i) {
		int s = rk[i].second;
		ll w = rk[i].first;
		dis[s] = w;
		pq.push(make_pair(dis[s], s));
	}
	while(!pq.empty()) {
		auto pr = pq.top();
		pq.pop();
		ll ds = pr.first;
		int u = pr.second;
		if (ds > dis[u]) {
			continue;
		}
		for (int i = 0; i < edges[u].size(); ++i) {
			int v = edges[u][i].first;
			ll w2 = edges[u][i].second;
			if (dis[v] > dis[u]+2LL*w2) {
				dis[v] = dis[u]+2LL*w2;
				pq.push(make_pair(dis[v], v));
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
	}
	vector<pair<ll, int>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		rk.push_back(make_pair(a[i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 1; i <= n; ++i) {
		dis[i] = (1LL<<60)-1;
	}
	// for (int i = 0; i < rk.size(); ++i) {
	// 	bfs(rk[i].second, rk[i].first);
	// }
	bfs(rk);
	for (int i = 1; i <= n; ++i) {
		printf("%lld", dis[i]);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
