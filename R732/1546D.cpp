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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
ll fac[N];
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
	fac[0] = 1LL;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i-1] * (ll)i % mod2;
	}
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		string s;
		cin>>s;
		int c0 = 0, c1 = 0;
		int cnt=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') cnt++;
			else {
				c1 += cnt/2;
				cnt=0;
				c0++;
			}
		}
		c1 += cnt/2;
		ll ans = fac[c0+c1];
		ans = ans * getpw(fac[c0], mod2-2) % mod2;
		ans = ans * getpw(fac[c1], mod2-2) % mod2;
		printf("%lld\n", ans);
	}
  return 0;
}
