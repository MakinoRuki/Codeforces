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
#define M 31
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
vector<pair<int,int>> ids[2][3];
vector<string> mat;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		mat.clear();
		int tot=0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				ids[i][j].clear();
			}
		}
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 'O') {
					tot++;
					ids[0][(i+j)%3].push_back(make_pair(i,j));
				} else if (mat[i][j]=='X') {
					tot++;
					ids[1][(i+j)%3].push_back(make_pair(i,j));
				}
			}
		}
		bool found=false;
		for (int r1= 0;r1<3; ++r1) {
			for (int r2=0;r2<3; ++r2) {
				if (r1!=r2) {
					if (ids[0][r1].size() + ids[1][r2].size() <= tot/3) {
						found=true;
						for (int i = 0; i < ids[0][r1].size(); ++i) {
							int x=ids[0][r1][i].first;
							int y=ids[0][r1][i].second;
							mat[x][y] = 'X';
						}
						for (int i = 0; i < ids[1][r2].size(); ++i) {
							int x=ids[1][r2][i].first;
							int y=ids[1][r2][i].second;
							mat[x][y] = 'O';
						}
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		for (int i = 0; i < n; ++i) {
			cout<<mat[i]<<endl;
		}
	}
	return 0;
}
