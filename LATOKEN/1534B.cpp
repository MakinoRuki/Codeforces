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
#define M 10005
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		int minv = INT_MAX;
		int maxv = INT_MIN;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			minv = min(minv, a[i]);
			maxv = max(maxv, a[i]);
		}
		ll tot = 0LL;
		for (int i = 1; i <= n; ++i) {
			if ((i==1 || a[i]>a[i-1]) && (i==n || a[i] > a[i+1])) {
				ll det = a[i];
				if (i + 1 <= n) det = min(det, (ll)(a[i]-a[i+1]));
				if (i-1>=1) det = min(det, (ll)(a[i]-a[i-1]));
				tot += det;
				a[i] -= det;
			}
		}
		// int l = 1, r = maxv;
		// while(l < r) {
		// 	int mid=(l+r)/2;
		// 	cout<<l<<" "<<r<<endl;
		// 	ll tot=0, cnt = 0;
		// 	for (int i = 1; i <= n; ++i) {
		// 		if (a[i] >= mid) {
		// 			tot += (a[i]-mid+1);
		// 			if (i==1) cnt += (a[i]-mid+1);
		// 			else if (a[i-1] < mid) cnt += (a[i]-mid+1);
		// 			else cnt += abs(a[i]-a[i-1]);
		// 			if (i == n || a[i+1] < mid) {
		// 				cnt += a[i]-mid+1;
		// 			}
		// 		}
		// 	}
		// //	cout
		// 	if (tot >= cnt) {
		// 		l = mid+1;
		// 	} else {
		// 		r = mid;
		// 	}
		// }
		// cout<<r<<endl;
		// r--;
		// ll ans = 0LL;
		// for (int i = 1; i <= n; ++i) {
		// 	if (a[i] > r) {
		// 		ans += a[i]-r;
		// 		a[i] = r;
		// 	}
		// }
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || i == n) tot += a[i];
			if (i > 1) tot += abs(a[i]-a[i-1]);
		}
		printf("%lld\n", tot);
	}
  return 0;
}
