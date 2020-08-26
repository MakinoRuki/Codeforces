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
#define N 5002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
ll p, f;
int cs, cw;
ll s, w;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &p, &f);
		scanf("%d%d", &cs, &cw);
		scanf("%lld%lld", &s, &w);
		ll ans = 0;
		for (int i = 0; i <= cs; ++i) {
			if (i * s <= p) {
				ll cnt = 0;
				ll x = i;
				ll y = max(0LL, (p-i*s));
				y /= w;
				if (y>cw) {
					y = cw;
				}
				cnt += x + y;
				x = cs-x;
				y = cw - y;
				if (s < w) {
					ll x2 = min(x, f/s);
					ll det = f-x2*s;
					ll y2 = min(det/w, y);
					cnt += x2+y2;
				} else {
					ll x2 = min(y, f/w);
					ll det = f-x2*w;
					ll y2 = min(det/s, x);
					cnt += x2+y2;
				}
				ans = max(ans, cnt);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
