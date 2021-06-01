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
#define M 25
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q;
ll dp[N][N];
ll s[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]);
	}
	sort(s+1, s+n+1);
	memset(dp, -1, sizeof(dp));
	for (int i = n; i >= 1; --i) {
		dp[i][i] = 0LL;
		for (int j = i+1; j <= n; ++j) {
			if (j == i+1) dp[i][j] = s[j] - s[i];
			else {
				dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + (ll)(s[j]-s[i]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
  return 0;
}
