#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#define M 1000005
#define N 500005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
vector<string> mat;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool check(int x, int y) {
	int cnt=0;
	for (int d = 0; d < 4; ++d) {
		int nx=x+dx[d];
		int ny=y+dy[d];
		if (nx>=0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.') {
			cnt++;
		}
	}
	return cnt<=1;
}
void bfs(int x, int y) {
	queue<int> q;
	q.push(x*m+y);
	while(!q.empty()) {
		auto u = q.front();
		q.pop();
		int x = u/m;
		int y = u%m;
		for (int d = 0; d < 4; ++d) {
			int nx = x+dx[d];
			int ny = y+dy[d];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '.' && check(nx, ny)) {
				mat[nx][ny] = '+';
				q.push(nx*m+ny);
			}
		}
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		mat.clear();
		int sx, sy;
		string s;
		getline(cin, s);
		for (int i = 1; i <= n; ++i) {
		//	cin>>s;
			getline(cin, s);
		//	cout<<"s="<<s<<endl;
			mat.push_back(s);
			for (int j = 0; j < m; ++j) {
				// char c;
				// scanf("%c", &c);
				if (s[j] == 'L') {
					sx = i-1;
					sy = j;
				}
				//mat[i-1].push_back(c);
			}
			// char c;
			// scanf("%c", &c);
		}
	//	cout<<"??"<<endl;
		bfs(sx, sy);
		for (int i = 0; i < mat.size(); ++i) {
			for (int j = 0; j < mat[i].size(); ++j) {
				printf("%c", mat[i][j]);
			}
			puts("");
		}
	}
  return 0;
}

