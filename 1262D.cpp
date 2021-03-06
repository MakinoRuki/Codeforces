#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 200020
using namespace std;
typedef long long ll;
int n, m;
int a[N];
struct node {
	int l, r;
	int sum;
} tree[N<<2];
void build(int idx, int l, int r) {
	tree[idx].l=l;
	tree[idx].r=r;
	if (l == r) {
		tree[idx].sum = 0;
		return ;
	}
	int mid=(l+r)/2;
	build(idx*2, l, mid);
	build(idx*2+1, mid+1, r);
	tree[idx].sum = tree[idx*2].sum+tree[idx*2+1].sum;
}
void update(int idx, int pos) {
	if (tree[idx].l == tree[idx].r) {
		tree[idx].sum = 1;
		return;
	}
	int mid=(tree[idx].l+tree[idx].r)/2;
	if (pos <= mid) update(idx*2, pos);
	else update(idx*2+1, pos);
	tree[idx].sum = tree[idx*2].sum+tree[idx*2+1].sum;
}
int query(int idx, int pos) {
	if (tree[idx].l == tree[idx].r) {
		return tree[idx].l;
	}
	if (tree[2*idx].sum >= pos) {
		return query(idx*2, pos);
	} else {
		return query(idx*2+1, pos-tree[idx*2].sum);
	}
}
int main() {
	cin>>n;
	vector<pair<int, int>> rk;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
    // anyway要取前k大的数。设x=bk，那么所有大于x的数都要选，等于x的选最左边的。
		rk.push_back(make_pair(-a[i], i));
	}
	sort(rk.begin(), rk.end());
	cin>>m;
	vector<pair<int, pair<int, int>>> krk;
	krk.clear();
	for (int i = 0; i < m; ++i) {
		int k, pos;
		cin>>k>>pos;
		krk.push_back(make_pair(k, make_pair(pos, i)));
	}
	sort(krk.begin(), krk.end());
	build(1, 1, n);
	vector<int> ans(m, 0);
	int pre = 0;
	for (int i = 0; i < m; ++i) {
		int k = krk[i].first;
		int pos = krk[i].second.first;
		int idx = krk[i].second.second;
		for (int j = pre+1; j <= k; ++j) {
			update(1, rk[j-1].second+1);
		}
		pre = k;
		ans[idx] = a[query(1, pos)-1];
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
