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
int k;
int q;
int d[N];
int idx[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &d[i]);
		}
		sort(d+1, d+n+1);
		ll ans = 0LL;
		for (int i = 1; i < n; ++i) {
			ll det = d[i+1]-d[i];
			ans += det;
			ans -= det * (ll)i * (ll)(n-i);
		}
		printf("%lld\n", ans);
	}
  return 0;
}
