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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll p, q;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &p, &q);
		if (p%q!=0) {
			printf("%lld\n", p);
		} else {
			ll ans=0;
			for (ll i = 2; i * i <= q; ++i) {
				ll res=1LL;
				if (q%i==0) {
					while(q%i==0) {
						res *= i;
						q /= i;
					}
					ll tmp=p;
					while(tmp%i==0) {
						tmp/=i;
					}
					tmp *= (res/i);
					ans=max(ans, tmp);
				}
			}
			if (q>1) {
				ll tmp=p;
				while(tmp%q==0) {
					tmp/=q;
				}
				ans=max(ans, tmp);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
