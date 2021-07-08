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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		ll tot = 0LL;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			tot += a[i];
		}
		ll det = tot / n;
		ll r = tot % n;
		ll ans = r * (n - r);
		printf("%lld\n", ans);
	}
  return 0;
}
