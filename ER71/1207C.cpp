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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int t;
int n;
ll a, b;
string s;
ll dp[N][3];
int main() {
	cin>>t;
	for (int cas = 1; cas<=t; ++cas) {
		scanf("%d%lld%lld", &n, &a, &b);
		cin>>s;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; j <= 2; ++j) {
				dp[i][j] = (1LL<<61)-1;
			}
		}
		dp[0][1] = b;
		for (int i = 0; i < n; ++i) {
			if (dp[i][1] < (1LL<<61)-1) {
				if (s[i] == '0') {
					dp[i+1][1] = min(dp[i+1][1], dp[i][1] + a+b);
					dp[i+1][2] = min(dp[i+1][2], dp[i][1] + 2*a+2*b);
				}
			}
			if (dp[i][2] < (1LL<<61)-1) {
				if (s[i] == '0') {
					dp[i+1][1] = min(dp[i+1][1], dp[i][2] + 2*a+b);
				}
				dp[i+1][2] = min(dp[i+1][2], dp[i][2] + a+2*b);
			}
		//	cout<<"i="<<i+1<<" "<<dp[i+1][1]<<" "<<dp[i+1][2]<<endl;
		}
		printf("%lld\n", dp[n][1]);
	}
	return 0;
}
