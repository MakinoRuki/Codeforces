#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
int n, m;
ll det[N];
int main() {
	cin>>n>>m;
	memset(det, 0, sizeof(det));
	for (int i = 0; i < m; ++i) {
		int u, v, d;
		cin>>u>>v>>d;
		det[u] -= d;
		det[v] += d;
	}
	vector<pair<ll, int>> rk;
	rk.clear();
	for (int i =1; i <= n; ++i) {
		if (det[i]) {
			rk.push_back(make_pair(det[i], i));
		}
	}
	sort(rk.begin(), rk.end());
	vector<pair<pair<int, int>, ll> > ans;
	ans.clear();
	int l = 0, r = rk.size()-1;
  // 知道每个人的负债之后，正负相抵。两个指针扫。
	while(l < r) {
		ll al = abs(rk[l].first);
		ll ar = abs(rk[r].first);
		ll add = min(al, ar);
		ans.push_back(make_pair(make_pair(rk[l].second, rk[r].second), add));
		if (add == abs(rk[l].first)) l++;
		else {
			rk[l].first += add;
		}
		if (add == abs(rk[r].first)) r--;
		else {
			rk[r].first -= add;
		}
	}
	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i].first.first<<" " <<ans[i].first.second<<" "<<ans[i].second<<endl;
	}
	return 0;
}
