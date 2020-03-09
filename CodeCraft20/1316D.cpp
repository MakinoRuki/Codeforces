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
#define N 1002
using namespace std;
typedef long long ll;
int n;
pair<int, int>mat[N][N];
vector<string> ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool update(int x, int y, int nx, int ny) {
	if (nx < 1 || nx > n || ny < 1 || ny > n) return false;
	if (mat[x][y] != mat[nx][ny]) return false;
	if (nx < x) ans[x-1][y-1] = 'U';
	else if (nx > x) ans[x-1][y-1] = 'D';
	else if (ny < y) ans[x-1][y-1] = 'L';
	else if (ny > y) ans[x-1][y-1] = 'R';
	if (ans[nx-1][ny-1] == ' ') {
		if (x > nx) ans[nx-1][ny-1] = 'D';
		else if (x < nx) ans[nx-1][ny-1] = 'U';
		else if (y < ny) ans[nx-1][ny-1] = 'L';
		else if (y > ny) ans[nx-1][ny-1] = 'R';
	}
	return true;
}
bool dfs(int x, int y, char c) {
	ans[x-1][y-1] = c;
	for (int d = 0; d < 4; ++d) {
		int nx = x+dx[d];
		int ny = y+dy[d];
		if (nx >=1 && nx<=n &&ny >= 1 && ny <= n) {
			if (mat[nx][ny] == mat[x][y] && ans[nx-1][ny-1]==' ') {
				if (nx < x && !dfs(nx, ny, 'D')) return false;
				if (nx > x && !dfs(nx, ny, 'U')) return false;
				if (ny < y && !dfs(nx, ny, 'R')) return false;
				if (ny > y && !dfs(nx, ny, 'L')) return false;
			}
		}
	}
	return true;
}
int main() {
	scanf("%d",&n);
	ans.clear();
	for (int i = 1; i <= n; ++i) {
		int x,y;
		for (int j = 1; j <= n; ++j) {
			scanf("%d%d", &x,&y);
			mat[i][j] = make_pair(x,y);
		}
		ans.push_back(string(n, ' '));
	}
	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			auto p = mat[i][j];
			int x = p.first;
			int y = p.second;
			if (x==-1 && y==-1) continue;
			if (mat[x][y].first != x || mat[x][y].second != y) {
				ok= false;
				break;
			}
			ans[x-1][y-1] = 'X';
		}
		if (!ok) break;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			auto p = mat[i][j];
			int x = p.first;
			int y = p.second;
			if (x == -1 && y == -1) {
				if (ans[i-1][j-1] != ' ') continue;
				int d;
				for (d = 0; d < 4; ++d) {
					int nx = dx[d]+i;
					int ny = j+dy[d];
					if (update(i, j, nx, ny)) break;
				}
				if (d >= 4) {
					ok = false;
					break;
				}
			} else if (ans[i-1][j-1] == 'X') {
				if (!dfs(i, j, 'X')) {
					ok = false;
					break;
				}
			}
		}
		if (!ok) break;
	}
	if (!ok) cout<<"INVALID"<<endl;
	else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (ans[i-1][j-1] == ' ') {
					ok = false;
					break;
				}
			}
		}
		if (!ok) {
			cout<<"INVALID"<<endl;
		} else {
			cout<<"VALID"<<endl;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					printf("%c",ans[i][j]);
				}
				cout<<endl;
				//cout<<ans[i]<<endl;
			}
		}
	}
	return 0;
}
