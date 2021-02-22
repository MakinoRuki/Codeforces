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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
ll k;
int a[N];
ll sum[N];
int main() {
	cin>>n>>q>>k;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
		while(q-->0) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", k-1);
		}
		return 0;
	}
	memset(sum, 0LL, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		if (i == 1) {
			sum[i] = a[i+1]-1-1;
		} else if (i == n) {
			sum[i] = sum[i-1] + (ll)k-(ll)a[i-1]-1;
		} else {
			sum[i] = sum[i-1] + (ll)a[i+1]-(ll)a[i-1]-2;
		}
	}
	while(q-->0) {
		int l,r;
		scanf("%d%d", &l, &r);
		if (r==l) {
			printf("%lld\n", k-1);
			continue;
		}
		ll tot = max(0LL, sum[r-1]-sum[l]);
		tot += (ll)a[l+1]-2;
		tot += (ll)k-(ll)a[r-1]-1;
		printf("%lld\n", tot);
	}
  return 0;
}
