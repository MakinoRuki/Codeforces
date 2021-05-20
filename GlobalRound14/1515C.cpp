#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m, x;
int h[N];
int sum[N];
int ans[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &m, &x);
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &h[i]);
			rk.push_back(make_pair(h[i], i));
		}
		sort(rk.begin(), rk.end());
		set<pair<int,int>> ss;
		ss.clear();
		for (int i = 1; i <= m; ++i) {
			ss.insert(make_pair(0, i));
			sum[i] = 0;
		}
		for (int i = 0; i < rk.size(); ++i) {
			int id = rk[i].second;
			auto top = *ss.begin();
			int x = top.first;
			int y = top.second;
			ans[id] = y;
			x += h[id];
			ss.erase(ss.begin());
			ss.insert(make_pair(x, y));
		}
		for (int i = 1; i <= n; ++i) {
			sum[ans[i]] += h[i];
		}
		bool ok=true;
		vector<int> rk2;
		rk2.clear();
		for (int i = 1; i <= m; ++i) {
			rk2.push_back(sum[i]);
		}
		sort(rk2.begin(), rk2.end());
		for (int i = 1; i < rk2.size(); ++i) {
			if (rk2[i] - rk2[i-1] > x) {
				ok=false;
				break;
			}
		}
		if (!ok) puts("NO");
		else {
			puts("YES");
			for (int i = 1; i <= n; ++i) {
				printf("%d", ans[i]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
