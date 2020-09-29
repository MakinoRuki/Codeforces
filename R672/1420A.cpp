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
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, q;
int t;
int a[N];
int BIT[N];
int cnt;
int id[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int pos, int val) {
	while(pos <= cnt) {
		BIT[pos] += val;
		pos += lowbit(pos);
	}
}
int query(int pos) {
	int res=0;
	while(pos>0) {
		res += BIT[pos];
		pos -= lowbit(pos);
	}
	return res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		vector<pair<int,int>> rk;
		rk.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			rk.push_back(make_pair(a[i], i));
			BIT[i] = 0;
		}
		sort(rk.begin(), rk.end());
		cnt=1;
		for (int i = 0; i < rk.size(); ++i) {
			if (i==0 || rk[i].first == rk[i-1].first) {
				id[rk[i].second] = cnt;
			} else {
				cnt++;
				id[rk[i].second] = cnt;
			}
		}
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
		//	cout<<"i="<<i<<" "<<id[i]<<endl;
			int x=id[i];
			ll det=query(cnt)-query(x);
			tot += det;
		//	cout<<"tot="<<tot<<endl;
			update(x, 1);
		//	cout<<query(x)<<endl;
		}
		ll ub=(ll)n*(ll)(n-1)/2LL -1;
		if (tot > ub) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
