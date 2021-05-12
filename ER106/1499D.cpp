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
#define M 25
#define N 20000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int mp[N];
int ps[N];
int main() {
	for (int i = 1; i <= 20000000; ++i) {
		mp[i]=i;
	}
	for (int i = 2; i * i <= 20000000; ++i) {
		if (mp[i] == i) {
			for (int j = i*i; j <= 20000000; j += i) {
				mp[j] = i;
			}
		}
	}
	ps[1] = 0;
	for (int i = 2; i <= 20000000; ++i) {
		if (mp[i] == i) {
			ps[i] = 1;
		} else {
			int p = mp[i];
			int x = i;
			while(x%p == 0) {
				x/=p;
			}
			ps[i] = ps[x] + 1;
		}
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll c,d,x;
		scanf("%lld%lld%lld", &c, &d, &x);
		ll ans = 0LL;
		for (ll i = 1; i * i <= x; ++i) {
			if (x%i == 0) {
				ll g = i;
				ll w = x/g+d;
				if (w % c == 0) {
					int m = ps[w/c];
					ans += (1LL<<m);
				}
				if (x/i != i) {
					g = x/i;
					w = x/g+d;
					if (w%c==0) {
						int m = ps[w/c];
						ans += (1LL<<m);
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
