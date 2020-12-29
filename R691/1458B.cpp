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
#define N 105
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N], b[N];
int dp[2][N][N*N*4];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][20000]=0;
	for (int i = 0; i < n; ++i) {
		int now=i&1;
		memset(dp[now^1], -1, sizeof(dp[now^1]));
		for (int j = 0; j <= i; ++j) {
			for (int s1 = 0; s1 <= 35000; ++s1) {
				if (dp[now][j][s1]>=0) {
					int det=a[i+1]-b[i+1];
					if (s1-2*det>=0 && s1-2*det<=35000) dp[now^1][j+1][s1-2*det] = max(dp[now^1][j+1][s1-2*det], dp[now][j][s1]+2*b[i+1]);
					if (s1+b[i+1]>=0 && s1+b[i+1]<=35000) dp[now^1][j][s1+b[i+1]] = max(dp[now^1][j][s1+b[i+1]], dp[now][j][s1]+b[i+1]);
				}
			}
		}
		// for (int j = 0; j <= i+1; ++j) {
		// 	for (int s1=0; s1<=35000; ++s1) {
		// 		if (dp[now^1][j][s1] >= 0) {
		// 		//	cout<<"v="<<i+1<<" "<<j<<" "<<s1-20000<<" "<<dp[now^1][j][s1]<<endl;
		// 		}
		// 	}
		// }
	}
	for (int i = 1; i <= n; ++i) {
		int res=-1;
		for (int j = 0; j <= 35000; ++j) {
			if (dp[n&1][i][j] >= 0) {
				int det=j-20000;
				if (det>0) res=max(res, dp[n&1][i][j]-det);
				else res=max(res, dp[n&1][i][j]);
			//	if (res>14) cout<<i<<" "<<j<<endl;
			}
		}
		double res2=res*0.5;
		printf("%.10lf", res2);
		if (i < n) cout<<" ";
		else cout<<endl; 
	}
	return 0;
}
