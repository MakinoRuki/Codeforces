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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
ll a[N];
ll sum[N];
int main() {
	cin>>n>>q;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(sum, 0LL, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + a[i];
	}
	ll cur=0LL;
	for (int i = 1; i <= q; ++i) {
		ll k;
		scanf("%lld", &k);
		int l = 1, r = n+1;
		while(l<r) {
			int mid=(l+r)/2;
			if (sum[mid] > cur+k) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		if (r > n) {
			printf("%d\n", n);
			cur=0LL;
		} else {
			printf("%d\n", n-r+1);
			cur+=k;
		}
	}
	return 0;
}
