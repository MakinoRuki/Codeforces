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
int r, g, b;
vector<int> rl, gl, bl;
ll dp[N][N][N];
int main() {
	cin>>r>>g>>b;
	rl.clear();
	gl.clear();
	bl.clear();
	for (int i = 1; i <= r; ++i) {
		int x;
		scanf("%d", &x);
		rl.push_back(x);
	}
	for (int i = 1; i <= g; ++i) {
		int x;
		scanf("%d", &x);
		gl.push_back(x);
	}
	for (int i = 1; i <= b; ++i) {
		int x;
		scanf("%d", &x);
		bl.push_back(x);
	}
	sort(rl.begin(), rl.end());
	reverse(rl.begin(), rl.end());
	sort(gl.begin(), gl.end());
	reverse(gl.begin(), gl.end());
	sort(bl.begin(), bl.end());
	reverse(bl.begin(), bl.end());
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	ll ans = 0LL;
	for (int i = 0; i <= r; ++i) {
		for (int j = 0; j <= g; ++j) {
			for (int k = 0; k <= b; ++k) {
				if (dp[i][j][k] >= 0) {
					ans = max(ans, dp[i][j][k]);
					if (i+1<=r && j+1<=g) {
						dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+(ll)rl[i]*(ll)gl[j]);
					}
					if (i+1<=r && k+1<=b) {
						dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]+(ll)rl[i]*(ll)bl[k]);
					}
					if (j+1<=g && k+1<=b) {
						dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k]+(ll)gl[j]*(ll)bl[k]);
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
