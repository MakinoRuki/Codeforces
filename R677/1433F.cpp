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
#define N 72
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,m,k;
int a[N][N];
int dp[N][N];
int dp2[N][N][N][N];
int main() {
	cin>>n>>m>>k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i =1 ; i <= n; ++i) {
	//	cout<<"i="<<i<<endl;
		for (int j=0; j <=m; ++j) {
			for (int k1=0;k1<=m/2; ++k1) {
				for (int k2=0;k2<k; ++k2) {
					dp2[i][j][k1][k2]=-1;
				}
			}
		}
		//memset(dp2[i], -1, sizeof(dp2[i]));
		dp2[i][0][0][0] = 0;
		//cout<<"???"<<dp2[i][0][0][0]<<endl;
		for (int j = 0; j < m; ++j) {
			for (int k1=0; k1<=m/2; ++k1) {
				for (int k2=0; k2< k; ++k2) {
			//		cout<<"k1="<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
					if(dp2[i][j][k1][k2]>=0) {
				//		cout<<"k2="<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
						dp2[i][j+1][k1][k2] = max(dp2[i][j+1][k1][k2], dp2[i][j][k1][k2]);
						if (i==1 && j==0 && k1==0 && k2==0) {
					//		cout<<"k1="<<k1+1<<" "<<m/2<<endl;
						}
						if (k1+1<=m/2) {
						//	if (i==1 && j==0 && k1==0 && k2==0) cout<<"!!!"<<endl;
							dp2[i][j+1][k1+1][(k2+a[i][j+1])%k] = max(dp2[i][j+1][k1+1][(k2+a[i][j+1])%k], dp2[i][j][k1][k2]+a[i][j+1]);
							//if (i==1 && j==0 && k1==0 && k2==0) cout<<"x="<<dp2[i][j+1][k1+1][k2+1]<<endl;
						}
					}
				}
			}
		}
	//	if (i==1) cout<<"dp="<<dp2[i][1][1][1]<<endl;
		//cout<<"i="<<i<<" "<<dp2[i][m][2][0]<<endl;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0]=0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (dp[i][j]>=0) {
				for (int k1=0;k1<=m/2; ++k1) {
					for (int k2=0;k2<k; ++k2) {
						if (dp2[i+1][m][k1][k2]>=0) {
							dp[i+1][(j+k2)%k] = max(dp[i+1][(j+k2)%k], dp[i][j]+dp2[i+1][m][k1][k2]);
						}
					}
				}
			}
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}
