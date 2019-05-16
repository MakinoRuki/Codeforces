#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long ll;
int n,m;
vector<ll> b, g;
int main() {
	cin>>n>>m;
	b.clear();
	ll bmax = -1;
	for (int i = 0; i < n; ++i) {
		ll bv;
		cin>>bv;
		b.push_back(bv);
		bmax = max(bmax, bv);
	}
	bool ok = true;
	for (int j = 0; j < m; ++j) {
		ll gv;
		cin>>gv;
		g.push_back(gv);
		if (gv < bmax) {
			ok = false;
		}
	}
	if (!ok) {
		cout<<-1<<endl;
	} else {
		sort(b.begin(), b.end());
		sort(g.begin(), g.end());
		ll ans = 0LL;
		for (int i = 0; i < b.size(); ++i) {
			ans += b[i] * m;
		}
		for (int i = g.size() - 1; i > 0; --i) {
			ans += g[i] - b.back();
		}
		if (g[0] > b.back()) {
			ans += g[0] - b[b.size() - 2];
		}
		cout<<ans<<endl;
	}
	return 0;
}
