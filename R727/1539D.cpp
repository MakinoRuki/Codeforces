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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int q, n;
ll a[N], b[N];
// struct cmp {
// 	bool operator()(const pair<ll,ll>& p1, const pair<ll,ll>& p2) const {
// 		return min(p2.first, p1.second)
// 	}
// }
int main() {
	cin>>n;
	multiset<pair<ll,ll>> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &a[i], &b[i]);
		ss.insert(make_pair(b[i], a[i]));
	}
	ll ans = 0LL;
	ll cur = 0LL;
	while(!ss.empty()) {
		auto pr1 = *ss.rbegin();
		auto pr2 = *ss.begin();
		if (cur >= pr2.first) {
			ans += pr2.second;
			cur += pr2.second;
			ss.erase(ss.begin());
		} else {
			ll det = min(pr1.second, pr2.first - cur);
			ans += 2LL * det;
			cur += det;
			ss.erase(--ss.end());
			if (pr1.second > det) {
				ss.insert(make_pair(pr1.first, pr1.second-det));
			}
		}
	//	cout<<"x="<<cur<<" "<<ans<<endl;
	}
	printf("%lld\n", ans);
  return 0;
}
