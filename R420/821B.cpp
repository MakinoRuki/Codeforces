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
#define N 52
#define SZ 200000002
#define eps 1e-7
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int m, b;
int main() {
	cin>>m>>b;
	ll ans=0LL;
	for (int y0 = 0; y0 <= b; ++y0) {
		ll x = (ll)m*(ll)(b-y0);
		ll res = (ll)(1+y0)*(ll)y0/2*(x+1);
		res += (1+x)*x/2*(ll)(y0+1);
		ans = max(ans, res);
	}
	printf("%lld\n", ans);
  return 0;
}
