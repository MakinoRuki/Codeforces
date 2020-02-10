#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 1000005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll a[N];
int main() {
	cin>>n;
	vector<pair<ll, int>> stk;
	stk.clear();
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		ll v = a[i];
		int cnt= 1;
		while(!stk.empty()) {
			auto cur = stk.back();
			ll v2 = cur.first;
			int cnt2 = cur.second;
			if (v2 * (ll)cnt > v * (ll)cnt2) {
				v += v2;
				cnt += cnt2;
				stk.pop_back();
			} else {
				break;
			}
		}
		stk.push_back(make_pair(v, cnt));
	}
	vector<double> ans(n+1, 0.0);
	int idx=0;
	for(int i = 0; i < stk.size(); ++i) {
		for (int j = 0; j < stk[i].second; ++j) {
			double v = (double)stk[i].first / (double)stk[i].second;
			ans[idx++] = v;
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.10lf\n", ans[i]);
	}
	return 0;
}
