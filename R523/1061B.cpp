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
int n;
ll m;
int main() {
	cin>>n>>m;
	map<ll, int> cnt;
	cnt.clear();
	ll maxv = 0LL;
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		ll a;
		scanf("%lld", &a);
		cnt[a]++;
		tot += a;
	}
	vector<pair<ll,int>> vs;
	vs.clear();
	for (auto itr : cnt) {
		vs.push_back(make_pair(itr.first, itr.second));
	}
	sort(vs.begin(), vs.end());
	ll pre = 0LL;
	ll tot2=0LL;
	for (int i = vs.size()-1; i>=0; --i) {
		if (i>0) {
			ll det = vs[i].first - vs[i-1].first;
			ll x = vs[i].second;
			if (det > x) {
				tot2 += x;
				det -= x;
				ll z = min(det, pre);
				tot2 += z;
				det -= z;
				pre -= z;
				tot2 += det;
			} else {
				tot2 += det;
				pre += x-det;
			}
		} else {
			ll det = vs[i].first;
			ll x = vs[i].second;
			if (det > x) {
				tot2 += x;
				det -= x;
				ll z = min(det, pre);
				tot2 += z;
				det -= z;
				pre -= z;
				tot2 += det;
			} else {
				tot2 += det;
				pre += x- det;
			}
		}
	}
	if (pre) tot2 += pre;
	printf("%lld\n", tot - tot2);
	return 0;
}
