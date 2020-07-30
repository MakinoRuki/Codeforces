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
#define N 300005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n, k, z;
int a[N];
ll dp[N][6];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d",&n,&k,&z);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		a[n+1]=0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= 5; ++j) {
				dp[i][j] = -1;
			}
		}
		dp[2][0] = a[1]+a[2];
		ll ans = a[1]+a[2];
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j <= z; ++j) {
				if (dp[i][j] >= 0) {
					for (int j2 = 0; j+j2 <= z; ++j2) {
						if (i-1+j*2+j2*2+1 <= k) {
							dp[i+1][j+j2] = max(dp[i+1][j+j2], dp[i][j]+(ll)j2*(a[i-1]+a[i])+a[i+1]);
						}
						if (i < n && i-1+j*2+j2*2+1 == k) {
							ans = max(ans, dp[i][j]+(ll)j2*(a[i-1]+a[i])+a[i+1]);
						}	else if (i-1+j*2+j2*2==k) {
							ans = max(ans, dp[i][j]+(ll)j2*(a[i-1]+a[i]));
						} else if (j2>0 && i-1+j*2+(j2-1)*2+1 == k) {
							ans = max(ans, dp[i][j]+(ll)(j2-1)*(a[i-1]+a[i])+a[i-1]);
						}
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
