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
#define N 5000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll t,l,r;
ll dp[N];
ll prm[N];
ll pw[N];
ll dfs(int x) {
	if (dp[x]>=0) return dp[x];
	if (x==1) return dp[x]=0LL;
	dp[x]=(ll)x*(ll)(x-1)/2LL;
	dp[x]%=mod;
	ll i;
	if (x>2 && x%2==0) {
		return dp[x] = (dfs(x/2)+(2*(2-1)/2)%mod*(x/2)%mod)%mod;
	}
	int d=prm[x];
	if (d<0) return dp[x];
	return dp[x]=(dfs(x/d)+(d*(d-1)/2)%mod*(x/d)%mod)%mod;
	// for (i = 2; i * i <= x; ++i) {
	// 	if (x%i==0) {
	// 		ll res=
	// 		dp[x]=res;
	// 		return dp[x];
	// 	}
	// }
	// return dp[x];
}
// ll dfs(int v) {
// 	if (dp[v]>=0) return dp[v];
// 	if (v==1) return dp[v]=0;
// 	dp[v]=inf;
// 	int d1=-1;
// 	for (int i = 1; i *i <= v; ++i) {
// 		if (v%i==0) {
// 			int d=i;
// 			ll res1=dfs(v/d)+d*(d-1)/2;
// 			if (res1<dp[v]) {
// 				dp[v]=res1;
// 				d1=d;
// 			}
// 			d = v/i;
// 			res1=dfs(v/d)+d*(d-1)/2;
// 			if (res1<dp[v]) {
// 				dp[v]=res1;
// 				d1=d;
// 			}
// 		}
// 	}
// 	cout<<v<<" "<<dp[v]<<" "<<d1<<endl;
// 	return dp[v];
// }
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
	cin>>t>>l>>r;
	memset(prm, -1, sizeof(prm));
	for (int i = 2; i*i <= r; ++i) {
		if (prm[i]<0) {
			for (int j = 2*i; j <= r; j += i) {
				if (prm[j]<0) prm[j]=i;
			}
		}
	}
	pw[0]=1LL;
	for (int i = 1; i <= r; ++i) {
		pw[i]=pw[i-1]*(ll)t%mod;
	}
	memset(dp, -1, sizeof(dp));
	ll res=0LL;
	for (int i = 2; i <= r; ++i) {
		if (dp[i]<0) {
			dfs(i);
			if (i>=l && i <= r) {
			//	cout<<i<<" "<<dp[i]<<endl;
			//	cout<<t<<" "<<i-l<<" "<<getpw(t, i-l)<<endl;
				ll tmp=dp[i]*pw[i-l]%mod;
				res=(res+tmp)%mod;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
