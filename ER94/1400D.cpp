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
#define N 3005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
int n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans = 0LL;
		for (int i = 1; i <= n; ++i) {
			int cnt[N];
			int cnt2[N];
			memset(cnt, 0, sizeof(cnt));
			for (int j = i+1; j <= n; ++j) {
				if (a[j] == a[i]) continue;
				cnt[a[j]]++;
			}
			memset(cnt2, 0, sizeof(cnt2));
			ll tot = 0LL;
			for (int j = i+1; j <= n; ++j) {
				if (a[j] == a[i]) {
					ans += tot;
				} else {
					ll cur = cnt2[a[j]] * (cnt[a[j]]-cnt2[a[j]]);
					tot -= cur;
					cnt2[a[j]]++;
					tot += cnt2[a[j]] * (cnt[a[j]] - cnt2[a[j]]);
				}
			}
			ll num = 0LL;
			for (int j= i+1; j <= n; ++j) {
				if (a[j] == a[i]) {
					num++;
				}
			}
			if (num>=3) {
				ans += num*(num-1)*(num-2)/6;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
