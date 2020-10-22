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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
int m;
int dp[2][N];
int sum[N];
int la[N], lb[N];
int main() {
	cin>>n>>s>>m;
	memset(la, 0, sizeof(la));
	memset(lb, 0, sizeof(lb));
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + (s[i-1]=='?');
		if (s[i-1]!='b') {
			la[i] = lb[i-1]+1;
		}
		if (s[i-1] != 'a') {
			lb[i] = la[i-1]+1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[0][i] = dp[0][i-1];
		dp[1][i] = dp[1][i-1];
		if ((m%2==0 && lb[i]>=m) || (m%2 && la[i]>=m)) {
			if (dp[0][i-m]+1>dp[0][i]) {
				dp[0][i]=dp[0][i-m]+1;
				dp[1][i]=dp[1][i-m]+sum[i]-sum[i-m];
			} else if (dp[0][i-m]+1==dp[0][i]) {
				dp[1][i]=min(dp[1][i], dp[1][i-m]+sum[i]-sum[i-m]);
			}
			// dp[0][i]=max(dp[0][i], dp[0][i-m]+1);
			// if (dp[0][i]>dp[0][i-1]) {
			// 	dp[1][i] = dp[1][i-m] + sum[i]-sum[i-m];
			// } else if (dp[0][i]==dp[0][i-1]) {
			// 	dp[1][i] = min(dp[1][i-1], dp[1][i-m]+sum[i]-sum[i-m]);
			// }
		}
	}
	//cout<<dp[0][9]<<" "<<dp[1][9]<<endl;
	//cout<<dp[0][n]<<endl;
	cout<<dp[1][n]<<endl;
	return 0;
}
