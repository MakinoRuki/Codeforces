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
#define N 602
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int dp[N][N][2][2][2];
string s;
int dfs(int p00, int p01, int mid, int rev, int p) {
	if (dp[p00][p01][mid][rev][p] > INT_MIN) {
		return dp[p00][p01][mid][rev][p];
	}
	if (!p00 && !p01 && mid) {
		return dp[p00][p01][mid][rev][p] = 0;
	}
	int res1 = INT_MAX;
	int res2 = INT_MIN;
	if (p00 > 0) {
		res1 = min(res1, dfs(p00-1, p01+1, mid, 0, !p)+1);
		res2 = max(res2, dfs(p00-1, p01+1, mid, 0, !p)-1);
	}
	if (p01 > 0) {
		res1 = min(res1, dfs(p00, p01-1, mid, 0, !p)+1);
		res2 = max(res2, dfs(p00, p01-1, mid, 0, !p)-1);
	}
	if (!mid) {
		res1 = min(res1, dfs(p00, p01, !mid, 0, !p)+1);
		res2 = max(res2, dfs(p00, p01, !mid, 0, !p)-1);
	}
	if (p01 && !rev) {
		res1 = min(res1, dfs(p00, p01, mid, 1, !p));
		res2 = max(res2, dfs(p00, p01, mid, 1, !p));
	}
	if (!p) return dp[p00][p01][mid][rev][p] = res1;
	return dp[p00][p01][mid][rev][p] = res2;
}
int main() {
	for (int i = 0; i <= 600; ++i) {
		for (int j = 0; j <= 600; ++j) {
			for (int k1 = 0; k1 < 2; ++k1) {
				for (int k2 = 0; k2 < 2; ++k2) {
					for (int k3 = 0; k3 < 2; ++k3) {
						dp[i][j][k1][k2][k3] = INT_MIN;
					}
				}
			}
		}
	}
	for (int i = 0; i <= 600; ++i) {
		for (int j = 0; j <= 600; ++j) {
			for (int k1 = 0; k1 < 2; ++k1) {
				for (int k2 = 0; k2 < 2; ++k2) {
					for (int k3 = 0; k3 < 2; ++k3) {
						if (dp[i][j][k1][k2][k3] <= INT_MIN) {
							dfs(i, j, k1, k2, k3);
						}
					}
				}
			}
		}
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		cin>>s;
		int l = 0, r = n-1;
		int p00=0,p01=0;
		while(l < r) {
			if (s[l] == '0' && s[r] == '0') {
				p00++;
				l++;
				r--;
			} else if (!(s[l]=='1' && s[r]=='1')) {
				p01++;
				l++;
				r--;
			} else {
				l++;
				r--;
			}
		}
		int mid=1;
		if (l == r && s[l] == '0') {
			mid = 0;
		}
		int res= dp[p00][p01][mid][0][0];
		if (res < 0) puts("ALICE");
		else if (res > 0) puts("BOB");
		else puts("DRAW");
	}
  return 0;
}
