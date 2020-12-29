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
int t,n,m,k;
int a[N];
int cnt[N];
ll fac[N];
ll fac2[N];
ll getpw(ll a, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}
ll comb(int a, int b) {
	ll res = fac[a]*fac2[b]%mod*fac2[a-b]%mod;
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; ++i) {
			cnt[i]=0;
		}
		
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		fac[0]=1LL;
		fac2[0]=1LL;
		for (int i = 1; i <= n; ++i) {
			fac[i] = fac[i-1]*(ll)i%mod;
			fac2[i] = getpw(fac[i], mod-2);
		}
		ll tot=0LL;
		int j=1;
		ll sum=0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > 0) {
				while(j <= i+k && j <= n) {
					sum += cnt[j];
					j++;
				}
				for (int x = 1; x <= min(m, cnt[i]); ++x) {
					if (sum-cnt[i]+x >= m) {
					//	cout<<i<<" "<<j<<" "<<sum<<endl;
						ll cur=comb(cnt[i], x) * comb(sum-cnt[i], m-x) % mod;
						tot=(tot+cur)%mod;
					}
				}
				sum -= cnt[i];
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
}
