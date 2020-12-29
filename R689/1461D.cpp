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
#define eps 1e-7
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, q;
int a[N];
int s[N];
unordered_set<ll> ss;
void dfs(vector<pair<int,ll>>& rk, int l, int r) {
	if (l > r) return ;
	if (l == r) {
		ss.insert(rk[l].second);
		return;
	}
	int mid=(rk[l].first + rk[r].first)/2;
	ll tot=0LL;
	int id = l;
	for (int i = l; i <= r; ++i) {
		tot += rk[i].second;
		if (rk[i].first <= mid) id = i;
	}
	ss.insert(tot);
	dfs(rk, l, id);
	dfs(rk, id+1, r);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		vector<pair<int,ll>> rk;
		rk.clear();
		ll sum=0LL;
		for (int i = 1; i <= n; ++i) {
			if (i==1 || a[i]==a[i-1]) {
				sum += (ll)a[i];
			} else {
				rk.push_back(make_pair(a[i-1], sum));
				sum = a[i];
			}
		}
		rk.push_back(make_pair(a[n], sum));
		ss.clear();
		dfs(rk, 0, rk.size()-1);
		for (int i = 1; i <= q; ++i) {
			scanf("%d", &s[i]);
			if (ss.find(s[i]) != ss.end()) {
				cout<<"Yes"<<endl;
			} else {
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
