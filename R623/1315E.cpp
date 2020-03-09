#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n, k;
int b[N];
ll dp[N][18][2][2];
int main() {
	cin>>n>>k;
	memset(b, false, sizeof(b));
	for (int i = 1; i <= k; ++i) {
		int a;
		cin>>a;
		b[a] = true;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= (1<<n); j += (1<<i)) {
			if (i == 1) {
				for (int k1 = 0;k1<2;++k1) {
					for (int k2=0;k2<2; ++k2) {
						if (k1+k2 != b[j]+b[j+1]) continue;
						dp[j][i][k1][k2] = (b[j]||b[j+1]);
					}
				}
			} else {
				for (int x1=0;x1<2; ++x1) {
					for (int y1=0; y1<2; ++y1) {
						for (int x2= 0; x2 <2; ++x2) {
							for (int y2=0; y2<2; ++y2) {
								int j2 = j+(1<<(i-1));
								if (dp[j][i-1][x1][y1] < 0 || dp[j2][i-1][x2][y2]<0) continue;
								ll tmp = dp[j][i-1][x1][y1] + dp[j2][i-1][x2][y2];
								if (x1||x2) tmp++;
								if (y1||y2) tmp++;
								ll t1 = (x2||y1);
								dp[j][i][x1][x2] = max(dp[j][i][x1][x2], tmp+t1);
								dp[j][i][x1][y1] = max(dp[j][i][x1][y1], tmp+t1);
								t1 = (x2||y2);
								dp[j][i][x1][x2] = max(dp[j][i][x1][x2], tmp+t1);
								dp[j][i][x1][y2] = max(dp[j][i][x1][y2], tmp+t1);
								t1 = (x1||y2);
								dp[j][i][x2][x1] = max(dp[j][i][x2][x1], tmp+t1);
								dp[j][i][x2][y2] = max(dp[j][i][x2][y2], tmp+t1);
								t1 = (x1||y1);
								dp[j][i][x2][x1] = max(dp[j][i][x2][x1], tmp+t1);
								dp[j][i][x2][y1] = max(dp[j][i][x2][y1], tmp+t1);
							}
						}
					}
				}
			}
		}
	}
	ll ans = 0LL;
	for (int k1 = 0; k1 < 2; ++k1) {
		for (int k2=0; k2<2; ++k2) {
			ans = max(ans, dp[1][n][k1][k2] + (k1||k2));
		}
	}
	cout<<ans<<endl;
	return 0;
}
