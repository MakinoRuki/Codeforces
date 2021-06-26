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
#define N 50
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
ll a,b, x, y;
ll calc(ll n1) {
	if (x-a*n1<0) return n1;
	if (y-b*n1<0) return n1;
	ll d1 = (x-a*n1)/b;
	ll d2 = (y-b*n1)/a;
	return n1 + min(d1, d2);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (a == b) {
			printf("%lld\n", (ll)min(x/a, y/b));
		} else {
		//	if (a > b) swap(a,b);
			ll z = (b*y-a*x)/(b*b-a*a);
			if (z < 0) {
				z = 0LL;
			}
			ll ans = max(calc(0), calc(min(x/a, y/b)));
		//	ll ans = calc()
		//	cout<<"z="<<z<<endl;
			// 取不到非整数极值，因此取极值附近的整数。
			for (ll i = z-2500; i <= z+2500; ++i) {
				if (i < 0) continue;
				if (i > x/a || i > y/b) continue;
				ll n1 = (x-i*a)/b;
				ll n2 = (y-i*b)/a;
				ll j = ((x-i*a<0 || y-i*b<0) ? 0LL : min(n1,n2));
				ans = max(ans, i + j);
			}
			printf("%lld\n", ans);
		}
	}
  return 0;
}
