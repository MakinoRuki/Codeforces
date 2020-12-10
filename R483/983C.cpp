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
#define M 20005
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
int a[N], b[N];
int cnt;
int idx[10][10][10][10];
vector<vector<int>> st;
int dp[N][720][10];
bool vis[N][720][10];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	cnt=0;
	memset(idx, -1, sizeof(idx));
	st.clear();
	for (int a = 0; a < 10; ++a) {
		for (int b = a; b < 10; ++b) {
			for (int c = b; c < 10; ++c) {
				for (int d = c; d < 10; ++d) {
					idx[a][b][c][d] = ++cnt;
					st.push_back({a,b,c,d});
				}
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= 716; ++j) {
			for (int s = 1; s < 10; ++s) {
				dp[i][j][s] = inf;
			}
		}
	}
	dp[0][1][1] = 0;
	memset(vis, false, sizeof(vis));
	vis[0][1][1] = true;
	queue<pair<int, pair<int,int>>> q;
	q.push(make_pair(0, make_pair(1,1)));
	while(!q.empty()) {
		auto cur=q.front();
		q.pop();
		int x = cur.first;
		int id = cur.second.first;
		if (x >= n && id == 1) continue;
		vector<int> sv = st[id-1];
		int l = cur.second.second;
		vis[x][id][l] = false;
		for (int l2 = 1; l2 <= 9; ++l2) {
		//	if (l2 == l) continue;
			if (a[x+1] != l2 && sv[0] != l2 && sv[1] != l2 && sv[2] != l2 && sv[3] != l2) {
				continue;
			}
	//		cout<<l<<" "<<l2<<endl;
			int cst = abs(l-l2);
			vector<int> sv2;
			for (int i = 0; i < 4; ++i) {
				if (sv[i] == 0) continue;
				if (sv[i] != l2) {
					sv2.push_back(sv[i]);
				} else {
					cst++;
				}
			}
			int y = x;
			while(y+1 <= n && a[y+1] == l2 && sv2.size() < 4) {
				sv2.push_back(b[y+1]);
				y++;
				cst++;
			}
			while(sv2.size()<4) sv2.push_back(0);
			sort(sv2.begin(), sv2.end());
			int id2 = idx[sv2[0]][sv2[1]][sv2[2]][sv2[3]];
		//	cout<<"y="<<y<<" "<<"id2="<<id2<<endl;
			if (y > x || id2 != id) {
				if (dp[y][id2][l2] > dp[x][id][l]+cst) {
					dp[y][id2][l2] = dp[x][id][l] + cst;
					if (!vis[y][id2][l2]) {
			//			cout<<"st="<<y<<" "<<id2<<" "<<l2<<" "<<dp[y][id2][l2]<<endl;
						vis[y][id2][l2]=true;
						q.push(make_pair(y, make_pair(id2, l2)));
					}
				}
			}
		}
	}
	int ans = inf;
	for (int l = 1; l <= 9; ++l) {
		ans = min(ans, dp[n][1][l]);
	}
	cout<<ans<<endl;
	return 0;
}
