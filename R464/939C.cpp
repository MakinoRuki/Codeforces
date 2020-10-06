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
#include <cmath>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int s,f;
int main() {
	cin>>n;
	vector<pair<int,int>> rk;
	rk.clear();
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	cin>>s>>f;
	s--;
	f--;
	for (int i = 0; i < n; ++i) {
		int b=(s-i+n)%n;
		int e=(f-1-i+n)%n;
		if (b<=e) {
	//		cout<<"i1="<<i<<" "<<b<<" "<<e;
			rk.push_back(make_pair(b, -a[i]));
			rk.push_back(make_pair(e, a[i]));
		} else {
		//	cout<<"i2="<<i<<" "<<b<<" "<<e;
			rk.push_back(make_pair(b, -a[i]));
			rk.push_back(make_pair(n-1, a[i]));
			rk.push_back(make_pair(0, -a[i]));
			rk.push_back(make_pair(e, a[i]));
		}
	}
	sort(rk.begin(), rk.end());
	ll tot=0LL;
	ll ans=0LL;
	int tm=-1;
	for (int i = 0; i < rk.size(); ++i) {
	//	cout<<i<<" "<<rk[i].first<<" "<<rk[i].second<<endl;
		tot -= rk[i].second;
		if (tot>ans || tm<0) {
			ans=tot;
			tm=rk[i].first;
		}
	}
	cout<<tm+1<<endl;
	return 0;
}
