#pragma GCC optimize(2)
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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, l, r, k;
string s;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll n;
		scanf("%lld", &n);
		if (n < 6) {
			n = 6;
		}
		if (n % 2) {
			n++;
		}
		ll ans = n/2 * 5;
		// ll ans = 0LL;
		// if (n >= 10) {
		// 	ll det = n/10;
		// 	n -= det*10;
		// 	ans += det * 25LL;
		// }
		// if (n >= 8) {
		// 	ll det = n/8;
		// 	n -= det*8;
		// 	ans += det * 20LL;
		// }
		// ll det = (n+5)/6;
		// ans += det * 15LL;
		printf("%lld\n", ans);
	}
  return 0;
}
