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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int h;
ll dp[N];
vector<string> mat;
ll pw[N];
int main() {
	memset(dp, 0LL, sizeof(dp));
	cin>>n>>m;
	mat.clear();
	pw[0] = 1LL;
	for (int i = 1; i <= n*m; ++i) {
		pw[i] = pw[i-1] * 2LL % mod2;
	}
	int tot=0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 'o') {
				tot++;
			}
		}
	}
	for (int i = 2; i <= n*m; ++i) {
		dp[i] = ((dp[i-1] + 2LL*dp[i-2]) % mod2 + pw[i-2]) % mod2;
	}
	ll ans = 0LL;
	for (int i = 0; i < n; ++i) {
		int len = 0;
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == 'o') {
				len++;
			} else {
				if (len>0) {
					ans = (ans + dp[len] * pw[tot - len] % mod2) % mod2;
				}
				len = 0;
			}
		}
		if (len > 0) ans = (ans + dp[len] * pw[tot-len] % mod2) % mod2;
	}
	for (int j = 0; j < m; ++j) {
		int len = 0;
		for (int i = 0; i < n; ++i) {
			if (mat[i][j] == 'o') {
				len++;
			} else {
				if (len>0) {
					ans = (ans + dp[len] * pw[tot - len] % mod2) % mod2;
				}
				len = 0;
			}
		}
		if (len > 0) ans = (ans + dp[len] * pw[tot-len] % mod2) % mod2;
	}
	printf("%lld\n", ans);
	return 0;
}
