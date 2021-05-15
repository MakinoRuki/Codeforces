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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		vector<int> bits;
		bits.clear();
		for (int i = 0; i < 30; ++i) {
			int cnt=0;
			for (int j = 1; j <= n; ++j) {
				if ((1<<i) & a[j]) {
					cnt++;
				}
			}
			if (cnt < n) {
				bits.push_back(i);
			}
		}
		ll x = 0;
		for (int i = 1; i <= n; ++i) {
			int j;
			for (j = 0; j < bits.size(); ++j) {
				if ((1<<bits[j])&a[i]) {
					break;
				}
			}
			if (j >= bits.size()) {
				x++;
			}
		}
		ll ans = 0LL;
		if (x >= 2) {
			ans = x*(x-1)%mod;
			for (int i = 1; i <= n-2; ++i) {
				ans = ans * (ll)i % mod;
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
