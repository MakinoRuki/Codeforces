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
int t, n, l, r, k;
string s;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		// k=100;
		// n=100000;
		for (int i = 1; i <= n; ++i) {
			//a[i] = rand()%(n+1);
			scanf("%d", &a[i]);
		}
		ll ans = 0LL;
		bool ok=false;
		// for (int i = 1; i <= 100; ++i) {
		// 	for (int j = 1; j <= 100; ++j) {

		// 	}
		// }
		int det = min(101, k);
		for (int i = n; i >= max(n-101,1); --i) {
			for (int j = i-1; j >= max(n-101, 1); --j) {
				if (!ok) {
					ans = (ll)i*(ll)(j) - (ll)k * (ll)(a[i]|a[j]);
					ok=true;
				} else {
					ans = max(ans, (ll)i*(ll)(j) - (ll)k * (ll)(a[i]|a[j]));
				}
			}
		}
		// for (int i = 2; i <= n; ++i) {
		// 	if (i <= k) {
		// 		for (int j = i-1; j >= 1; --j) {
		// 			if (!ok) {
		// 				ans = (ll)i*(ll)(j) - (ll)k * (ll)(a[i]|a[j]);
		// 				ok=true;
		// 			} else {
		// 				ans = max(ans, (ll)i*(ll)(j) - (ll)k * (ll)(a[i]|a[j]));
		// 			}
		// 		}
		// 	} else {
		// 		if (!ok) {
		// 			ans = (ll)i*(ll)(i-1) - (ll)k * (ll)(a[i]|a[i-1]);
		// 			ok=true;
		// 		} else {
		// 			ans = max(ans, (ll)i*(ll)(i-1) - (ll)k * (ll)(a[i]|a[i-1]));
		// 		}
		// 	}
		// }
	// 	// for (int i = 1; i < n; ++i) {
	// 	// 	if (i == 1) {
	// 	// 		ans = (ll)i*(ll)(i+1) - (ll)k * (ll)(a[i]|a[i+1]);
	// 	// 	} else {
	// 	// 		ans = max(ans, (ll)i*(ll)(i+1) - (ll)k * (ll)(a[i]|a[i+1]));
	// 	// 	}
	// 	// }
	 	printf("%lld\n", ans);
	// }
	// for (n = 20000; n <= 20000; n++) {
	// 	for (k = 1; k <= min(n,100); ++k) {
	// 		ll ans=0;
	// 		bool ok=false;
	// 		for (int i = 1; i <= n; ++i) {
	// 			a[i] = rand() % (n+1);
	// 		}
	// 		int i1=-1,i2=-1;
	// 		for (int i = 1; i <= n; ++i) {
	// 			for (int j = i+1; j <= n; ++j) {
	// 				//ans = max(ans, i*j-k*(a[i]|a[j]));
	// 				if (!ok || (ll)i*(ll)j-(ll)k*(ll)(a[i]|a[j]) >= ans) {
	// 					ans = (ll)i*(ll)j-(ll)k*(ll)(a[i]|a[j]);
	// 					i1 = i;
	// 					i2 = j;
	// 					ok=true;
	// 				}
	// 			}
	// 		}
	// 		cout<<n<<" "<<k<<" "<<i1<<" "<<i2<<" "<<ans<<endl;
	// 	}
	}
  return 0;
}
