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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
ll fac[N];
ll fac2[N];
ll getpw(ll x, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) res=res*x%mod2;
		x=x*x%mod2;
		b/=2;
	}
	return res;
}
ll comb(int a, int b) {
	ll res = fac[a] * fac2[a-b] % mod2 * fac2[b] % mod2;
	return res;
}
int main() {
	cin>>n>>k;
	fac[0]=1LL;
	fac2[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i]=fac[i-1]*(ll)i%mod2;
		fac2[i] = getpw(fac[i], mod2-2)%mod2;
	}
	vector<pair<int, int>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		rk.push_back(make_pair(l, -1));
		rk.push_back(make_pair(r, 1));
	}
	ll tot=0LL;
	sort(rk.begin(), rk.end());
	ll ans=0LL;
	for (int i = 0; i < rk.size(); ++i) {
		int f=rk[i].second;
		if (f==-1) {
			tot++;
		//	cout<<"i="<<i<<" "<<rk[i].first<<" "<<tot<<endl;
			if (tot == k) {
				ans = (ans+1)%mod2;
			} else if (tot > k) {
			//	cout<<tot<<" "<<k<<" "<<comb(tot-1, k-1)<<endl;
				ans = (ans + comb(tot-1, k-1)) % mod2;
			}
		} else {
			tot--;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
