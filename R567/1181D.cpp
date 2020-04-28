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
#include <queue>
#define N 500005
using namespace std;
typedef long long ll;
int n, m, q;
int a[N];
vector<pair<ll, int>> qs;
int cnt[N];
struct node {
	int l, r;
	int sum;
	int val;
}tree[N<<2];
void build(int id, int l, int r) {
	tree[id].l=l;
	tree[id].r=r;
	tree[id].sum=0;
	tree[id].val=l;
	if (l==r) {
		return ;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
}
void update(int id, int pos) {
	if (tree[id].l==tree[id].r) {
		tree[id].sum++;
		return;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (pos<=mid) {
		update(id*2, pos);
	} else {
		update(id*2+1, pos);
	}
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
int query(int id, int num) {
	if (tree[id].l==tree[id].r) {
		return tree[id].l;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (tree[id*2].sum<num) {
		return query(id*2+1, num-tree[id*2].sum);
	} else {
		return query(id*2, num);
	}
}
int main() {
	cin>>n>>m>>q;
	qs.clear();
	vector<pair<int,int>> rk;
	rk.clear();
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int i = 1; i <= m; ++i) {
		rk.push_back(make_pair(cnt[i], i));
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < q; ++i) {
		ll k;
		scanf("%lld", &k);
		qs.push_back(make_pair(k, i));
	}
	sort(qs.begin(), qs.end());
	vector<int> ans(q);
	build(1, 1, m);
	int j = 0;
	int i = 0;
	ll sum=n;
	for (j = 0; j < rk.size(); ++j) {
		if (j==0) {
			update(1, rk[j].second);
		} else {
			if (rk[j].first == rk[j-1].first) {
				update(1, rk[j].second);
			} else {
				ll det=(ll)j*(ll)(rk[j].first-rk[j-1].first);
			//	cout<<"j="<<j<<" "<<det<<endl;
				while(i < q && sum+det>=qs[i].first) {
					int idx=(qs[i].first-sum) % j;
					if (idx==0) idx=j;
				//	cout<<"***"<<i<<" "<<idx<<endl;
					ans[qs[i].second] = query(1, idx);
					i++;
				}
				sum += det;
				update(1, rk[j].second);
			}
		}
	}
	while(i < q) {
		int idx=(qs[i].first-sum) % m;
		if (idx==0) idx=m;
		ans[qs[i].second] = query(1, idx);
		i++;
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
