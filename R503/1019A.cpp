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
#define N 3002
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int p[N], c[N];
vector<int> ps[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i], &c[i]);
		ps[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; ++i) {
		sort(ps[i].begin(), ps[i].end());
	}
	ll ans = (1LL<<61);
	for (int i = max(1, (int)ps[1].size()); i <= n; ++i) {
		ll tot=0LL;
		vector<int> rk;
		rk.clear();
		int cnt=0;
		for (int j = 2; j <= m; ++j) {
			if (ps[j].size() >= i) {
				int det=ps[j].size()-i+1;
				cnt += det;
				for (int k = 0; k < det; ++k) {
					tot += ps[j][k];
				}
				for (int k = det; k < ps[j].size(); ++k) {
					rk.push_back(ps[j][k]);
				}
			} else {
				for (int k = 0; k < ps[j].size(); ++k) {
					rk.push_back(ps[j][k]);
				}
			}
		}
		if (ps[1].size() + cnt >= i) {
			ans = min(ans, tot);
		} else {
			sort(rk.begin(), rk.end());
			int det=i-ps[1].size()-cnt;
			if (det > rk.size()) {
				continue;
			}
			for (int j = 0; j < det; ++j) {
				tot += rk[j];
			}
			ans = min(ans, tot);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
