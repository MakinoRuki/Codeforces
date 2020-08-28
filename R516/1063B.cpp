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
#define N 2002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int mat[N][N];
int r, c;
int x, y;
int dis[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[N][N];
int main() {
	cin>>n>>m>>r>>c>>x>>y;
	r--;
	c--;
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '*') {
				mat[i][j] = 1;
			}
		}
	}
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dis[i][j] = inf+1;
		}
	}
	dis[r][c] = 0;
	vis[r][c] = true;
	queue<int> q;
	q.push(r*m+c);
	while(!q.empty()) {
		int cur= q.front();
		q.pop();
		int cr=cur/m;
		int cc=cur%m;
		vis[cr][cc] = false;
		for (int d = 0; d < 4; ++d) {
			int nx=cr+dx[d];
			int ny=cc+dy[d];
			if (nx>=0 && nx<n &&ny>=0 &&ny<m && !mat[nx][ny]) {
				int det = 0;
				if (d==2) det++;
				if (dis[cr][cc]+det<dis[nx][ny]) {
					dis[nx][ny] = dis[cr][cc]+det;
					if (!vis[nx][ny]) {
						vis[nx][ny] = true;
						q.push(nx*m+ny);
					}
				}
			}
		}
	}
	int tot=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!mat[i][j] && dis[i][j] <= x && j-c+dis[i][j]<=y) {
				tot++;
			}
		}
	}
	printf("%d\n", tot);
	return 0;
}
