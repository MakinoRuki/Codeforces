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
#define N 105
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int n, m, sx, sy;
bool vis[N][N];
int main() {
	cin>>n>>m>>sx>>sy;
	memset(vis, false, sizeof(vis));
	vector<pii> ans;
	ans.clear();
	ans.push_back(make_pair(sx, sy));
	vis[sx][sy] = true;
	int now = 0;
	while(ans.size() < n*m) {
		int cx=sx, cy = sy;
		if (!now) {
			for (int j = sy-1; j>=1; --j) {
				if (!vis[sx][j]) {
					vis[sx][j] = true;
					ans.push_back(make_pair(sx,j));
					cy = j;
				}
			}
			for (int j = sy+1; j <= m; ++j) {
				if (!vis[sx][j]) {
					vis[sx][j] = true;
					ans.push_back(make_pair(sx, j));
					cy= j;
				}
			}
		} else {
			for (int i = sx-1; i >=1 ; --i) {
				if (!vis[i][sy]) {
					vis[i][sy] = true;
					ans.push_back(make_pair(i, sy));
					cx = i;
				}
			}
			for (int i = sx+1; i <= n; ++i) {
				if (!vis[i][sy]) {
					vis[i][sy] = true;
					ans.push_back(make_pair(i,sy));
					cx = i;
				}
			}
		}
		now = !now;
		sx = cx, sy = cy;
	}
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
