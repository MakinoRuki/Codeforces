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
#define N 52
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int r1,c1, r2, c2;
int mat[N][N];
bool can[2][N*N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs(int r, int c, int f) {
	memset(can[f], false, sizeof(can[f]));
	can[f][r*n+c] = true;
	queue<int> q;
	q.push(r*n+c);
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		int x = cur/n;
		int y = cur%n;
		for (int d = 0; d < 4; ++d) {
			int nx = x+dx[d];
			int ny = y+dy[d];
			if (nx>=0 && nx < n && ny >= 0 && ny < n && !mat[nx][ny]) {
				if (!can[f][nx*n+ny]) {
					can[f][nx*n+ny] = true;
					q.push(nx*n+ny);
				}
			}
		}
	}
}
int main() {
	cin>>n>>r1>>c1>>r2>>c2;
	memset(mat, false, sizeof(mat));
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		for (int j = 0; j < n; ++j) {
			mat[i][j] = s[j]-'0';
		}
	}
//	cout<<"ok"<<endl;
	bfs(r1-1, c1-1, 0);
//	cout<<"ok1"<<endl;
	bfs(r2-1, c2-1, 1);
//	cout<<"ok2"<<endl;
	r1--;
	c1--;
	r2--;
	c2--;
	bool found=false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (can[0][i*n+j] && can[1][i*n+j]) {
				found=true;
				break;
			}
		}
	}
	if (found) {
		cout<<0<<endl;
		return 0;
	}
	int ans=inf;
	for (int a1 = 0; a1 < n; ++a1) {
		for (int b1 = 0; b1 < n; ++b1) {
			for (int a2 = 0; a2 < n; ++a2) {
				for (int b2 = 0; b2 < n; ++b2) {
					if (a1 == a2 && b1 == b2) continue;
					if ((can[0][a1*n+b1] && can[1][a2*n+b2])||(can[1][a1*n+b1]&&can[0][a2*n+b2])) {
						int dis = (a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
						ans = min(ans, dis);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
  return 0;
}
