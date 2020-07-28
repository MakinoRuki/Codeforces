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
#define N 105
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k, l;
int d[N];
int hs[N][4*N];
bool dp[N][2*N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k>>l;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &d[i]);
		}
		for (int i = 0; i <= 4*k; ++i) {
			hs[0][i] = 0;
			hs[n+1][i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= 4*k; ++j) {
				if (j==0) hs[i][j]=0;
				else {
					hs[i][j] = hs[i][j-1];
					int j2 = (j-1)%k;
					if ((j >= 1 && j <= k) || (j>=2*k+1&&j<=3*k)) {
						if (d[i]+j2 > l) {
							hs[i][j]++;
						}
					} else {
						if (d[i]+k-j2 > l) {
						  hs[i][j]++;
						}
					}
				}
			}
		}
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < 2*k; ++j) {
				if (!dp[i][j]) continue;
				for (int j2 = 0; j2 <= 2*k; ++j2) {
					if (hs[i][j+j2+1]-hs[i][j]==0) {
						int j3 = j+j2+2;
						if (j3 > 4*k) {
							j3 = 1;
						}
						if (hs[i+1][j3] - hs[i+1][j3-1]==0) {
							dp[i+1][(j+j2+1)%(2*k)] = true;
						}
					}
				}
			}
		}
		bool ok = false;
		for (int i = 0; i < 2*k; ++i) {
			if (dp[n+1][i]) ok = true;
		}
		if (ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
  return 0;
}
