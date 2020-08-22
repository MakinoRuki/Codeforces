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
int t, n, k;
ll x,y,z;
ll a,b,c;
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%lld%lld%lld", &x,&y,&z);
		scanf("%lld%lld%lld",&a,&b,&c);
		ll w = min(z,b);
		ll det = x+z-c;
		if (w<=det) {
			ll ans = 2LL*w;
			printf("%lld\n", ans);
		} else {
			ll ans = 2LL*(x+z-c);
			if (det>=0) {
				ans = max(ans, 2LL*det);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
