#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
#define M 1000005
#define N 500005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
//string s;
string s;
int t;
int n, q, m, k, e;
int a[N];
ll dp[N][2][2];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod2;
		x=x*x%mod2;
		y/=2;
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int cnt=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == 1) {
				cnt++;
			}
		}
		for (int i = 0; i <= n; ++i) {
			for (int j1 = 0; j1 < 2; ++j1) {
				for (int j2 = 0; j2 < 2; ++j2) {
					dp[i][j1][j2] = 0LL;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			ll v[2][2];
			v[0][0] = dp[a[i]][0][0];
			v[1][0] = dp[a[i]][1][0];
			v[1][1] = dp[a[i]][1][1];
			if (a[i]-1>=0) {
				v[0][0] = (v[0][0] + dp[a[i]-1][0][0]) % mod2;
			}
			v[0][0] = (v[0][0] + dp[a[i]][0][0]) % mod2;
			for (int j = 0; j < 2; ++j) {
				v[1][j] = (v[1][j] + dp[a[i]][1][j]) % mod2;
			}
			if (a[i] - 2 >= 0) {
				v[1][1] = (v[1][1] + dp[a[i]-2][0][0]) % mod2;
				v[1][1] = (v[1][1] + dp[a[i]-2][1][0]) % mod2;
			}
			if (a[i]+2 <= n) {
				v[1][0] = (v[1][0] + dp[a[i]+2][1][1]) % mod2;
			}
			if (a[i] == 0) {
				v[0][0] = (v[0][0] + 1) % mod2;
			}
			dp[a[i]][0][0] = v[0][0];
			dp[a[i]][1][0] = v[1][0];
			dp[a[i]][1][1] = v[1][1];
		}
		ll ans = 0LL;
		for (int i = 0; i <= n; ++i) {
		//	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
			ans = (ans + dp[i][0][0])% mod2;
			ans = (ans + dp[i][1][0]) % mod2;
			ans = (ans + dp[i][1][1]) % mod2;
		}
	//	cout<<"ans="<<ans<<endl;
		ans = (ans + (getpw(2LL, cnt) - 1 + mod2)%mod2) % mod2;
//		cout<<"ans="<<ans<<endl;
		printf("%lld\n", ans);
	}
  return 0;
}

