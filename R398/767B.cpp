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
int t, n;
int k;
int q;
ll ts, tf, tt;
ll sev[N];
void update(ll& ans, ll& wt, ll cur, ll tt) {
	if (ans < 0) {
		ans = cur;
		wt = tt;
	} else {
		if (tt < wt) {
			ans = cur;
			wt = tt;
		}
	}
}
int main() {
	vector<pair<ll,int>> qs;
	qs.clear();
	cin>>ts>>tf>>tt;
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		ll tm;
		scanf("%lld", &tm);
		if (qs.empty() || qs.back().first != tm) {
			qs.push_back(make_pair(tm, 1));
		} else {
			qs.back().second++;
		}
	}
	sev[0] = ts;
	for (int i = 0; i < qs.size(); ++i) {
		if (qs[i].first < sev[i]) {
			sev[i+1] = sev[i] + qs[i].second * tt;
		} else {
			sev[i+1] = qs[i].first + qs[i].second * tt;
		}
	}
	ll ans = -1;
	ll wt = -1;
	for (int i = 1; i <= qs.size(); ++i) {
		ll pre = sev[i-1];
		ll cur = qs[i-1].first - 1;
		if (pre + tt <= tf && cur + tt <= tf) {
			if (pre < cur) {
				update(ans, wt, cur, tt);
			} else {
				update(ans, wt, cur, pre-cur+tt);
			}
		}
	}
	if (sev[qs.size()] + tt <= tf) {
		update(ans, wt, sev[qs.size()], tt);
	}
	if (qs.size() > 0 && qs[0].first-1 > ts) {
		update(ans, wt, ts, tt);
	}
	cout<<ans<<endl;
  return 0;
}
