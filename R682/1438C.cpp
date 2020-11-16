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
#define N 500
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,m;
int a[N][N];
int dx[4] = {-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n,&m);
		map<int, vector<pair<int,int>>> mp;
		mp.clear();
		for (int i =0 ; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				mp[a[i][j]].push_back(make_pair(i,j));
			}
		}
		int now=0;
		for (auto itr : mp) {
			auto vs=itr.second;
			if (!vs.empty()) {
				int c1=0,c0=0;
				for (int i = 0; i < vs.size(); ++i) {
					int x=vs[i].first;
					int y=vs[i].second;
					if ((x+y)%2==0) {
						c0++;
					} else {
						c1++;
					}
				}
				if (c0>0 && c1>0) {
					for (int i = 0; i < vs.size(); ++i) {
						int x=vs[i].first;
						int y=vs[i].second;
						if ((x+y)%2==now) {
							a[x][y]++;
							mp[a[x][y]].push_back(make_pair(x, y));
						}
					}
				}
			}
			now ^= 1;
		}
		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < m; ++j) {
		// 		if (i-1>=0 && a[i-1][j]==a[i][j]) {
		// 			a[i][j]++;
		// 		} else if (j-1>=0 && a[i][j-1]==a[i][j]) {
		// 			a[i][j]++;
		// 		}
		// 	}
		// }
		// queue<int> q;
		// int vis[N][N];
		// int vis2[N][N];
		// for (int i = 0; i <= n; ++i) {
		// 	for (int j = 0; j <= m; ++j) {
		// 		vis[i][j]=false;
		// 		vis2[i][j]=false;
		// 	}
		// }
		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < m; ++j) {
		// 		int d;
		// 		for (d = 0; d < 4; ++d) {
		// 			int ni=dx[d]+i;
		// 			int nj=dy[d]+j;
		// 			if (ni>=0 && ni < n && nj>=0 && nj<m && a[ni][nj]==a[i][j]) {
		// 				break;
		// 			}
		// 		}
		// 		if (d < 4) {
		// 			q.push(i*m+j);
		// 			vis[i][j]=true;
		// 		}
		// 	}
		// }
		// while(!q.empty()) {
		// 	int cur=q.front();
		// 	q.pop();
		// 	int x=cur/m;
		// 	int y=cur%m;
		// 	int d;
		// 	bool f1=false,f2=false;
		// 	for (d = 0; d < 4; ++d) {
		// 		int nx=x+dx[d];
		// 		int ny=y+dy[d];
		// 		if (nx>=0 && nx < n && ny>=0 && ny < m) {
		// 			if (a[nx][ny]==a[x][y]) {
		// 				f1=true;
		// 			}
		// 			if (a[nx][ny]==a[x][y]+1 && vis2[nx][ny]) {
		// 				f2=true;
		// 			}
		// 		}
		// 	}
		// 	if (f1 && !f2) {
		// 		a[x][y]++;
		// 		vis2[x][y]=true;
		// 		for (int d2=0;d2<4; ++d2) {
		// 			int nx=x+dx[d2];
		// 			int ny=y+dy[d2];
		// 			if (nx>=0 && nx < n && ny>=0 && ny < m && a[nx][ny]==a[x][y]) {
		// 				if (!vis[nx][ny]) {
		// 					q.push(nx*m+ny);
		// 					vis[nx][ny]=true;
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		for (int i = 0; i < n; ++i) {
			for (int j =0; j < m; ++j) {
				printf("%d", a[i][j]);
				if (j < m-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
