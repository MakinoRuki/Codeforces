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
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
ll a[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	cin>>q;
	ll res=a[1];
	for (int i = n; i >= 2; --i) {
		a[i] -= a[i-1];
		if (a[i] >= 0) {
			res += a[i];
		}
	}
	ll res2 = (res+1)/2;
	if (res<0) {
		res2=res/2;
	}
	printf("%lld\n", res2);
	for (int i =1 ; i <= q; ++i) {
		int l,r,x;
		scanf("%d%d%d", &l,&r,&x);
		if (l==1) {
			res += x;
			a[1] += x;
		} else {
			if (a[l] >= 0) {
				res -= a[l];
			}
			a[l] += x;
			if (a[l] >= 0) {
				res += a[l];
			}
		}
		if (r+1<=n) {
			if (a[r+1]>=0) {
				res -= a[r+1];
			}
			a[r+1] -= x;
			if (a[r+1] >= 0) {
				res += a[r+1];
			}
		}
		res2=(res+1)/2;
		if (res<0) {
			res2=res/2;
		}
		printf("%lld\n", res2);
	}
	return 0;
}
