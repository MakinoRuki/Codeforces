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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int n, m, p;
int a[N], ca[N], b[N], cb[N];
struct node {
	int l, r;
	ll sum;
	ll val;
} tree[20*N];
vector<pair<int, int>> ark;
vector<pair<int, int>> brk;
vector<pair<int, pair<int, int>>> ms;
void build(int root, int l, int r) {
	tree[root].l = l;
	tree[root].r = r;
	tree[root].sum = 0;
	if (l == r) {
		tree[root].val = -brk[l-1].second;
		return ;
	}
	int mid = (l+r)/2;
	build(root*2, l, mid);
	build(root*2+1, mid+1, r);
	tree[root].val = max(tree[root*2].val, tree[root*2+1].val);
}
void update(int root, int x, int w) {
	if (tree[root].l == tree[root].r) {
		int pos = tree[root].l;
		if (brk[pos-1].first <= x) return ;
		tree[root].sum += w;
		tree[root].val = -brk[pos-1].second + tree[root].sum;
		return ;
	}
	int mid = (tree[root].l+tree[root].r)/2;
	if (x >= brk[mid-1].first) {
		update(root*2+1, x, w);
	} else {
		update(root*2, x, w);
	}
	tree[root].sum = tree[root*2].sum+tree[root*2+1].sum;
	tree[root].val = max(tree[root*2].val, tree[root*2+1].val + tree[root*2].sum);
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d",&a[i],&ca[i]);
		ark.push_back(make_pair(a[i], ca[i]));
	}	
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d",&b[i],&cb[i]);
		brk.push_back(make_pair(b[i], cb[i]));
	}
	for (int i = 1; i <= p; ++i) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ms.push_back(make_pair(x,make_pair(y,z)));
	}
	sort(ark.begin(), ark.end());
	sort(brk.begin(), brk.end());
	sort(ms.begin(), ms.end());
	int j = 0;
	build(1, 1, m);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll res = -ark[i].second;
		while(j < p && ms[j].first < ark[i].first) {
			update(1, ms[j].second.first, ms[j].second.second);
			j++;
		}
		res += tree[1].val;
		if (i == 0) ans = res;
		else ans = max(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}
