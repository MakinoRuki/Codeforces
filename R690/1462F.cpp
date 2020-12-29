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
int t,n,m,k;
int a[N];
vector<pair<int,int>> segs;
unordered_map<int,int> ids;
int cnt[N*3];
int bit[N*3];
int tot;
int lowbit(int x) {
	return x&(-x);
}
void update(int pos) {
	while(pos <= tot) {
		bit[pos]++;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos) {
		res += bit[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		segs.clear();
		set<int> ss;
		ss.clear();
		for (int i = 0; i < n; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			segs.push_back(make_pair(r,l));
			ss.insert(l);
			ss.insert(r);
		}
		vector<int> pts(ss.begin(), ss.end());
		ids.clear();
		for (int i = 0; i <pts.size(); ++i) {
			ids[pts[i]] = i+1;
		}
		tot=(int)pts.size();
		sort(segs.begin(), segs.end());
		for (int i = 0; i <= tot; ++i) {
			bit[i]=0;
		}
		for (int i = 0; i < n; ++i) {
			cnt[i]=0;
		}
		for (int i = 0; i < segs.size(); ++i) {
			int l = segs[i].second;
			int r = segs[i].first;
			int idl=ids[l];
			int idr=ids[r];
			cnt[i] += query(idr)-query(idl-1);
			update(idr);
		}
		for (int i = 0; i <= tot; ++i) {
			bit[i]=0;
		}
		int sz=(int)segs.size();
		for (int i = sz-1; i >= 0; --i) {
			int l = segs[i].second;
			int r = segs[i].first;
			int idl=ids[l];
			int idr=ids[r];
			cnt[i] += (sz-1-i) - (query(tot)-query(idr));
			update(idl);
		}
		int ans=n-1;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, n-(cnt[i]+1));
		}
		printf("%d\n", ans);
	}
	return 0;
}
