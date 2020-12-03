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
int n, m;
int x,k,y;
int a[N], b[N];
ll calc(vector<int>& ids) {
	int sz=(int)ids.size();
	int lb = 0;
	int rb = sz/k;
	int maxv=a[ids[0]];
	for (int i = 1; i < ids.size(); ++i) {
		maxv=max(maxv, a[ids[i]]);
	}
	int l = ids[0]-1;
	int r = ids.back()+1;
//	cout<<"sz="<<sz<<" "<<l<<" "<<r<<endl;
	if (maxv > a[l] && maxv > a[r]) {
		lb = 1;
	}
	if (lb > rb) {
		return -1;
	}
	ll res = (ll)lb * (ll)x + ((ll)sz-(ll)lb*(ll)k)*(ll)y;
	for (int i = lb+1; i <= rb; ++i) {
		res = min(res, (ll)i*(ll)x+((ll)sz-(ll)i*(ll)k)*(ll)y);
	}
	return res;
}
int main() {
	cin>>n>>m;
	cin>>x>>k>>y;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
	}
	a[0] = 0;
	a[n+1] = 0;
	vector<int> ids;
	ids.clear();
	int j = 1;
	bool ok=true;
	ll ans=0LL;
	for (int i = 1; i <= n; ++i) {
		if (j > m || a[i] != b[j]) {
			ids.push_back(i);
		} else {
			if (!ids.empty()) {
				ll res =  calc(ids);
				if (res < 0) {
					ok=false;
					break;
				}
				ans += res;
			}
			ids.clear();
			j++;
		}
	}
	if (!ids.empty()) {
		ll res= calc(ids);
		if (res<0) ok=false;
		ans += res;
	}
	if (j <= m || !ok) {
		cout<<-1<<endl;
	} else {
		printf("%lld\n", ans);
	}
	return 0;
}
