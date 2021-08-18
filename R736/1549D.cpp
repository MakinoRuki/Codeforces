#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
ll a[N];
struct node {
	int l, r;
	ll g;
} tree[N<<2];
ll getgcd(ll x, ll y) {
	return y == 0 ? x : getgcd(y, x%y);
}
void build(int id, int l, int r) {
	//cout<<"id="<<id<<endl;
	tree[id].l = l;
	tree[id].r = r;
	if (l == r) {
		tree[id].g = abs(a[l+1]-a[l]);
		return ;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id].g = getgcd(tree[id*2].g, tree[id*2+1].g);
}
ll query(int id, int l, int r) {
	if (l <= tree[id].l && r >= tree[id].r) {
		return tree[id].g;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (r <= mid) {
		return query(id*2, l, r);
	} else if (l > mid) {
		return query(id*2+1, l, r);
	} else {
		return getgcd(query(id*2, l, mid), query(id*2+1, mid+1, r));
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			//a[i] = i + 2;
		}
		if (n == 1) {
			printf("%d\n", 1);
			continue;
		}
		build(1, 1, n-1);
		int ans = 1;
		int j = 1;
		for (int i = 1; i < n; ++i) {
			while(j <= i && query(1, j, i) <= 1) {
				j++;
			}
			if (j <= i) {
				ans = max(ans, i-j+1+1);
			}
		}
		printf("%d\n", ans);
	}
  return 0;
}
