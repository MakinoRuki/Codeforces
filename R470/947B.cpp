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
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll v[N], t[N];
ll a[N], b[N];
ll sum[N];
int main() {
	cin>>n;
	memset(sum, 0LL, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &v[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &t[i]);
		sum[i] = sum[i-1] + t[i];
	}
	memset(a, 0LL, sizeof(a));
	memset(b, 0LL, sizeof(b));
	for (int i = 1; i <= n; ++i) {
		int l = i, r = n+1;
		while(l < r) {
			int mid = (l+r)/2;
			if (sum[mid] - sum[i-1] >= v[i]) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (r <= n) {
			a[r] += (sum[r]-sum[i-1]-v[i]);
		//	cout<<i<<" "<<r<<" "<<a[r]<<endl;
			b[r+1]++;
		}
	}
	ll cnt = 0;
	for (int i = 1; i <= n; ++i) {
		ll tot = (ll)i * t[i];
		tot -= a[i];
		cnt += b[i];
		tot -= cnt*t[i];
		printf("%lld", tot);
		if (i < n) cout<<" ";
		else cout<<endl;
	}
  return 0;
}
