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
int n,m;
string s;
int BIT[N];
unordered_map<char, set<int>> ids;
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, int val) {
	while(pos<=n) {
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int id) {
	int res=0;
	while(id>0) {
		res+=BIT[id];
		id -= lowbit(id);
	}
	return res;
}
int getpos(int t) {
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if (query(mid)>=t) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	return r;
}
int main() {
	cin>>n>>m>>s;
	memset(BIT, 0, sizeof(BIT));
	ids.clear();
	for (int i =1; i <=n; ++i) {
		update(i, 1);
		ids[s[i-1]].insert(i);
	}
	for (int q=1; q<=m; ++q) {
		int l,r;
		char c[2];
		scanf("%d%d%s", &l,&r, c);
		int r2=getpos(r);
		int l2=getpos(l);
		auto ss=ids[c[0]];
		auto itr1=ss.upper_bound(r2);
		auto itr2=ss.lower_bound(l2);
		vector<int> tmp(itr2, itr1);
		for (int i =0;i <tmp.size(); ++i) {
			ids[c[0]].erase(tmp[i]);
			update(tmp[i], -1);
		}
	}
	string ans="";
	for (int i = 1; i <= n; ++i) {
		if (query(i)-query(i-1) > 0) {
			ans.push_back(s[i-1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
