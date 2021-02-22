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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll x,y;
		scanf("%lld%lld", &x, &y);
		ll tot=0LL;
		for (ll r = 1; r <= 100000; ++r) {
			ll ub = min(y, (x/r)-1);
			if (ub > r) {
				tot += ub-r;
			} else {
				break;
			}
		}
		printf("%lld\n", tot);
	}
  return 0;
}
