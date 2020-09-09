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
#define N 202
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, k;
string s, t;
ll dp[N][N][N];
int main() {
	cin>>n>>k;
	cin>>s>>t;
	if (t[0]==t[1]) {
		int cnt=0;
		for (int i = 0; i < n; ++i) {
			if (s[i]==t[0]) {
				cnt++;
			}
		}
		int det=n-cnt;
		det=min(det, k);
		cnt+=det;
		cout<<(cnt-1)*cnt/2<<endl;
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	dp[n][0][0] = 0;
	for (int i = n; i > 0; --i) {
		for (int j = 0; j <= k; ++j) {
			for (int j2 = 0; j2 <= n-i; ++j2) {
				if (dp[i][j][j2] <0) continue;
				if (s[i-1]==t[0]) {
					dp[i-1][j][j2] = max(dp[i-1][j][j2], dp[i][j][j2] + j2);
					if (j+1<=k) dp[i-1][j+1][j2+1] = max(dp[i-1][j+1][j2+1], dp[i][j][j2]);
				} else if (s[i-1]==t[1]) {
					dp[i-1][j][j2+1] = max(dp[i-1][j][j2+1], dp[i][j][j2]);
					if (j+1<=k) dp[i-1][j+1][j2] = max(dp[i-1][j+1][j2], dp[i][j][j2]+j2);
				} else {
					dp[i-1][j][j2] = max(dp[i-1][j][j2], dp[i][j][j2]);
					if (j+1<=k) {
						dp[i-1][j+1][j2] = max(dp[i-1][j+1][j2], dp[i][j][j2]+j2);
						dp[i-1][j+1][j2+1] = max(dp[i-1][j+1][j2+1], dp[i][j][j2]);
					}
				}
				//if (dp[1][1][2]==2) cout<<"j="<<j<<" "<<j2<<" "<<dp[i][j][j2]<<endl;
				//if (dp[0][2][2]==4) cout<<"j="<<j<<" "<<j2<<" "<<dp[i][j][j2]<<endl;
			}
		}
		// for (int j=0;j<=k; ++j) {
		// 	for (int j2=0;j2<=n; ++j2) {
		// 		cout<<i-1<<" "<<j<<" "<<j2<<" "<<dp[i-1][j][j2]<<endl;
		// 	}
		// }
	}
	ll ans=0LL;
	for (int j = 0; j <= k; ++j) {
		for (int j2=0; j2<=n; ++j2) {
			//if (dp[0][j][j2]==4) cout<<j<<" "<<j2<<endl;
			ans=max(ans, dp[0][j][j2]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
