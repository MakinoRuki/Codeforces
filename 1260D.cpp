#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#define N 200020
using namespace std;
typedef long long ll;
int m,n,k,t;
int a[N];
vector<pair<int, pair<int, int>>> traps;
bool check(int val) {
	int tot=n+1;
	int cur=0;
	for (int i = 0; i < k; ++i) {
		int l = traps[i].first;
		int r = traps[i].second.first;
		int d = traps[i].second.second;
		if (d > val) {
			cur = max(cur, l-1);
			tot += max(0, 2*(r-cur));
			cur = max(cur, r);
		}
	}
	return tot <= t;
}
int main() {
	cin>>m>>n>>k>>t;
	for (int i = 0; i < m; ++i) {
		cin>>a[i];
	}
	sort(a, a+m);
	traps.clear();
	for (int i = 0; i < k; ++i) {
		int l,r,d;
		cin>>l>>r>>d;
		traps.push_back(make_pair(l, make_pair(r, d)));
	}
	sort(traps.begin(), traps.end());
	int l = 0, r = m;
	while(l < r) {
		int mid=(l+r)/2;
		if (check(a[mid])) r=mid;
		else l = mid+1;
	}
	if (r == m) cout<<0<<endl;
	else cout<<m-r<<endl;
	return 0;
}
