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
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<int> edges[N];
int a[N];
int dp[N][M];
int getgcd(int x, int y) {
	if (y == 0) return x;
	return getgcd(y, x%y);
}
int getres(int st, int len) {
	int g = -1;
	for (int i = 20; i >= 0; --i) {
		if ((1<<i) <= len) {
			if (g < 0) g = dp[st][i];
			else {
				g = getgcd(g, dp[st][i]);
			}
			st += (1<<i);
			len -= (1<<i);
		}
	}
	return g;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			a[n+i] = a[i];
		}
		for (int i = 1; i <= 2*n; ++i) {
			dp[i][0] = a[i];
			for (int j = 1; j <= 20; ++j) {
				dp[i][j] = -1;
			}
		}
		for (int i = 1; i <= 20; ++i) {
			for (int j = 1; j <= 2*n; ++j) {
				if (dp[j][i-1]>0 && dp[j+(1<<(i-1))][i-1]>0) {
					dp[j][i] = getgcd(dp[j][i-1], dp[j+(1<<(i-1))][i-1]);
				}
			}
		}
	//	cout<<dp[n][0]<<" "<<dp[n][1]<<" "<<dp[n][2]<<" "<<getres(n, 4)<<endl;
		int l = 0, r = n;
		while(l < r) {
			int mid = (l+r)/2;
		//	cout<<l<<" "<<r<<" "<<mid<<endl;
			int g = -1;
			int i;
			for (i = 1; i <= n; ++i) {
				int g1 = getres(i, mid+1);
				if (g < 0) g = g1;
				else if (g1 != g) break;
			}
			if (i > n) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("%d\n", r);
	}
  return 0;
}
