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
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll w;
ll a[N][N];
ll dis[N][N];
ll ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
ll bfs(int sx, int sy) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dis[i][j] = (1LL<<60)-1;
		}
	}
	dis[sx][sy] = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(sx, sy));
	ll res = (1LL<<60)-1;
	while(!q.empty()) {
		auto pr = q.front();
		q.pop();
		int x = pr.first;
		int y = pr.second;
		for (int d = 0;d < 4; ++d) {
			int nx= x+dx[d];
			int ny=y+dy[d];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] >= 0) {
				if (dis[nx][ny] > dis[x][y]+w) {
					dis[nx][ny] = dis[x][y]+w;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (sx==1 && sy==1) ans = min(ans, dis[n][m]);
	for (int i =1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] > 0 && dis[i][j] < (1LL<<60)-1) {
				res = min(res, dis[i][j]+a[i][j]);
			}
		}
	}
	return res;
}
int main() {
	cin>>n>>m>>w;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%lld", &a[i][j]);
		}
	}
	ans = (1LL<<60)-1;
	ll res1 = bfs(1, 1);
	ll res2 = bfs(n, m);
	ans = min(ans, res1+res2);
	if (ans < (1LL<<60)-1) {
		cout<<ans<<endl;
	} else {
		puts("-1");
	}
  return 0;
}
