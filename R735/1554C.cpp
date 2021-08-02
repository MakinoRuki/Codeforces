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
int t, n, m, l, r, k;
string s;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		ll l = 0, r = m;
		ll pre = 0LL;
		ll ans = 0LL;
		for (int i = 30; i >= 0; --i) {
			ll mid = pre + (1LL<<i);
			if (mid <= l) {
				if ((1LL<<i)&n) {
					if (r-l+1 == (1LL<<i)) {
						ans |= (1LL<<i);
						break;
					} else {
						pre |= (1LL<<i);
					}
				} else {
					break;
				}
			} else if (mid > r) {
				if ((1LL<<i)&n) {
					break;
				} else {
					if (r-l+1 == (1LL<<i)) {
						ans |= (1LL<<i);
						break;
					}
					//if (i > 2) cout<<"x"<<endl;
				}
			} else {
				ll n0 = mid - l;
				ll n1 = r-l+1-n0;
				if ((1LL<<i)&n) {
					if (n1 == (1LL<<i)) {
						ans |= (1LL<<i);
						r = mid-1;
					} else {
						l = mid;
						pre |= (1LL<<i);
					}
				} else {
					if (n0 == (1LL<<i)) {
						l = mid;
						pre |= (1LL<<i);
						ans |= (1LL<<i);
					} else {
						r = mid-1;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
