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
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int a[N];
map<int, ll> sum;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		sum.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans = 0LL;
		for (int i = 1; i <= n; ++i) {
			ll det = (ll)(n-i+1);
			if (sum.find(a[i]) != sum.end()) {
				ans += det * (sum[a[i]]);
			}
			sum[a[i]] += (ll)i;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
