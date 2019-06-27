#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300010
#define M 1000005
using namespace std;
int n, m;
int a[N], b[N];
int q;
struct node {
	int l, r;
	int sum, maxs;
}tree[M * 4];
void init(int idx, int l, int r) {
	tree[idx].l = l;
	tree[idx].r = r;
	if (l == r) {
		tree[idx].sum = 0;
		tree[idx].maxs = 0;
		return;
	}
	int m = (l + r) / 2;
	init(idx*2, l, m);
	init(idx*2+1, m+1, r);
	tree[idx].sum = 0;
	tree[idx].maxs = 0;
}
void update(int idx, int p, int v) {
	if (tree[idx].l == tree[idx].r) {
		tree[idx].sum += v;
		tree[idx].maxs += v;
		return;
	}
	int m = (tree[idx].l+tree[idx].r) / 2;
	if (p <= m) update(idx*2, p, v);
	else update(idx*2+1, p, v);
	tree[idx].sum = tree[idx*2].sum+tree[idx*2+1].sum;
	tree[idx].maxs = max(tree[idx*2+1].maxs, tree[idx*2].maxs + tree[idx*2+1].sum);
}
int query(int idx, int ssum) {
	if (tree[idx].l == tree[idx].r) {
		return tree[idx].l;
	}
	if (ssum + tree[idx*2+1].maxs > 0) {
		return query(idx*2+1, ssum);
	} else {
		return query(idx*2, ssum + tree[idx*2+1].sum);
	}
}
int main() {
	cin>>n>>m;
	init(1, 1, M-1);
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		update(1, a[i], 1);
		//cout<<tree[1].sum<<" "<<tree[1].maxs<<endl;
	}
	for (int i = 1; i <= m; ++i) {
		cin>>b[i];
		update(1, b[i], -1);
		//cout<<tree[1].sum<<" "<<tree[1].maxs<<endl;
	}
	cin>>q;
	for (int i = 0; i < q; ++i) {
		int t, idx, x;
		cin>>t>>idx>>x;
		if (t == 1) {
			update(1, a[idx], -1);
			update(1, x, 1);
			a[idx] = x;
		} else {
			update(1, b[idx], 1);
			update(1, x, -1);
			b[idx] = x;
		}
		if (tree[1].maxs <= 0) {
			cout<<"-1"<<endl;
		} else {
			int ans = query(1, 0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
