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
#define N 200002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,q;
vector<int> edges[N];
int idx[N], b[N], e[N];
int cnt;
struct node {
	int l,r;
	int f;
	int sum;
} tree[N<<2];
int t[N];
int t2[N];
void dfs(int u, int p) {
	idx[u]=++cnt;
	b[u]=cnt;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs(v, u);
	}
	e[u]=cnt;
}
void build(int id, int l, int r) {
	tree[id].l=l;
	tree[id].r=r;
	if (l==r) {
		tree[id].f=0;
		tree[id].sum=t2[l];
	//	cout<<"x="<<id<<" "<<l<<" "<<r<<" "<<tree[id].sum<<endl;
		return ;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id].f=0;
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	//cout<<"y="<<id<<" "<<l<<" "<<r<<" "<<tree[id].sum<<endl;
}
void pushdown(int id, int id2) {
	if (tree[id].f) {
		int det=tree[id2].r-tree[id2].l+1;
		int sum=tree[id2].sum;
		tree[id2].f=!tree[id2].f;
		tree[id2].sum=det-sum;
	//	cout<<"id="<<id<<" "<<"id2="<<id2<<" "<<tree[id2].f<<endl;
	}
}
void update(int id, int l, int r) {
	if (tree[id].l==l && tree[id].r==r) {
		int det=r-l+1;
		int sum=tree[id].sum;
		tree[id].f=!tree[id].f;
		tree[id].sum=det-sum;
		return;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	pushdown(id, id*2);
	pushdown(id, id*2+1);
	tree[id].f=0;
	if (r<=mid) {
		update(id*2, l, r);
	} else if (l>mid) {
		update(id*2+1, l, r);
	} else {
		update(id*2, l, mid);
		update(id*2+1, mid+1, r);
	}
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id, int l, int r) {
//	cout<<id<<" "<<l<<" "<<r<<" "<<tree[id].f<<" "<<tree[id].sum<<endl;
	if (tree[id].l==l && tree[id].r==r) {
		return tree[id].sum;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	pushdown(id, id*2);
	pushdown(id, id*2+1);
	tree[id].f=0;
	if (r<=mid) return query(id*2, l, r);
	else if (l>mid) return query(id*2+1, l, r);
	else {
		return query(id*2, l, mid) + query(id*2+1, mid+1, r);
	}
}
int main() {
	cin>>n;
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		edges[p].push_back(i);
	}
	cnt=0;
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		t2[idx[i]]=t[i];
	}
	build(1, 1, cnt);
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		string op;
		int v;
		cin>>op;
		scanf("%d", &v);
		if (op=="pow") {
			update(1, b[v], e[v]);
		//	cout<<"f="<<tree[5].f<<endl;
		} else {
			int res=query(1, b[v], e[v]);
		//	cout<<b[v]<<" "<<e[v]<<endl;
			printf("%d\n", res);
		}
	}
	return 0;
}
