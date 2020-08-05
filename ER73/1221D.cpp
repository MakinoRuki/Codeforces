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
#define N 300005
#define M 1000005
#define inf 1000000000
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q, n;
ll a[N], b[N];
ll dp[N][3];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld", &a[i], &b[i]);
		}
		dp[1][0] = 0;
		dp[1][1] = b[1];
		dp[1][2] = 2LL*b[1];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i+1][j] = 1LL<<61;
			}
			for (int j = 0; j < 3; ++j) {
				for (int k = 0; k < 3; ++k) {
					if (a[i]+j != a[i+1]+k && dp[i][j] < (1LL<<61)) {
						dp[i+1][k] = min(dp[i+1][k], dp[i][j]+k*b[i+1]);
					}
				}
			}
		}
		ll ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
		cout<<ans<<endl;
	}
  return 0;
}
