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
#include <queue>
#define N 10005
using namespace std;
typedef long long ll;
const ll inf = (1LL<<62)-1;
int n, m;
int d[N];
int r, g;
vector<pair<int, int>> edges[N];
int dis[N][N/10+2];
typedef pair<int,int> pii;
void solve(int s) {
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < g; ++j) {
			dis[i][j] = 1000000000;
		}
	}
	dis[s][0] = 0;
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
	q.push(make_pair(0, make_pair(s, 0)));



	
	while(!q.empty()) {
		auto top = q.top();
		int ds = top.first;
		int u = top.second.first;
		int rm = top.second.second;
		q.pop();
		if (ds > dis[u][rm]) continue;
		for (int i = 0; i < edges[u].size(); ++i) {
			int v = edges[u][i].first;
			int w = edges[u][i].second;
			if (rm + w < g) {
				if (dis[v][rm+w] > ds) {
					dis[v][rm+w] = ds;
					q.push(make_pair(ds, make_pair(v, rm+w)));
				}
			} else if (rm + w == g) {
				if (dis[v][0] > ds+1) {
					dis[v][0] = ds+1;
					q.push(make_pair(ds+1, make_pair(v, 0)));
				}
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &d[i]);
	}
	cin>>g>>r;
	sort(d+1, d+m+1);
	for (int i = 1; i < m; ++i) {
		if (d[i+1]-d[i]<=g) {
			edges[i].push_back(make_pair(i+1, d[i+1]-d[i]));
			edges[i+1].push_back(make_pair(i, d[i+1]-d[i]));
		}
	}
	solve(1);
	ll ans=inf;
	for (int i = 1; i <= m; ++i) {
		if (dis[i][0] < 1000000000 && n-d[i]<=g) {
			ans = min(ans, (ll)dis[i][0]*(ll)(g+r)+n-d[i]);
		}
	}
	if (ans < inf) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}
