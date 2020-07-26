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
#define N 100005
#define M 20010
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
int a[N], b[N];
int id1[N], id2[N];
int cnt;
struct node {
	int l, r;
	ll sum;
	int cnt;
} tree[N<<2];
void build(int id, int l, int r) {
	tree[id].l = l;
	tree[id].r = r;
	tree[id].sum = 0;
	tree[id].cnt=0;
//	cout<<"id="<<id<<endl;
	if (l==r) return;
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].cnt=tree[id*2].cnt+tree[id*2+1].cnt;
}
void update(int id, int pos, ll val) {
	if (tree[id].l==tree[id].r) {
		tree[id].sum += val;
		tree[id].cnt=1;
	//	cout<<"id="<<id<<" "<<tree[id].l<<" "<<tree[id].sum<<" "<<tree[id].cnt<<endl;
		return;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if (pos <= mid) {
		update(id*2, pos, val);
	} else {
		update(id*2+1, pos, val);
	}
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
	tree[id].cnt=tree[id*2].cnt+tree[id*2+1].cnt;
	//cout<<"id="<<id<<" "<<tree[id].l<<" "<<tree[id].sum<<" "<<tree[id].cnt<<endl;
}
void query(int id, int lb, ll& sum, int& cnt) {
	if (tree[id].l == tree[id].r) {
		if (!tree[id].cnt) return ;
		ll x = id2[tree[id].l];
		if (x > lb && cnt+1<n) {
			sum += x;
			cnt++;
		}
	//	cout<<"id="<<id<<" "<<sum<<" "<<cnt<<endl;
		return;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	//cout<<"mid="<<mid<<" "<<id<<endl;
	if (id2[mid+1] > lb) {
		if (cnt+ tree[id*2+1].cnt < n) {
			sum += tree[id*2+1].sum;
			cnt += tree[id*2+1].cnt;
			query(id*2, lb, sum, cnt);
		//	cout<<"id="<<id<<" "<<sum<<" "<<cnt<<endl;
		} else {
			query(id*2+1, lb, sum, cnt);
		//	cout<<"id="<<id<<" "<<sum<<" "<<cnt<<endl;
		}
	} else {
		query(id*2+1, lb, sum, cnt);
	//	cout<<"id="<<id<<" "<<sum<<" "<<cnt<<endl;
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			rk.push_back(make_pair(a[i], i));
		}
		cnt=0;
		sort(rk.begin(), rk.end());
		for (int i = 0; i < rk.size(); ++i) {
			id1[rk[i].second] = ++cnt;
			id2[cnt] = rk[i].first;
		}
		rk.clear();
		for (int i = 1; i <= m; ++i) {
			rk.push_back(make_pair(b[i], i));
		}
		sort(rk.begin(), rk.end());
		build(1, 1, m);
		ll ans = 0LL;
		for (int i = 0; i < rk.size(); ++i) {
			ll suma = 0LL;
			int cnta = 0;
			//cout<<"i="<<i<<endl;
			query(1, rk[i].first, suma, cnta);
		//	cout<<"i="<<i<<" "<<rk[i].first<<" "<<rk[i].second<<" "<<suma<<" "<<cnta<<endl;
			ans = max(ans, suma + (ll)a[rk[i].second] + (ll)(n-cnta-1)*(ll)rk[i].first);
		//	cout<<id1[rk[i].second]<<" "<<a[rk[i].second]<<endl;
			update(1, id1[rk[i].second], a[rk[i].second]);
		}
		cout<<ans<<endl;
	}
  return 0;
}
