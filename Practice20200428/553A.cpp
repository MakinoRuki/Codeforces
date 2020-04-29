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
#define N 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int c[N];
ll dp[N];
ll comb[N][N];
int main() {
	cin>>k;
	n=0;
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &c[i]);
		n += c[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; ++i) {
		comb[i][0] = 1LL;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[1] = 1LL;
	ll sum = c[1];
	for (int i = 2; i <= k; ++i) {
		dp[i] = dp[i-1]*comb[sum+c[i]-1][sum] % mod;
	//	cout<<"i="<<i<<" "<<dp[i-1]<<" "<<sum<<" "<<comb[sum+c[i]-1][sum]<<" "<<dp[i]<<endl;
		sum += c[i];
	}
	cout<<dp[k]<<endl;
	return 0;
}
