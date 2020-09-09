#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, q;
int a[N];
int sum[N];
ll getpw(ll x, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) res=res*x%mod;
		x=x*x%mod;
		b/=2;
	}
	return res;
}
int main() {
	cin>>n>>q;
	string s;
	memset(sum, 0, sizeof(sum));
	cin>>s;
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1]+(s[i-1]=='1');
	}
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		int n1=sum[r]-sum[l-1];
		int n0=r-l+1-n1;
		ll res=getpw(2LL, n1);
		res=(res-1+mod)%mod;
		res=res*getpw(2LL, n0)%mod;
		printf("%lld\n", res);
	}
	return 0;
}
