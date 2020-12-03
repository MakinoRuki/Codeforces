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
int n,q;
int a[N];
int lb[N];
int BIT[N];
int ans[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos) {
	while(pos <= n) {
		BIT[pos] += 1;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos > 0) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>n>>q;
	memset(lb, -1, sizeof(lb));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(BIT, 0, sizeof(BIT));
	for (int i = 1; i <= n; ++i) {
		int det=a[i]-i;
		if (det>0) {
			continue;
		}
		if (det == 0) {
			lb[i]=i;
			update(i);
			continue;
		}
		int l = -1, r = i-1;
		while(l < r) {
			int mid=(l+r+1)/2;
			int res=query(n);
			if (mid-1>0) res -= query(mid-1);
			if (res >= abs(det)) {
				l = mid;
			} else {
				r = mid-1;
			}
		}
		lb[i] = r;
		if (lb[i]>=1) {
			update(lb[i]);
		}
	}
	vector<pair<pair<int,int>,int>> qs;
	qs.clear();
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		qs.push_back(make_pair(make_pair(n-y, x+1), i));
	}
	sort(qs.begin(), qs.end());
	memset(BIT, 0, sizeof(BIT));
	int r = 1;
	for (int i = 0; i < q; ++i) {
		int x=qs[i].first.second;
		int y=qs[i].first.first;
		int id=qs[i].second;
		while(r <= y) {
			if (lb[r]>=1) update(lb[r]);
			r++;
		}
		ans[id] = query(n);
		if (x-1>=1) ans[id] -= query(x-1);
	}
	for (int i = 1; i <= q; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
