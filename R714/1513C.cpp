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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
ll dp[N];
ll dp2[10][N];
int main() {
	for (int i = 0; i <= 8; ++i) {
		dp[i] = 2;
	}
	dp[9] = 3;
	for (int i = 10; i <= 200000; ++i) {
		dp[i] = (dp[i-9] + dp[i-10]) % mod;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10-i; ++j) {
			dp2[i][j] = 1;
		}
		dp2[i][10-i] = 2;
		for (int j = 10-i+1; j <= 200000; ++j) {
			dp2[i][j] = dp[j-(10-i)];
		}
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		ll ans = 0LL;
		while(n) {
			ans = (ans + dp2[n%10][m]) % mod;
			n /= 10;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
