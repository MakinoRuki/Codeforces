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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int lm[N], rm[N];
struct node {
	int l, r;
	int minv;
} tree[N<<2];
void build(int id, int l, int r) {
	tree[id].l=l;
	tree[id].r=r;
	if (l==r) {
		tree[id].minv=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id].minv=min(tree[id*2].minv, tree[id*2+1].minv);
}
int query(int id, int l, int r) {
	if (l==tree[id].l && r==tree[id].r) {
		return tree[id].minv;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r<=mid) {
		return query(id*2, l, r);
	} else if (l>mid) {
		return query(id*2+1, l, r);
	} else {
		return min(query(id*2, l, mid), query(id*2+1, mid+1, r));
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		build(1, 1, n);
		for (int i = 1; i <= n; ++i) {
			if (i==1) lm[i]=a[i];
			else lm[i] = max(lm[i-1], a[i]);
		}
		for (int i = n; i >= 1; --i) {
			if (i==n) rm[i]=a[i];
			else rm[i] = max(rm[i+1], a[i]);
		}
		bool found=false;
		for (int i = 2; i < n; ++i) {
			int l=1,r=i;
			while(l<r) {
				int mid=(l+r)/2;
				if (lm[mid]<=a[i]) {
					l=mid+1;
				} else {
					r=mid;
				}
			}
		//	if (i==4) cout<<"r="<<r<<endl;
			if (r-1<1 || lm[r-1]!=a[i]) {
				continue;
			}
			int l2=i, r2=n;
			while(l2<r2) {
				int mid=(l2+r2+1)/2;
				if (rm[mid]<=a[i]) {
					r2=mid-1;
				} else {
					l2=mid;
				}
			}
		//	if (i==4) cout<<"r2="<<r2<<endl;
			if (r2+1>n || rm[r2+1]!=a[i]) {
				continue;
			}
		//	if (i==4) cout<<r<<" "<<r2<<endl;
			int res=query(1, r, r2);
			if (res != a[i]) {
				continue;
			}
			found=true;
			cout<<"YES"<<endl;
			printf("%d %d %d\n", r-1, r2-r+1, n-r2);
			break;
		}
		if (!found) {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
