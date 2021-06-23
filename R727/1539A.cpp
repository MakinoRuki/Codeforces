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
#define N 510
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int k;
int q;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll n, x, tt;
		scanf("%lld%lld%lld", &n, &x, &tt);
		ll a = min(tt/x, n-1);
		ll ans = max(n-a, 0LL) * a;
		ll b = (a > 0 ? a*(a-1)/2 : 0LL);
		ans += b;
		printf("%lld\n", ans);
	}
  return 0;
}
