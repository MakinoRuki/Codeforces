#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 300005
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, q, m;
int a[N];
vector<int> idx[N];
struct node {
	int l, r;
	int id;
} tree[N<<2];
int calc(int l, int r, int id) {
	int x = a[id];
	int lb = lower_bound(idx[x].begin(), idx[x].end(), l) - idx[x].begin();
	if (lb >= idx[x].size()) return 0;
	int rb = upper_bound(idx[x].begin(), idx[x].end(), r) - idx[x].begin();
	if (rb <= lb) return 0;
	return rb-lb;
}
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	if (l == r) {
		tree[id].id = l;
		return ;
	}
	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	int id1 = tree[id*2].id;
	int id2 = tree[id*2+1].id;
	if (calc(l, r, id1) > calc(l, r, id2)) {
		tree[id].id = id1;
	} else {
		tree[id].id = id2;
	}
}
int query(int id, int l, int r) {
	if (tree[id].l == l && tree[id].r == r) {
		return tree[id].id;
	}
	int mid = (tree[id].l + tree[id].r) / 2;
	if (r <= mid) {
		return query(id*2, l, r);
	} else if (l > mid) {
		return query(id*2+1, l, r);
	} else {
		int id1 = query(id*2, l, mid);
		int id2 = query(id*2+1, mid+1, r);
		if (calc(l, r, id1) > calc(l, r, id2)) {
			return id1;
		}
		return id2;
	}
}
int main() {
	cin>>n>>q;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		idx[a[i]].push_back(i);
	}
	build(1, 1, n);
	while(q-->0) {
		int l, r;
		scanf("%d%d", &l, &r);
		int id = query(1, l, r);
		int len = (r-l+1);
		int res = calc(l, r, id);
		if (res <= (len+1)/2) {
			cout<<1<<endl;
		} else {
			printf("%d\n", 2*res-len);
		}
	}
	return 0;
}

/*myturn.ca.gov*/
