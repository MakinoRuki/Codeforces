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
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, s;
int a[N];
int main() {
	cin>>n>>s;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll l = 0, r = n;
	while(l < r) {
		ll mid=(l+r+1)/2;
		vector<ll> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back((ll)a[i]+(ll)i*mid);
		}
		sort(rk.begin(), rk.end());
		ll tot=0LL;
		for (int i = 0; i < mid; ++i) {
			tot += rk[i];
		}
		if (tot <= s) {
			l = mid; 
		} else {
			r = mid-1;
		}
	}
	vector<ll> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		rk.push_back((ll)a[i]+(ll)i*r);
	}
	sort(rk.begin(), rk.end());
	ll tot=0LL;
	for (int i = 0; i < r; ++i) {
		tot += rk[i];
	}
	printf("%lld %lld\n", r, tot);
	return 0;
}
