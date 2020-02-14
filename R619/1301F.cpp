#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1002
using namespace std;
int n,m,k;
int col[N][N];
int q;
int dis[42][N][N];
vector<pair<int,int>> ps[42];
bool has[42];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};
void bfs(int c) {
	queue<pair<int,int>> q;
	for (int i = 0; i < ps[c].size(); ++i) {
		int x = ps[c][i].first;
		int y = ps[c][i].second;
		dis[c][x][y] = 0;
		q.push(make_pair(x,y));
	}
	memset(has, false, sizeof(has));
	has[c] = true;
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first;
		int y = cur.second;
		if (!has[col[x][y]]) {
			has[col[x][y]] = true;
			int nc = col[x][y];
			for (int i = 0; i < ps[nc].size(); ++i) {
				int nx = ps[nc][i].first;
				int ny = ps[nc][i].second;
				if (dis[c][nx][ny] < 0) {
					dis[c][nx][ny] = dis[c][x][y]+1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		for (int d= 0; d < 4; ++d) {
			int nx = dx[d] + x;
			int ny = dy[d] + y;
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (dis[c][nx][ny] < 0) {
					dis[c][nx][ny] = dis[c][x][y]+1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin>>col[i][j];
			ps[col[i][j]].push_back(make_pair(i,j));
		}
	}
	memset(dis, -1, sizeof(dis));
	for (int i = 1; i <= k; ++i) {
		bfs(i);
	}
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		int r1, c1, r2, c2;
		cin>>r1>>c1>>r2>>c2;
		int ans = abs(r1-r2) + abs(c1-c2);
		for (int j = 1; j <= k; ++j) {
			if (dis[j][r1][c1] >= 0 && dis[j][r2][c2] >= 0) {
				ans = min(ans, dis[j][r1][c1] + dis[j][r2][c2] + 1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
