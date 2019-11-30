#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define N 1000005
using namespace std;
typedef long long ll;
int n;
string cmd;
struct node {
	int l, r;
	int sum, minv, maxv;
} tree[N*4];
void build(int idx, int l, int r) {
	tree[idx].l = l;
	tree[idx].r = r;
	if (l == r) {
		return ;
	}
	int mid=(l+r)/2;
	build(idx*2, l, mid);
	build(idx*2+1, mid+1, r);
}
void update(int idx, int p, int v) {
	if (tree[idx].l == tree[idx].r) {
		tree[idx].sum = v;
		tree[idx].minv = v;
		tree[idx].maxv = v;
		return;
	}
	int mid = (tree[idx].l+tree[idx].r) / 2;
	if (p <= mid) update(idx*2, p, v);
	else update(idx*2+1, p, v);
	tree[idx].sum = tree[idx*2].sum+tree[idx*2+1].sum;
	tree[idx].minv = min(tree[idx*2].minv, tree[idx*2].sum+tree[idx*2+1].minv);
	tree[idx].maxv = max(tree[idx*2].maxv, tree[idx*2].sum+tree[idx*2+1].maxv);
}
int main() {
	cin>>n;
	cin>>cmd;
	int pos = 1;
	build(1, 1, n);
	for (int i = 0; i < n; ++i) {
		if (cmd[i] == 'L') {
			pos = max(pos-1, 1);
		} else if (cmd[i] == 'R') {
			pos++;
		} else if (cmd[i] == '(') {
			update(1, pos, 1);
		} else if (cmd[i] == ')') {
			update(1, pos, -1);
		} else {
			update(1, pos, 0);
		}
		// 看前缀和。合法序列的条件是总和为0切任一个位置前缀和>=0。
		// 则括号层数最多的位置就是前缀和最大的位置。
		if (tree[1].sum == 0 && tree[1].minv >= 0) {
			cout<<tree[1].maxv;
		} else {
			cout<<"-1";
		}
		if (i == n-1) cout<<endl;
		else cout<<" ";
	}
	return 0;
}
