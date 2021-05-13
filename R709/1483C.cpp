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
#define M 25
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int h[N];
ll b[N];
ll dp[N];
ll dp2[N];
struct node {
	int l, r;
	ll maxv;
} tree[N<<2];
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	tree[id].maxv = -(1LL<<60);
	if (l == r) {
		return ;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
}
ll query(int id, int l, int r) {
	if (tree[id].l == l && tree[id].r) {
		return tree[id].maxv;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) {
		return query(id*2, l, r);
	} else if (l > mid) {
		return query(id*2+1, l, r);
	} else {
		return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
	}
}
void update(int id, int pos, ll val) {
	if (tree[id].l == tree[id].r) {
		tree[id].maxv = val;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (pos <= mid) {
		update(id*2, pos, val);
	} else {
		update(id*2+1, pos, val);
	}
	tree[id].maxv=max(tree[id*2].maxv, tree[id*2+1].maxv);
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &b[i]);
	}
	vector<int> ids;
	ids.clear();
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		dp[i] = -(1LL<<60);
		while(!ids.empty() && h[i] <= h[ids.back()]) {
			ids.pop_back();
		}
		if (ids.empty()) {
			dp[i] = max(dp[i], b[i]);
			if (i>1) dp[i] = max(dp[i], query(1, 1, i-1)+b[i]);
		} else {
			dp[i] = max(dp[i], query(1, ids.back(), i-1)+b[i]);
			dp[i] = max(dp[i], dp2[ids.back()]);
		}
		dp2[i] = dp[i];
		if (!ids.empty()) {
			dp2[i] = max(dp2[i], dp2[ids.back()]);
		}
		ids.push_back(i);
		update(1, i, dp[i]);
	}
	printf("%lld\n", dp2[n]);
  return 0;
}
