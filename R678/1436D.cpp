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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
int a[N];
pair<ll, bool> dfs(int u, int p, ll ub) {
	ll det=0LL;
	if (edges[u].empty()) {
		if (a[u]<=ub) {
			return make_pair(ub-a[u], true);
		} else {
			return make_pair(a[u]-ub, false);
		}
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		auto res=dfs(v, u, ub);
		if (!res.second) {
			return make_pair(-1, false);
		}
		det += res.first;
		if (det>2LL*1000000000000000LL) {
			det=2LL*1000000000000000LL;
		}
	}
	if (a[u]<=det) {
		if (det-a[u]>2LL*1000000000000000LL) {
			return make_pair(2LL*1000000000000000LL, true);
		} else {
			return make_pair(det-a[u], true);
		}
	}
	return make_pair(-1, false);
}
int main() {
	cin>>n;
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		edges[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	ll l=0,r=1000000000000000LL;
	while(l<r) {
		ll mid=(l+r)/2;
		auto res=dfs(1, 0, mid);
		if (res.second) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	cout<<r<<endl;
	return 0;
}
