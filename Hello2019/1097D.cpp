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
#define M 31
#define N 10005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
int k;
ll dp[N][62];
ll fac2[62];
ll getpw(ll x, ll y) {
	ll res=1LL;
	while(y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
}
int main() {
	cin>>n>>k;
	vector<pair<ll,int>> ps;
	ps.clear();
	for (ll i = 2; i * i <= n; ++i) {
		if (n%i==0) {
			int cnt=0;
			while(n%i==0) {
				cnt++;
				n/=i;
			}
			ps.push_back(make_pair(i, cnt));
		}
	}
	if (n>1) ps.push_back(make_pair(n, 1));
	fac2[0] = 1LL;
	for (int i = 1; i <= 60; ++i) {
		fac2[i] = getpw(i, mod-2);
	}
	ll ans=1LL;
	for (int i = 0; i < ps.size(); ++i) {
		ll p = ps[i].first;
		int cnt=ps[i].second;
		for (int x = 0; x <= k; ++x) {
			for (int j = 0; j <= 60; ++j) {
				dp[x][j] = 0;
			}
		}
		dp[0][cnt] = 1;
		for (int j = 0; j < k; ++j) {
			for (int x = 0; x <= cnt; ++x) {
				for (int y = x; y >= 0; --y) {
				//	if (j == 1 && y == 1) cout<<"p="<<p<<" "<<"j="<<j<<" "<<x<<" "<<dp[j][x]<<" "<<fac2[x+1]<<" "<<dp[j+1][y]<<endl;
					dp[j+1][y] = (dp[j+1][y] + dp[j][x]*fac2[x+1]%mod) % mod;
				}
			}
		}
	//	cout<<dp[1][1]<<" "<<dp[2][1]<<" "<<fac2[4]<<endl;
	//	cout<<p<<" "<<cnt<<" "<<k<<" "<<dp[k][0]<<" "<<dp[k][1]<<endl;
		ll res[62];
		res[0] = 1LL;
		for (int j = 1; j <= cnt; ++j) {
			res[j] = res[j-1]*p % mod;
		}
		ll cur=0LL;
		for (int j = 0; j <= cnt; ++j) {
			cur = (cur + dp[k][j]*res[j]%mod)%mod;
		}
		ans = ans * cur%mod;
	}
	cout<<ans<<endl;
	return 0;
}
