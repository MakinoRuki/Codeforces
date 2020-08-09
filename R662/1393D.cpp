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
#define N 2005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<string> mat;
int lm[N][N], rm[N][N];
int dp[2][N][N];
int main() {
	cin>>n>>m;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	memset(lm, 0, sizeof(lm));
	memset(rm, 0, sizeof(rm));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			if (mat[i-1][j-1] == mat[i-1][j-2]) {
				lm[i][j] = lm[i][j-1]+1;
			}
		}
		for (int j = m-1; j >= 1; --j) {
			if (mat[i-1][j-1] == mat[i-1][j]) {
				rm[i][j] = rm[i][j+1]+1;
			}
		}
	}
	ll ans = 0LL;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (i==1 || mat[i-1][j-1] != mat[i-2][j-1]) {
				dp[0][i][j] = 1;
			} else {
				int x = dp[0][i-1][j];
				int s = 2*min(lm[i][j], rm[i][j])+1;
				s = s/2+1;
				dp[0][i][j] = min(x+1, s);
			}
		}
		for (int i = n; i >= 1; --i) {
			if (i==n || mat[i-1][j-1] != mat[i][j-1]) {
				dp[1][i][j] = 1;
			} else {
				int x = dp[1][i+1][j];
				int s = 2*min(lm[i][j], rm[i][j])+1;
				s = s/2+1;
				dp[1][i][j] = min(x+1, s);
			}
		}
		// if (j==3) {
		// 	cout<<"dp="<<dp[0][3][3]<<" "<<dp[1][3][3]<<endl;
		// }
		for (int i = 1; i <= n; ++i) {
			int cur = min(dp[0][i][j], dp[1][i][j]);
			ans += (ll)cur;
		}
	}
	cout<<ans<<endl;
	return 0;
}
