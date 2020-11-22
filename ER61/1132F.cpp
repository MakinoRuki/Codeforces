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
int n;
string s;
int dp[N][N];
int main() {
	cin>>n>>s;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (i<=j) dp[i][j]=inf;
			else dp[i][j]=0;
		}
	}
	for (int i = n; i >= 1; --i) {
		dp[i][i]=1;
		for (int j = i+1; j <= n; ++j) {
			dp[i][j]=min(dp[i][j], dp[i+1][j]+1);
			for (int k = i+1; k <= j; ++k) {
				if (s[i-1]==s[k-1]) {
					dp[i][j]=min(dp[i][j], dp[i][k-1]+dp[k+1][j]);
				} else {
					dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
