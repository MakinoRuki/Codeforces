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
int t;
int q, n;
ll k, x;
ll a[N];
int main() {
	cin>>n>>k>>x;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	ll ans = 0LL;
	vector<ll> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			ans++;
		} else {
			if (a[i] - a[i-1] > x) {
				ll det = (a[i]-a[i-1]);
				if (det % x == 0) {
					rk.push_back((a[i]-a[i-1])/x-1);
				} else {
					rk.push_back((a[i]-a[i-1])/x);
				}
				ans++;
			}
		}
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		if (rk[i] <= k) {
			ans--;
			k -= rk[i];
		} else {
			break;
		}
	}
	printf("%lld\n", ans);
  return 0;
}
