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
#define M 21
#define N 2602
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q;
ll l, r;
vector<ll> cdds;
bool check(ll x) {
	ll sq=(ll)sqrt(x);
	if (sq*sq == x) return false;
	return true;
}
int main() {
	cin>>q;
	vector<ll> rk;
	rk.clear();
	cdds.clear();
	rk.push_back(1);
	for (ll i = 2; i <= 1000000; ++i) {
		ll cur = i;
		for (int j = 2; j <= 60; ++j) {
			if (cur  > 1000000000000000000LL/ i) {
				break;
			}
			cur *= i;
			rk.push_back(cur);
		}
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		if (i == 0 || rk[i] != rk[i-1]) {
			if (check(rk[i])) {
				cdds.push_back(rk[i]);
			}
		}
	}
	// for (int i =0; i < 30; ++i) {
	// 	cout<<"i="<<i<<" "<<cdds[i]<<endl;
	// }
	while(q-->0) {
		scanf("%lld%lld", &l, &r);
		ll det = upper_bound(cdds.begin(), cdds.end(), r) - lower_bound(cdds.begin(), cdds.end(), l);
		//cout<<det<<endl;
		ll sq1 = (ll)sqrt(r);
		ll sq2 = (ll)sqrt(l-1);
		det += sq1-sq2;
		printf("%lld\n", det);
	}
  return 0;
}
