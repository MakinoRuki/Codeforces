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
#define M 10005
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N], b[N];
ll dp[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = i; j <= n; ++j) {
	// 		if (i == j) sum[i][j] = (ll)a[i]*(ll)b[i];
	// 		else sum[i][j] = sum[i][j-1] + (ll)a[j]*(ll)b[j];
	// 	}
	// }
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		tot += (ll)a[i]*(ll)b[i];
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			if (i == j) dp[i][j] = (ll)a[i]*(ll)b[i];
			else if (i+1 == j) dp[i][j] = (ll)a[i]*(ll)b[j]+(ll)a[j]*(ll)b[i];
			else {
				dp[i][j] = (ll)a[i]*(ll)b[j]+(ll)a[j]*(ll)b[i]+dp[i+1][j-1];
			}
		}
	}
	ll ans = tot;
	for (int i = 1; i <= n; ++i) {
		ll sum=0LL;
		for (int j = i; j <= n; ++j) {
			sum += (ll)a[j]*(ll)b[j];
			ans = max(ans, tot - sum + dp[i][j]);
		}
	}
	cout<<ans<<endl;
  return 0;
}
