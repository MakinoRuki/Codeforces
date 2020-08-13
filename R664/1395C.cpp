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
#define N 205
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int n, m;
int a[N], b[N];
bool dp[N][1<<9];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
	}
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1<<9); ++j) {
			if (dp[i][j]) {
				for (int k = 1; k <= m; ++k) {
					dp[i+1][(a[i+1]&b[k])|j] = true;
				}
			}
		}
	}
	for (int i = 0; i < (1<<9); ++i) {
		if (dp[n][i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
