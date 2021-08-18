#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<pair<int,int>> segs[N];
int tot;
int dp[N];
int pre[N];
struct node {
	int l, r;
	int lazy;
	int maxv;
} tree[N<<3];
vector<pair<int,int>> mergeseg(vector<pair<int,int>>& sgs) {
	sort(sgs.begin(), sgs.end());
	vector<pair<int,int>> res;
	res.clear();
	int b=-1,e=-1;
	for (int i = 0; i < sgs.size(); ++i) {
		int l = sgs[i].first;
		int r = sgs[i].second;
		if (i == 0) {
			b=l;
			e=r;
		} else {
			if (l <= e && r >= b) {
				b = min(b, l);
				e = max(e, r);
			} else {
				res.push_back(make_pair(b, e));
				b = l;
				e = r;
			}
		}
	}
	if (b >= 0 && e >= 0) {
		res.push_back(make_pair(b,e));
	}
	return res;
}
void pushdown(int id) {
	int val = tree[id].lazy;
	tree[id].lazy = -1;
	if (tree[id].l == tree[id].r) {
		return;
	}
	if ((tree[id*2].lazy < 0) || (dp[val] > dp[tree[id*2].lazy])) {
		tree[id*2].lazy = val;
	}
	if (dp[val] > dp[tree[id*2].maxv]) {
		tree[id*2].maxv = val;
	}
	if ((tree[id*2+1].lazy < 0) || (dp[val] > dp[tree[id*2+1].lazy])) {
		tree[id*2+1].lazy = val;
	}
	if (dp[val] > dp[tree[id*2+1].maxv]) {
		tree[id*2+1].maxv = val;
	}
}
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	tree[id].lazy = -1;
	tree[id].maxv = 0;
	if (l == r) {
		return;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
}
int query(int id, int l, int r) {
	if (l <= tree[id].l && r >= tree[id].r) {
		return tree[id].maxv;
	}
	if (tree[id].lazy >= 0) {
		pushdown(id);
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) return query(id*2, l, r);
	else if (l > mid) return query(id*2+1, l, r);
	else {
		//return max(query(id*2, l, mid), query(id*2+1, mid+1, r));
		int id1 = query(id*2, l, mid);
		int id2 = query(id*2+1, mid+1, r);
		if (dp[id1] > dp[id2]) {
			return id1;
		} else {
			return id2;
		}
	}
}
void update(int id, int l, int r, int val) {
	if (l <= tree[id].l && r >= tree[id].r) {
	//	tree[id].lazy = max(tree[id].lazy, val);
	//	tree[id].maxv = max(tree[id].maxv, val);
		if ((tree[id].lazy < 0) || (dp[val] > dp[tree[id].lazy])) {
			tree[id].lazy = val;
		}
		if (dp[val] > dp[tree[id].maxv]) {
			tree[id].maxv = val;
		}
		return;
	}
	if (tree[id].lazy >= 0) {
		pushdown(id);
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) {
		update(id*2, l, r, val);
	} else if (l > mid) {
		update(id*2+1, l, r, val);
	} else {
		update(id*2, l, mid, val);
		update(id*2+1, mid+1, r, val);
	}
	if (dp[tree[id*2].maxv] > dp[tree[id*2+1].maxv]) {
		tree[id].maxv = tree[id*2].maxv;
	} else {
		tree[id].maxv = tree[id*2+1].maxv;
	}
	//tree[id].maxv = max(tree[id*2].maxv, tree[id*2+1].maxv);
}
int main() {
	cin>>n>>m;
	memset(dp, 0, sizeof(dp));
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= n; ++i) {
		segs[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int row, l ,r;
		scanf("%d%d%d", &row, &l, &r);
		segs[row].push_back(make_pair(l, r));
	}
	set<int> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		auto v = mergeseg(segs[i]);
		segs[i].clear();
		for (int j = 0; j < v.size(); ++j) {
			segs[i].push_back(v[j]);
			ss.insert(v[j].first);
			ss.insert(v[j].second);
		}
	}
	vector<int> ps(ss.begin(), ss.end());
	tot = (int)ps.size();
	build(1, 1, tot);
	int ans=0;
	int aid = 0;
	for (int i = 1; i <= n; ++i) {
		int val = 0;
		int id = 0;
		for (int j = 0; j < segs[i].size(); ++j) {
			int l = lower_bound(ps.begin(), ps.end(), segs[i][j].first)-ps.begin()+1;
			int r = lower_bound(ps.begin(), ps.end(), segs[i][j].second)-ps.begin()+1;
			auto id2 = query(1, l, r);
			if (dp[id2] > val) {
				val = dp[id2];
				id = id2;
			}
		}
		dp[i] = val+1;
		pre[i] = id;
		//ans = max(ans, val+1);
		if (val + 1 > ans) {
			ans = val + 1;
			aid = i;
		}
		for (int j = 0; j < segs[i].size(); ++j) {
			int l = lower_bound(ps.begin(), ps.end(), segs[i][j].first)-ps.begin()+1;
			int r = lower_bound(ps.begin(), ps.end(), segs[i][j].second)-ps.begin()+1;
			update(1, l, r, i);
		}
	}
	printf("%d\n", n-ans);
	set<int> ss2;
	ss2.clear();
	int cid = aid;
	while(cid) {
		ss2.insert(cid);
		cid = pre[cid];
	}
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		if (ss2.find(i) == ss2.end()) {
			printf("%d", i);
			cnt++;
			if (cnt < n-(int)ss2.size()) {
				cout<<" ";
			} else {
				cout<<endl;
			}
		}
	}
  return 0;
}
