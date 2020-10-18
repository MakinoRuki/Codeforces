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
#define N 60
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int pw[10];
int main() {
	cin>>n;
	vector<int> ds;
	ds.clear();
	pw[0]=1;
	for (int i = 1; i <= 9; ++i) {
		pw[i]=pw[i-1]*10;
	}
	int x=n;
	while(x) {
		ds.push_back(x%10);
		x/=10;
	}
	int len=(int)ds.size();
	reverse(ds.begin(), ds.end());
	int ans=0;
	if (ds[0]<5) {
		if (len>1) {
			ans=pw[len-1]/2-1;
			int dp[12][2][2];
			for (int i=1;i<=ds[0]; ++i) {
				for (int j=0;j<=i; ++j) {
					memset(dp, 0, sizeof(dp));
					int f1=0,f2=0;
					if (i<ds[0]) f1=1;
					if (j<ds[0]) f2=1;
					dp[0][f1][f2]=1;
					for (int i2=0; i2<len-1; ++i2) {
						for (int j1=0;j1<2; ++j1) {
							for (int j2=0;j2<2; ++j2) {
								if (dp[i2][j1][j2]==0) continue;
							//	if (i==1 && j==1) cout<<"i2="<<i2<<" "<<j1<<" "<<j2<<endl;
								for (int d1=0; d1<=9; ++d1) {
									int d2=9-d1;
									if (!j1 && !j2 && d1<=ds[i2+1] && d2<=ds[i2+1]) {
									//	if (i==1 && j==1)cout<<"d1="<<d1<<" "<<d2<<endl;
										dp[i2+1][d1<ds[i2+1]][d2<ds[i2+1]] += dp[i2][j1][j2];
									} else if (!j1 && j2 && d1<=ds[i2+1]) {
										dp[i2+1][d1<ds[i2+1]][j2] += dp[i2][j1][j2];
									} else if (j1 && !j2 && d2<=ds[i2+1]) {
										dp[i2+1][j1][d2<ds[i2+1]] += dp[i2][j1][j2];
									} else if (j1 && j2) {
										dp[i2+1][j1][j2] += dp[i2][j1][j2];
									}
								}
							}
						}
					}
					int det=0;
					for (int j1=0;j1<2;++j1) {
						for (int j2=0;j2<2;++j2) {
						//	if (i==1 && j==1 && dp[len-1][j1][j2]>0) cout<<"j1="<<j1<<" "<<j2<<" "<<dp[len-1][j1][j2]<<endl;
							det += dp[len-1][j1][j2];
						}
					}
					if (i==j) ans += det/2;
					else {
						if (j==0 && (i<ds[0] || n-ds[0]*pw[len-1] == pw[len-1]-1)) {
							ans += det-1;
						} else {
							ans += det;
						}
					}
				//	cout<<i<<" "<<j<<" "<<ans<<endl;
				}
			}
		} else {
			ans=n*(n-1)/2;
		}
	} else {
		ans += (ds[0]-5)*pw[len-1];
	//	cout<<"ans="<<ans<<endl;
		int dp[12][2];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < len-1; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int d=0; d<= 9; ++d) {
					if (d>ds[i+1] && j==1) {
						dp[i+1][j] += dp[i][j];
					} else if (d==ds[i+1]) {
						dp[i+1][j] += dp[i][j];
					} else if (d<ds[i+1]) {
						dp[i+1][1] += dp[i][j];
					}
				}
			}
		}
		ans += dp[len-1][0]+dp[len-1][1];
		if (n==pw[len]-1) {
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
