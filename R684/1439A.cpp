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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<string> mat;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		mat.clear();
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mat.push_back(s);
		}
		vector<vector<int>> ans;
		ans.clear();
		for (int i = 0; i < n-2; ++i) {
			for (int j = 0; j < m-1; ++j) {
				if (mat[i][j]=='0' && mat[i][j+1]=='0') {
					continue;
				} else if (mat[i][j]=='1'&&mat[i][j+1]=='1') {
					ans.push_back({i, j, i, j+1, i+1, j});
					mat[i][j]='0';
					mat[i][j+1]='0';
					if (mat[i+1][j]=='0') mat[i+1][j]='1';
					else mat[i+1][j]='0';
				} else  {
					if (mat[i][j]=='1') {
						ans.push_back({i+1, j, i+1, j+1, i, j});
						mat[i][j]='0';
					} else {
						ans.push_back({i+1,j,i+1,j+1,i,j+1});
						mat[i][j+1]='0';
					}
					mat[i+1][j]=(mat[i+1][j]=='0'?'1':'0');
					mat[i+1][j+1]=(mat[i+1][j+1]=='0'?'1':'0');
				}
			}
		}
		for (int j = 0; j < m-1; ++j) {
			if (mat[n-2][j]=='0' && mat[n-1][j]=='0') {
				continue;
			} else if (mat[n-2][j]=='1' && mat[n-1][j]=='1') {
				ans.push_back({n-2,j,n-1,j,n-2,j+1});
				mat[n-2][j]='0';
				mat[n-1][j]='0';
				mat[n-2][j+1]=(mat[n-2][j+1]=='0'?'1':'0');
			} else {
				if (mat[n-2][j]=='1') {
					ans.push_back({n-2,j,n-2,j+1,n-1,j+1});
					mat[n-2][j]='0';
				} else {
					ans.push_back({n-1,j,n-2,j+1,n-1,j+1});
					mat[n-1][j]='0';
				}
				mat[n-2][j+1]=(mat[n-2][j+1]=='0'?'1':'0');
				mat[n-1][j+1]=(mat[n-1][j+1]=='0'?'1':'0');
			}
		}

		if (mat[n-2][m-1]=='1' && mat[n-1][m-1]=='1') {
			ans.push_back({n-2,m-2,n-1,m-2,n-2,m-1});
			ans.push_back({n-2,m-2,n-1,m-2,n-1,m-1});
		} else if (mat[n-2][m-1]=='1' || mat[n-1][m-1]=='1') {
			if (mat[n-2][m-1]=='1') {
				ans.push_back({n-2,m-2,n-1,m-2,n-2,m-1});
			} else {
				ans.push_back({n-2,m-2,n-1,m-2, n-1,m-1});
			}
			ans.push_back({n-2,m-1,n-1,m-1,n-2,m-2});
			ans.push_back({n-2,m-1,n-1,m-1,n-1,m-2});
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < 6; ++j) {
				printf("%d", ans[i][j]+1);
				if (j<5) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
