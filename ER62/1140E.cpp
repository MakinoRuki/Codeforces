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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int a[N];
ll getans1(int len) {
	ll res=1LL;
	ll a=(k-1);
	while(len) {
		if (len&1) res=res*a%mod2;
		a=a*a%mod2;
		len/=2;
	}
	return res;
}
ll getans2(int l, int r) {
	int tot=(r-l)/2-1;
	ll dp[tot+2][2][2];
	memset(dp, 0LL, sizeof(dp));
	if (tot==0) {
		if (a[l]==a[r]) return 0LL;
		return 1LL;
	}
	if (a[l]==a[r]) {
		dp[0][1][1]=1LL;
		for (int i = 0; i < tot; ++i) {
			dp[i+1][1][1] = (dp[i][0][0]+dp[i+1][1][1])%mod2;
			dp[i+1][0][0] = (dp[i][1][1]*(k-1)%mod2+dp[i][0][0]*(k-2)%mod2)%mod2;
		}
		return dp[tot][0][0];
	} else {
		dp[0][1][0] = 1LL;
		for (int i = 0; i < tot; ++i) {
			for (int j1 =0;j1<2; ++j1) {
				for (int j2=0;j2<2; ++j2) {
					if (j1==0 && j2==0) {
						if (k>=3) dp[i+1][0][0] = (dp[i+1][0][0]+dp[i][j1][j2]*(k-3)%mod2)%mod2;
						dp[i+1][1][0]=(dp[i+1][1][0]+dp[i][j1][j2])%mod2;
						dp[i+1][0][1]=(dp[i+1][0][1]+dp[i][j1][j2])%mod2;
					} else if (j1==0 && j2) {
						dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][j1][j2]*(k-2)%mod2)%mod2;
						dp[i+1][1][0]=(dp[i+1][1][0]+dp[i][j1][j2])%mod2;
					} else if (j1 && !j2) {
						dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][j1][j2]*(k-2)%mod2)%mod2;
						dp[i+1][0][1]=(dp[i+1][0][1]+dp[i][j1][j2])%mod2;
					}
				}
			}
		}
		if (tot==1) return dp[tot][0][0];
		return (dp[tot][0][0]+dp[tot][1][0])%mod2;
	}
	return 0;
}
int main() {
	vector<int> v1,v2;
	cin>>n>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i]>=1) {
			if (i%2) v1.push_back(i);
		  else v2.push_back(i);
		}
	}
	ll ans=1LL;
	if (v1.empty()) {
		int tot=n/2;
		if (n%2) tot++;
		ans = ans * k % mod2 * getans1(tot-1) % mod2;
	} else {
		for (int i = 0; i < v1.size(); ++i) {
			if (i == 0) {
				ans=ans*getans1((v1[i]-1)/2)%mod2;
			} else {
				ans=ans*getans2(v1[i-1], v1[i])%mod2;
			}
			if (i==v1.size()-1) {
				ans=ans*getans1((n-v1[i])/2)%mod2;
			}
		}
	}
//	cout<<ans<<endl;
	if (v2.empty()) {
		int tot=n/2;
		ans=ans*k%mod2*getans1(tot-1)%mod2;
	} else {
		for (int i = 0; i < v2.size(); ++i) {
			if (i==0) {
				ans=ans*getans1((v2[i]-1)/2)%mod2;
			} else {
				ans=ans*getans2(v2[i-1], v2[i])%mod2;
			}
			if (i==v2.size()-1) {
				ans=ans*getans1((n-v2[i])/2)%mod2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
