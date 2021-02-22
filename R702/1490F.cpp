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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int sum[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		map<int, int> cnt;
		cnt.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		vector<int> rk;
		rk.clear();
		for (auto itr : cnt) {
			rk.push_back(itr.second);
		}
		sort(rk.begin(), rk.end());
		vector<pair<int,int>> rk2;
		rk2.clear();
		for (int i = 0; i < rk.size(); ++i) {
			if (i == 0 || rk[i] != rk[i-1]) {
				rk2.push_back(make_pair(rk[i], 1));
			} else {
				rk2.back().second++;
			}
		}
		for (int i = 0; i <= n; ++i) {
			sum[i] = 0;
		}
		for (int i = 1; i <= rk2.size(); ++i) {
			sum[i] = sum[i-1] + rk2[i-1].second*rk2[i-1].first;
		}
		ll ans = n;
		ll pre = 0;
		ll num=0LL;
		int sz=(int)rk2.size();
		for (int i = sz; i >= 1; --i) {
			pre += num * (ll)(rk2[i].first-rk2[i-1].first);
			ans = min(ans, pre + sum[i-1]);
			num += rk2[i-1].second;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
