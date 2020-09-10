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
#define N 1005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
vector<string> mat;
bool vis[N][N];
int main() {
	cin>>n>>m;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i+3>n || j+3>m) {
				continue;
			}
			bool ok=true;
			for (int k1=0; k1<3; ++k1) {
				for (int k2=0; k2<3; ++k2) {
					if (k1==1 && k2==1) continue;
					if (mat[i+k1][j+k2] == '.') {
						ok=false;
						break;
					}
				}
			}
		//	if (i==0 && j==0) cout<<"ok="<<ok<<endl;
			if (ok) {
				for (int k1=0; k1<3; ++k1) {
					for (int k2=0; k2 < 3; ++k2) {
						if (k1==1 && k2==1) continue;
						vis[i+k1][j+k2]=true;
					}
				}
			}
		}
	}
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
		//	cout<<mat[i][j]<<" "<<vis[i][j]<<endl;
			if (mat[i][j]=='#' && !vis[i][j]) {
				ok=false;
				break;
			}
			if (mat[i][j]=='.' && vis[i][j]) {
				ok=false;
				break;
			}
		}
		if (!ok) break;
	}
	if (ok) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
