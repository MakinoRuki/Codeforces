#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
ll x;
int main() {
	cin>>x;
	vector<ll> ps;
	ps.clear();
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			ll res=1LL;
			while(x % i == 0) {
				x /= i;
				res *= (ll)i;
			}
			ps.push_back(res);
		}
	}
	if (x > 1) {
		ps.push_back(x);
	}
	int n = ps.size();
	ll a=1;
	ll b=1;
	for (int i = 0; i < (1<<n); ++i) {
		ll a1=1LL;
		ll b1=1LL;
		for (int j= 0; j < n; ++j) {
			if ((1<<j) & i) {
				a1 *= ps[j];
			} else {
				b1 *= ps[j];
			}
		}
		if (i ==0 || max(a1, b1) < max(a, b)) {
			a = a1;
			b = b1;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
