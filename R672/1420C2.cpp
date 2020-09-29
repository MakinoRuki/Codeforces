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
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n,q;
int a[N];
ll getdet(int id) {
	if (id < 1 || id > n) {
		return 0;
	}
	if (id==1) {
		if (id+1<=n) {
			if (a[id]>a[id+1]) {
				return a[id];
			}
			return 0;
		}
		return a[id];
	}
	if (id == n) {
		if (id-1>=1) {
			if (a[id]>a[id-1]) {
				return a[id];
			}
			return 0;
		}
		return a[id];
	}
	if (a[id]>a[id-1] && a[id]>a[id+1]) {
		return a[id];
	}
	if (a[id]<a[id-1] && a[id]<a[id+1]) {
		return -a[id];
	}
	return 0;
}
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll ans=0LL;
		for (int i = 1; i <= n; ++i) {
			ans += getdet(i);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= q; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			ans -= getdet(l-1);
			ans -= getdet(l);
			ans -= getdet(l+1);
			for (int j = -1; j <= 1; ++j) {
				if (r+j > l+1) {
					ans -= getdet(r+j);
				}
			}
			swap(a[l], a[r]);
			ans += getdet(l-1);
			ans += getdet(l);
			ans += getdet(l+1);
			for (int j = -1; j <= 1; ++j) {
				if (r+j > l+1) {
					ans += getdet(r+j);
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
