#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int p[N];
ll a[N];
int pos[N];
ll sum[N];
struct node {
	int l, r;
	ll minv, add;
} tree[N<<2];
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	tree[id].add = 0LL;
	if (l==r) {
		tree[id].minv = sum[l-1];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id].minv = min(tree[id*2].minv, tree[id*2+1].minv);
}
void update(int id, int l, int r, ll val) {
	if (tree[id].l==l && tree[id].r==r) {
		tree[id].add += val;
		tree[id].minv += val;
	//	cout<<"x1:"<<l<<" "<<r<<" "<<val<<" "<<tree[id].minv<<endl;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (tree[id].add != 0) {
		tree[id*2].add += tree[id].add;
		tree[id*2+1].add += tree[id].add;
		tree[id*2].minv += tree[id].add;
		tree[id*2+1].minv += tree[id].add;
		tree[id].add = 0;
	}
	if (r <= mid) {
		update(id*2, l, r, val);
	} else if (l > mid) {
		update(id*2+1, l, r, val);
	} else {
		update(id*2, l, mid, val);
		update(id*2+1, mid+1, r, val);
	}
	tree[id].minv = min(tree[id*2].minv, tree[id*2+1].minv);
	//cout<<"x2:"<<l<<" "<<r<<" "<<val<<" "<<tree[id].minv<<endl;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	memset(sum, 0LL, sizeof(sum));
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + a[pos[i]];
	}
	build(1, 1, n+1);
	ll ans = -1;
	for (int i = 1; i < n; ++i) {
		update(1, 1, p[i], a[i]);
		update(1, p[i]+1, n+1, -a[i]);
		ll res=tree[1].minv;
		ans = (ans < 0 ? res : min(ans, res));
	}
	cout<<ans<<endl;
	return 0;
}
