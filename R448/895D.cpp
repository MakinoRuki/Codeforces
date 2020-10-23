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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
string a,b;
ll a1[N], b1[N];
ll fac[N];
ll fac2[N];
int cnt[27];
int cnt2[27];
// ll comb(ll x, ll y) {
// 	return fac[x]*fac2[y]%mod*fac2[x-y]%mod;
// }
ll calc(int tot, int c, ll cn) {
	ll res=fac[tot];
	res=res*cn%mod*fac2[cnt2[c]]%mod;
	return res;
}
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
	cin>>a>>b;
	n = a.size();
	fac[0]=1LL;
	fac2[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i]=fac[i-1]*(ll)i%mod;
		fac2[i]=getpw(fac[i], mod-2);
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i) {
		cnt[a[i]-'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		cnt2[i]=cnt[i];
	}
	for (int i = 0; i < n; ++i) {
		int c=a[i]-'a';
		ll num[26];
		ll pre=1LL;
		for (int j = 0; j < 26; ++j) {
			num[j]=pre;
			pre=pre*fac2[cnt2[j]]%mod;
		}
		pre=1LL;
		for (int j = 25; j>=0; --j) {
			num[j]=num[j]*pre%mod;
			pre=pre*fac2[cnt2[j]]%mod;
		}
		for (int j = c+1; j < 26; ++j) {
			if (cnt2[j]>0) {
				cnt2[j]--;
			//	if (i==0 && j==c+1) cout<<"x="<<i<<" "<<j<<" "<<calc(n-1-i)<<endl;
				a1[i] = (a1[i] + calc(n-1-i, j, num[j]))%mod;
				cnt2[j]++;
			}
		}
		cnt2[c]--;
	}
	for (int i = n-2; i >= 0; --i) {
		a1[i] = (a1[i] + a1[i+1]) % mod;
	}
	for (int i = 0; i < 26; ++i) {
		cnt2[i]=cnt[i];
	}
	for (int i = 0; i < n; ++i) {
		int c=b[i]-'a';
		ll num[26];
		ll pre=1LL;
		for (int j = 0; j < 26; ++j) {
			num[j]=pre;
			pre=pre*fac2[cnt2[j]]%mod;
		}
		pre=1LL;
		for (int j = 25; j>=0; --j) {
			num[j]=num[j]*pre%mod;
			pre=pre*fac2[cnt2[j]]%mod;
		}
		for (int j = c-1; j >= 0; --j) {
			if (cnt2[j]>0) {
				cnt2[j]--;
				//if (i==0) cout<<"xx="<<j<<" "<<calc(n-1-i)<<endl;
				b1[i] = (b1[i] + calc(n-1-i, j, num[j]))%mod;
				cnt2[j]++;
			}
		}
		if (cnt2[c]>0) cnt2[c]--;
		else break;
	}
	for (int i = n-2; i >= 0; --i) {
		b1[i] = (b1[i+1] + b1[i]) % mod;
	}

	ll ans=0LL;
	for (int i = 0; i < 26; ++i) {
		cnt2[i]=cnt[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) {
			ans = a1[i+1];
			int c1=a[i]-'a';
			int c2=b[i]-'a';
			ll num[26];
			ll pre=1LL;
			for (int j = 0; j < 26; ++j) {
				num[j]=pre;
				pre=pre*fac2[cnt2[j]]%mod;
			}
			pre=1LL;
			for (int j = 25; j>=0; --j) {
				num[j]=num[j]*pre%mod;
				pre=pre*fac2[cnt2[j]]%mod;
			}
			for (int j = c1+1; j < c2; ++j) {
				if (cnt2[j]>0) {
					cnt2[j]--;
					ans = (ans + calc(n-1-i, j, num[j])) % mod;
					cnt2[j]++;
				}
			}
			ans = (ans + b1[i+1]) %mod;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
