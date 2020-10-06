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
#include <queue>
#include <cmath>
#define N 10002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll w,b,x;
int c[N];
ll cost[N];
ll dp[1002][N];
int main() {
	cin>>n>>w>>b>>x;
	int totc=0;
	for (int i =1 ; i <= n; ++i) {
		scanf("%d", &c[i]);
		totc+=c[i];
	}
	for (int i =1 ; i <= n; ++i) {
		scanf("%lld", &cost[i]);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= totc; ++j) {
			dp[i][j]=-1;
		}
	}
	dp[1][0]=w;
	for (int i = 1; i <= c[1]; ++i) {
		if (i*cost[1] <= w) {
			dp[1][i] = max(dp[1][i], dp[1][i-1]-cost[1]);
		}
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= totc; ++j) {
			if (dp[i-1][j]>=0) {
				dp[i][j] = max(dp[i][j], min(w+b*j, dp[i-1][j]+x));
				ll rem=min(w+b*j, dp[i-1][j]+x);
				for (int j2=1; j2<=c[i]; ++j2) {
					if (rem >= j2*cost[i]) {
						dp[i][j+j2] = max(dp[i][j+j2], rem-j2*cost[i]);
					//	if (i==2 && j+j2==7) cout<<i<<" "<<j<<" "<<j2<<" "<<dp[i-1][j]<<" "<<rem<<endl;
					}
				}
				//if (dp[2][7]>=0) cout<<i<<" "<<j<<" "<<dp[i-1][3]<<endl;
			}
		}
	}
	for (int i = totc; i>=0; --i) {
		if (dp[n][i]>=0) {
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
