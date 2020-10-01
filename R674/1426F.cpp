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
#include <queue>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string s;
ll cnta[N],cntc[N];
ll cnt[2][N];
ll pw[N];
ll getpw(ll a, ll b) {
	return pw[b]%mod;
}
int main() {
	cin>>n;
	cin>>s;
	pw[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		pw[i]=pw[i-1]*3LL%mod;
	}
	for (int i = 1; i <= n; ++i) {
		cnt[0][i]=cnt[0][i-1];
		cnta[i]=cnta[i-1];
		if (s[i-1]=='?') {
			cnt[0][i]++;
		} else if (s[i-1]=='a') {
			cnta[i]++;
		}
	}
	for (int i = n; i >= 1; --i) {
		cnt[1][i]=cnt[1][i+1];
		cntc[i]=cntc[i+1];
		if (s[i-1]=='?') {
			cnt[1][i]++;
		} else if (s[i-1]=='c') {
			cntc[i]++;
		}
	}
	ll ans=0LL;
	for (int i = 2; i < n; ++i) {
		if (s[i-1]=='?' || s[i-1]=='b') {
			ll an=cnta[i-1];
			ll cn=cntc[i+1];
			ll n0=cnt[0][i-1];
			ll n1=cnt[1][i+1];
			ans = (ans + an*cn%mod*getpw(3,n0+n1)%mod)%mod;
			if (n1) {
				ans=(ans+an*n1%mod*getpw(3,n0+n1-1)%mod)%mod;
			}
			if (n0) {
				ans=(ans+cn*n0%mod*getpw(3,n0+n1-1)%mod)%mod;
			}
			if (n0&&n1) {
				ans=(ans+n0*n1%mod*getpw(3,n0+n1-2)%mod)%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
