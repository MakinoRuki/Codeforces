#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#define N 500005
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int t,n,m;
ll c[N];
vector<int> edges[N];
ll getgcd(ll x, ll y) {
	return y == 0 ? x : getgcd(y, x%y);
}
int main() {
	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n,&m);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &c[i]);
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d%d",&u,&v);
			edges[v].push_back(u);
		}
		map<vector<int>, ll> tot;
		tot.clear();
		for (int i = 1; i <= n; ++i) {
			auto v = edges[i];
			if (v.empty()) continue;
			sort(v.begin(), v.end());
			tot[v] += c[i];
		}
		ll ans=0LL;
		for (auto x : tot) {
			ans = getgcd(ans, x.second);
		}
		printf("%lld\n", ans);
		for (int i =1; i <= n; ++i) {
			edges[i].clear();
		}
	}
	return 0;
}
