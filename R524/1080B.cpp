#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 500005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int q;
ll l, r;
int main() {
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld", &l, &r);
		ll cnt1=(r-l)/2;
		ll res1 = (l+cnt1)*(cnt1+1);
		if (l%2) res1 = -res1;
		if (l+1<=r) {
			ll cnt2=(r-(l+1))/2;
			ll res2 = (l+1+cnt2)*(cnt2+1);
			if ((l+1)%2) res2 = -res2;
			res1 += res2;
		}
		printf("%lld\n", res1);
	}
	return 0;
}
