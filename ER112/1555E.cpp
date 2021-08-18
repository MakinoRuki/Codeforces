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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<pair<int,pair<int,int>>> segs;
struct node {
	int l, r;
	int tot, lazy;
} tree[N<<2];
void pushdown(int id) {
	int val = tree[id].lazy;
	tree[id].lazy = 0;
	if (tree[id].l==tree[id].r) {
		return;
	}
	tree[id*2].lazy += val;
	tree[id*2].tot += val;
	tree[id*2+1].lazy += val;
	tree[id*2+1].tot += val;
}
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	tree[id].tot = 0;
	tree[id].lazy = 0;
	if (l == r) return ;
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
}
void update(int id, int l, int r, int det) {
	if (tree[id].lazy != 0) {
		pushdown(id);
	}
	if (l <= tree[id].l && r >= tree[id].r) {
		tree[id].lazy = det;
		tree[id].tot += det;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) {
		update(id*2, l, r, det);
	} else if (l > mid) {
		update(id*2+1, l, r, det);
	} else {
		update(id*2, l, mid, det);
		update(id*2+1, mid+1, r, det);
	}
	tree[id].tot = min(tree[id*2].tot, tree[id*2+1].tot);
}
int query(int id, int l, int r) {
	if (tree[id].lazy != 0) {
		pushdown(id);
	}
	if (l <= tree[id].l && r >= tree[id].r) {
		return tree[id].tot;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) {
		return query(id*2, l, r);
	} else if (l > mid) {
		return query(id*2+1, l, r);
	} else {
		return min(query(id*2,l ,mid), query(id*2+1, mid+1,r));
	}
}
int main() {
	cin>>n>>m;
	build(1, 1, m-1);
	segs.clear();
	for (int i = 1; i <= n; ++i) {
		int l,r,w;
		scanf("%d%d%d", &l, &r, &w);
		segs.push_back(make_pair(w, make_pair(l,r)));
	}
	sort(segs.begin(), segs.end());
	int ans = INT_MAX;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		int l1 = segs[i].second.first;
		int r1 = segs[i].second.second;
		int w1 = segs[i].first;
		update(1, l1, r1-1, 1);
		while(j <= i) {
			int l2 = segs[j].second.first;
			int r2 = segs[j].second.second;
			int w2 = segs[j].first;
			int res = query(1, 1, m-1);
			if (res > 0) {
				ans = min(ans, w1-w2);
				update(1, l2, r2-1, -1);
				j++;
			} else {
				break;
			}
		}
	}
	printf("%d\n", ans);
  return 0;
}
