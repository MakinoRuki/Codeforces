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
#define N 100005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N];
int BIT[N];
int main() {
	cin>>n;
	ll ans=0LL;
	map<int,int> pos;
	pos.clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (pos.find(a[i]) == pos.end()) {
			pos[a[i]] = i;
		}
	}
	vector<pair<int,int>> rk;
	rk.clear();
	for (auto itr : pos) {
		rk.push_back(make_pair(itr.second, itr.first));
	}
	sort(rk.begin(), rk.end());
	map<int, int> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		ss[a[i]]++;
	}
	int j=1;
	for (int i = 0; i < rk.size(); ++i) {
		int id=rk[i].first;
		while(j <= id) {
			ss[a[j]]--;
			if (ss[a[j]] == 0) {
				ss.erase(a[j]);
			}
			j++;
		}
		ans += (ll)ss.size();
	}
	printf("%lld\n", ans);
	return 0;
}
