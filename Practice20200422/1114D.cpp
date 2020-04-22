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
#define N 5002
using namespace std;
typedef long long ll;
string s, t;
int n;
int c[N];
int dp[N][N];
int l[N], r[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i >= j) dp[i][j] = 0;
			else dp[i][j] = 1000000000;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i == 1) l[i] = i;
		else {
			if (c[i] == c[i-1]) l[i] = l[i-1];
			else l[i]= i;
		}
	}
	for (int i = n; i >= 1; --i) {
		if (i==n) r[i] = i;
		else {
			if (c[i] == c[i+1]) r[i] = r[i+1];
			else r[i] = i;
		}
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
	// }
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			if (i==j) dp[i][j] = 0;
			else {
				if (r[i] >= j || l[j] <= i) dp[i][j] = 0;
				else {
					dp[i][j] = min(dp[i][j], dp[r[i]+1][j]+1);
					dp[i][j] = min(dp[i][j], dp[i][l[j]-1]+1);
					if (c[i]==c[j]) {
						dp[i][j] = min(dp[i][j], dp[r[i]+1][l[j]-1]+1);
					}
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
