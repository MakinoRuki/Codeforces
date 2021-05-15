#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, a, b;
vector<pair<int,int>> hd;
bool vis[N];
int main() {
	cin>>n>>a>>b;
	hd.clear();
	ll tot=0LL;
	set<pair<ll,int>> ss;
	ss.clear();
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		int hp, dmg;
		scanf("%d%d", &hp, &dmg);
		tot += (ll)dmg;
		hd.push_back(make_pair(hp, dmg));
		ss.insert(make_pair(hp-dmg, i));
	}
	if (b == 0) {
		printf("%lld\n", tot);
		return 0;
	}
	while(ss.size() > b) {
		ss.erase(ss.begin());
	}
	while(!ss.empty() && (*ss.begin()).first < 0) {
		ss.erase(ss.begin());
	}
	for (auto itr : ss) {
		tot += itr.first;
	}
	if (a == 0) {
		printf("%lld\n", tot);
		return 0;
	}
	ll ans = tot;
	for (int i = 0; i < n; ++i) {
		int hp = hd[i].first;
		int dmg = hd[i].second;
		ll hp2 = hp;
		for (int j = 1; j <= a; ++j) {
			hp2 = hp2 * 2LL;
		}
		if (hp2-dmg <= 0) {
			continue;
		}
		if (ss.find(make_pair(hp-dmg, i)) != ss.end()) {
			ll tot2 = tot - (ll)(hp-dmg) + (ll)(hp2-dmg);
			ans = max(ans, tot2);
		} else {
			if (ss.size() < b) {
				ll tot2 = tot + hp2-(ll)dmg;
				ans = max(ans, tot2);
			} else {
				auto pr = (*ss.begin());
				if (pr.first < hp2-(ll)dmg) {
					ll tot2 = tot - pr.first + (hp2-(ll)dmg);
					ans = max(ans, tot2);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
