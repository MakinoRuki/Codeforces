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
#define N 1000005
using namespace std;
typedef long long ll;
int n, m;
int a[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (n <= m) {
		bool dp[1002][1002][2];
		memset(dp, false, sizeof(dp));
		dp[0][0][0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < 2; ++k) {
					if (dp[i][j][k]) {
						dp[i+1][j][k] = true;
						dp[i+1][(j+a[i+1])%m][k|1] = true;
						//if (dp[n][0][1]) cout<<i<<" "<<j<<" "<<k<<endl;
					}
				}
			}
		}
		if (dp[n][0][1]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
	}
	return 0;
}
