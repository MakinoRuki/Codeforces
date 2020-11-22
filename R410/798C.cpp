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
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int dp[N][2];
int getgcd(int x, int y) {
	return y==0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = inf;
		}
	}
	int g = a[1];
	for (int i = 2; i <=n ;++i) {
		g=getgcd(g, a[i]);
	}
	if (g>1) {
		cout<<"YES"<<endl;
		cout<<0<<endl;
	} else {
		if (a[1]%2) {
			dp[1][1] = 0;
		} else {
			dp[1][0] = 0;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (dp[i][j]<inf) {
					if (j==0) {
						if (a[i+1]%2) {
							dp[i+1][1] = min(dp[i+1][1], dp[i][j]);
							dp[i+1][0] = min(dp[i+1][0], dp[i][j]+2);
						} else {
							dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
						}
					} else {
						int cs=(a[i+1]%2 ? 1 : 2);
						dp[i+1][0] = min(dp[i+1][0], dp[i][j]+cs);
					}
				}
			}
		}
		if (dp[n][0] < inf) {
			cout<<"YES"<<endl;
			cout<<dp[n][0]<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
