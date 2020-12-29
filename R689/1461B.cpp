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
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
vector<string> mat;
int dp[N][N];
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
		int ans=0;
		for (int i = 0; i < n; ++i) {
			int ln[N], rn[N];
			for (int j = 0; j < m; ++j) {
				ln[j] = 0;
				rn[j] = 0;
			}
			for (int j = 0; j < m; ++j) {
				if (mat[i][j]=='*') {
					ln[j] = 1;
					if (j-1>=0) ln[j] += ln[j-1];
				}
			}
			for (int j = m-1; j >= 0; --j) {
				if (mat[i][j]=='*') {
					rn[j] = 1;
					if (j+1<m) rn[j] += rn[j+1];
				}
			}
			for (int j = 0; j < m; ++j) {
				dp[i][j] = 0;
				if (mat[i][j] == '*') {
					dp[i][j] = min(ln[j], rn[j]);
			//		cout<<i<<" "<<j<<" "<<ln[j]<<" "<<rn[j]<<" "<<dp[i][j]<<endl;
					if (i-1>=0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
					else dp[i][j] = 1;
					ans += dp[i][j];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
