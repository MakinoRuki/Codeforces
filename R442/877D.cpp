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
#define N 1002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m,k;
vector<string> mat;
int dis[N][N];
bool vis[N][N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main() {
	cin>>n>>m>>k;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	int sx,sy;
	int ex,ey;
	scanf("%d%d%d%d", &sx,&sy,&ex,&ey);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dis[i][j]=inf;
			vis[i][j]=false;
		}
	}
	sx--;sy--;ex--;ey--;
	dis[sx][sy]=0;
	vis[sx][sy]=true;
	queue<int> q;
	q.push(sx*m+sy);
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		int x=cur/m;
		int y=cur%m;
		vis[x][y]=false;
		for (int d = 0; d < 4; ++d) {
			for (int dt=1; dt<=k; ++dt) {
				int nx=x+dx[d]*dt;
				int ny=y+dy[d]*dt;
				if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]=='.') {
					if (dis[nx][ny]>=dis[x][y]+1) {
						dis[nx][ny]=dis[x][y]+1;
						if (!vis[nx][ny]) {
							vis[nx][ny]=true;
							q.push(nx*m+ny);
						}
					} else {
						break;
					}
				} else {
					break;
				}
			}
		}
	}
	if (dis[ex][ey]>=inf) {
		cout<<-1<<endl;
	} else {
		cout<<dis[ex][ey]<<endl;
	}
	return 0;
}
