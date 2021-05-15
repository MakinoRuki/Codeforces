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
#define M 52
#define N 102
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int dp[N][N][27][2];
vector<pair<int,int>> edges[N];
bool ans[N][N];
int dfs(int x, int y, int pre, int p) {
	if (dp[x][y][pre][p] >= 0) {
		return dp[x][y][pre][p];
	}
	bool res=true;
	bool found=false;
	if (!p) {
		for (int i = 0; i < edges[x].size(); ++i) {
			if (edges[x][i].second >= pre) {
				found=true;
				res &= dfs(edges[x][i].first, y, edges[x][i].second, !p);
			}
		}
	} else {
		for (int i = 0; i < edges[y].size(); ++i) {
			if (edges[y][i].second >= pre) {
				found=true;
				res &= dfs(x, edges[y][i].first, edges[y][i].second, !p);
			}
		}
	}
	if (!found) return dp[x][y][pre][p] = 0;
	if (res) return dp[x][y][pre][p] = 0;
	else return dp[x][y][pre][p] = 1;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		string c;
		scanf("%d%d", &u, &v);
		cin>>c;
		edges[u].push_back(make_pair(v, c[0]-'a'+1));
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k <= 26; ++k) {
				for (int p = 0; p < 2; ++p) {
					if (dp[i][j][k][p] < 0) dfs(i, j, k, p);
				}
			}
		}
	}
//	cout<<dp[1][1][0][0]<<" "<<dp[2][1][2][1]<<endl;
	for (int i = 1; i <= n; ++i) {
		string res="";
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j][0][0] == 1) {
				res.push_back('A');
			} else {
				res.push_back('B');
			}
		}
		cout<<res<<endl;
	}
  return 0;
}
