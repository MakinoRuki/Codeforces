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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N], b[N];
int tree[N<<2];
vector<int> ids[N];
void build(int id, int l, int r) {
	if (l==r) {
		tree[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id]=max(tree[id*2], tree[id*2+1]);
}
void update(int id, int l, int r, int pos) {
	if (l==r) {
		tree[id]=0;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) update(id*2, l, mid, pos);
	else if (pos>mid) update(id*2+1, mid+1, r, pos);
	tree[id]=max(tree[id*2], tree[id*2+1]);
}
int query(int id, int l, int r, int l1, int r1) {
	if (l==l1 && r==r1) {
		return tree[id];
	}
	int mid=(l+r)/2;
	if (r1<=mid) return query(id*2, l, mid, l1, r1);
	else if (l1>mid) return query(id*2+1, mid+1, r, l1, r1);
	else {
		int res1=query(id*2, l, mid, l1, mid);
		int res2=query(id*2+1, mid+1, r, mid+1, r1);
		return max(res1, res2);
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			ids[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ids[a[i]].push_back(i);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		bool ok=true;
		build(1, 1, n);
		for (int i = n; i >= 1; --i) {
			if (ids[b[i]].empty()) {
				ok=false;
				break;
			}
			int id=ids[b[i]].back();
			ids[b[i]].pop_back();
			int res=query(1, 1, n, id, n);
		//	cout<<i<<" "<<res<<endl;
			if (res>b[i]) {
				ok=false;
				break;
			}
			update(1, 1, n, id);
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
