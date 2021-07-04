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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 505
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
ll dp[N][N*2][2];
int main() {
	cin>>n;
	vector<pair<int,ll>> op;
	op.clear();
	for (int i = 1; i <= n; ++i) {
		string s;
		cin>>s;
		if (s[0]=='-') {
			op.push_back(make_pair(-1,0));
		} else {
			ll x;
			scanf("%lld", &x);
			op.push_back(make_pair(1,x));
		}
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		if (op[i-1].first == 1) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= n; ++k) {
					dp[j][k][0] = 0LL;
					dp[j][k][1] = 0LL;
				}
			}
			dp[0][0][0] = 1LL;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k <= n; ++k) {
					// for (int k2 = 0; k2 < 2; ++k2) {
					// 	if (j < i && k2 == 1) continue;
					// 	if (j >= i && k2 == 0) continue;
					 	if (j+1<i) {
					 		dp[j+1][k][0] = (dp[j+1][k][0] + dp[j][k][0]) % mod2;
							if (op[j].first == 1) {
								if (op[j].second < op[i-1].second) {
									dp[j+1][k+1][0] = (dp[j+1][k+1][0]+dp[j][k][0])%mod2;
								} else {
									dp[j+1][k][0] = (dp[j+1][k][0]+dp[j][k][0])%mod2;
								}
							} else {
								dp[j+1][max(k-1,0)][0] = (dp[j+1][max(k-1,0)][0] + dp[j][k][0])%mod2;
							}
						} else if (j+1==i) {
							dp[j+1][k+1][1] = (dp[j+1][k+1][1] + dp[j][k][0]) % mod2;
						} else {
							dp[j+1][k][1] = (dp[j+1][k][1] + dp[j][k][1]) % mod2;
							if (op[j].first== 1) {
								if (op[j].second <= op[i-1].second) {
									dp[j+1][k+1][1] = (dp[j+1][k+1][1]+dp[j][k][1])%mod2;
								} else {
									dp[j+1][k][1] = (dp[j+1][k][1]+dp[j][k][1])%mod2;
								}
							} else {
								if (k-1>0) {
									dp[j+1][k-1][1] = (dp[j+1][k-1][1]+dp[j][k][1])%mod2;
								}
							}
						}
					//}
				}
			}
		//	cout<<"i="<<i<<endl;
			for (int k = 1; k <= n; ++k) {
			//	cout<<k<<" "<<dp[n][k][1]<<endl;
				ans = (ans + dp[n][k][1]*op[i-1].second%mod2)%mod2;
			}
		}
	}
	printf("%lld\n", ans);
  return 0;
}
