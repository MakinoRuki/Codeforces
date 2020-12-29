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
#define M 31
#define N 300002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int tree[N<<2];
void build(int id, int l, int r) {
	if (l==r) {
		tree[id]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id] = min(tree[id*2], tree[id*2+1]);
}
int query(int id, int l, int r, int l2, int r2) {
	if (l==l2 && r==r2) {
		return tree[id];
	}
	int mid=(l+r)/2;
	if (r2<=mid) return query(id*2, l, mid, l2, r2);
	else if (l2>mid) return query(id*2+1, mid+1, r, l2, r2);
	else return min(query(id*2, l, mid, l2, mid), query(id*2+1, mid+1, r, mid+1, r2));
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		build(1, 1, n);
		string ans = string(n, '0');
		int l=1, r=n;
		bool ok = true;
		for (int i = 1; i <=n; ++i) {
			int v=query(1, 1, n, l, r);
			if (v==i) {
				if (a[l]==i && a[r]==i) {
					break;
				}
				if (a[l]!=i && a[r]!=i) {
					break;
				}
				if (a[l]==i) l++;
				else r--;
			} else {
				ok=false;
				break;
			}
		}
		int len = r-l+1;
		if (!ok) len++;
		for (int i = len; i <= n; ++i) {
			ans[i-1] = '1';
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			ss.insert(a[i]);
		}
		if (ss.size() == n) {
			ans[0] = '1';
		}
		cout<<ans<<endl;
	}
	return 0;
}
