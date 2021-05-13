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
#define M 25
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int r[N], c[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &r[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
		}
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			rk.push_back(make_pair(r[i], c[i]));
		}
		sort(rk.begin(), rk.end());
		if (!(rk[0].first==1 && rk[0].second==1)) {
			reverse(rk.begin(), rk.end());
			rk.push_back(make_pair(1,1));
			reverse(rk.begin(), rk.end());
		}
		ll ans = 0LL;
		for (int i = 1; i < rk.size(); ++i) {
			ll rd = rk[i].first-rk[i-1].first;
			ll x = rk[i-1].first;
			ll y = rk[i-1].second;
			ll x2 = rk[i].first;
			ll y2 = rk[i].second;
			if ((x+y)%2==0) {
				if (rd-1 == y2 - y) {
					continue;
				} else if (rd - 1 < y2 -y) {
					ans += rd;
				} else {
					ll det = (rd-1-(y2-y));
					ans += (det+1)/2;
				}
			} else {
				if (rd == y2-y) {
					continue;
				} else if (rd > y2-y) {
					ll det = (rd - (y2-y));
					ans += (det+1)/2;
				}
			}
		}
		printf("%lld\n", ans);
	}
  return 0;
}
