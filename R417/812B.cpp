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
#define N 20
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
vector<string> mp;
int rows[N][2];
int dp[N][2];
int main() {
	cin>>n>>m;
	m += 2;
	mp.clear();
	memset(rows, -1, sizeof(rows));
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mp.push_back(s);
		int id=-1;
		for (int j = 0; j < m; ++j) {
			if (s[j]=='1') {
				if (id<0) rows[i][0] = j;
				id = j;
				rows[i][1] = j;
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = inf;
		}
	}
	int ans=2*inf;
	dp[n][0]=0;
	bool found=false;
	for (int i = n-1; i >= 0; --i) {
		if (rows[i][0] >= 0) {
			found=true;
			int res=2*inf;
			if (dp[i+1][0] < inf) {
				res = min(res, dp[i+1][0]+rows[i][1]);
			}
			if (dp[i+1][1] < inf) {
				res = min(res, dp[i+1][1]+m-1-rows[i][0]);
			}
			ans = res;
		}
		for (int j = 0; j < 2; ++j) {
			if (dp[i+1][j] < inf) {
				dp[i][!j] = min(dp[i][!j], dp[i+1][j] + m);
				if (rows[i][0]<0) {
					dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
				} else {
					if (j==0) {
						dp[i][j]=min(dp[i][j], dp[i+1][j]+rows[i][1]*2+1);
					} else {
						dp[i][j]=min(dp[i][j], dp[i+1][j]+2*(m-1-rows[i][0])+1);
					}
				}
			}
		}
	//	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	if (found) cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}
