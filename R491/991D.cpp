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
#define N 205
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int dp[N][2][2][2][2];
string s,t;
int st[N][2];
int n;
void update(int& ov, int cv) {
	ov=max(ov, cv);
}
int main() {
	cin>>s>>t;
	n=s.size();
	memset(st, 0, sizeof(st));
	for (int i = 0; i < n; ++i) {
		if (s[i]=='X') {
			st[i+1][0]=1;
		}
		if (t[i]=='X') {
			st[i+1][1]=1;
		}
	}
	if (n<=1) {
		cout<<0<<endl;
	} else {
		memset(dp, -1, sizeof(dp));
		dp[1][1][1][st[1][0]][st[1][1]]=0;
		for (int i = 1; i <= n; ++i) {
			for (int j0=0;j0<2;++j0) {
				for (int j1=0;j1<2; ++j1) {
					for (int k0=0;k0<2; ++k0) {
						for (int k1=0; k1<2; ++k1) {
							if (dp[i][j0][j1][k0][k1]<0) continue;
							int t0,t1;
							if (i+1>n) {
								t0=0,t1=0;
							} else {
								t0=st[i+1][0];
								t1=st[i+1][1];
							}
							update(dp[i+1][k0][k1][t0][t1], dp[i][j0][j1][k0][k1]);
							if (j0==0 && k0==0 && k1==0) {
								update(dp[i+1][1][1][t0][t1], dp[i][j0][j1][k0][k1]+1);
							}
							if (!j1&&!k0&&!k1) {
								update(dp[i+1][1][1][t0][t1], dp[i][j0][j1][k0][k1]+1);
							}
							if (!k0&&!j0&&!j1) {
								update(dp[i+1][1][k1][t0][t1], dp[i][j0][j1][k0][k1]+1);
							}
							if (!k1&&!j0&&!j1) {
								update(dp[i+1][k0][1][t0][t1], dp[i][j0][j1][k0][k1]+1);
							}
							if (i+1<=n) {
								if (!k0&&!k1&&!t0) {
									update(dp[i+1][1][1][1][t1], dp[i][j0][j1][k0][k1]+1);
								}
								if (!k0&&!k1&&!t1) {
									update(dp[i+1][1][1][t0][1], dp[i][j0][j1][k0][k1]+1);
								}
								if (!k0&&!t0&&!t1) {
									update(dp[i+1][1][k1][1][1], dp[i][j0][j1][k0][k1]+1);
								}
								if (!k1&&!t0&&!t1) {
									update(dp[i+1][k0][1][1][1], dp[i][j0][j1][k0][k1]+1);
								}
							}
						}
					}
				}
			}
		}
		int ans=0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				ans=max(ans, dp[n+1][i][j][0][0]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
