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
#define N 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
ll d[N];
ll sum[N];
ll getpw(ll x, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) {
			res=res*x%mod2;
		}
		x=x*x%mod2;
		b/=2;
	}
	return res;
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &d[i]);
	}
	sort(d+1, d+n+1);
	memset(sum, 0LL, sizeof(sum));
	int l=1,r=n;
	while(l<r) {
		swap(d[l], d[r]);
		l++;
		r--;
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1]+d[i];
	}
	for (int i = 1; i <= m; ++i) {
		int a;
		ll b;
		scanf("%d%lld", &a, &b);
		l = 0, r=n;
		while(l<r) {
			int mid=(l+r+1)/2;
			if (d[mid] >= b) {
				l=mid;
			} else {
				r=mid-1;
			}
		}
		if (r < a) {
			cout<<0<<endl;
		} else {
			ll res=sum[r]*(ll)(r-a)%mod2;
			res=res*getpw(r, mod2-2)%mod2;
		//	cout<<"res="<<res<<endl;
			ll res2=(sum[n]-sum[r])*(ll)(r+1-a)%mod2;
		//	cout<<"res2="<<res2<<endl;
			res2=res2*getpw(r+1, mod2-2)%mod2;
			res = (res+res2)%mod2;
			printf("%lld\n", res);
		}
	}
	return 0;
}
