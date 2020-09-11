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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
ll t;
ll a[N];
int BIT[N];
int id[N];
int cnt=0;
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, int val) {
	while(pos <= cnt) {
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos > 0) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>n>>t;
	vector<pair<ll, int>> rk;
	rk.clear();
	rk.push_back(make_pair(0, 0));
	ll pre=0LL;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		pre += a[i];
		rk.push_back(make_pair(pre, i));
	}
	sort(rk.begin(), rk.end());
	cnt=1;
	map<ll, int> mp;
	mp.clear();
	for (int i = 0; i < rk.size(); ++i) {
		int p=rk[i].second;
		if (i==0) {
			id[p] = cnt;
		} else {
			if (rk[i].first != rk[i-1].first) {
				cnt++;
			}
			id[p] = cnt;
		}
		mp[rk[i].first] = cnt;
	}
	memset(BIT, 0LL, sizeof(BIT));
	ll ans=0LL;
	update(mp[0], 1);
	pre=0LL;
	for (int i = 1; i <= n; ++i) {
		pre += a[i];
		auto itr = mp.upper_bound(pre-t);
		if (itr != mp.end()) {
			int id1 = itr->second;
			ans += query(cnt) - query(id1-1);
		}
		update(mp[pre], 1);
	}
	printf("%lld\n", ans);
	return 0;
}
