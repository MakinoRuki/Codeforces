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
#define N 300005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int q;
ll d;
vector<ll> ps;
ll comb[55][55];
ll getgcd(ll a, ll b) {
	return b==0?a:getgcd(b, a%b);
}
ll solve(ll u, ll v) {
	ll x = u/v;
	if (x==1) return 1LL;
	vector<ll> ts;
	ts.clear();
	ll tot=0LL;
	for (int i = 0; i < ps.size(); ++i) {
		int cnt=0;
		while(x%ps[i]==0) {
			cnt++;
			x/=ps[i];
		}
		if (cnt>0) {
			ts.push_back(cnt);
			tot += cnt;
		}
	}
	ll res = 1LL;
	for (int i = 0; i < ts.size(); ++i) {
		res = res * comb[tot][ts[i]] % mod;
		tot -= ts[i];
	}
	return res;
}
int main() {
	cin>>d>>q;
	ps.clear();
	for (int i = 0; i <= 52; ++i) {
		comb[i][0] = 1LL;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
		}
	}
	for (ll i = 2; i*i <= d; ++i) {
		if (d%i==0) {
			ps.push_back(i);
			while(d%i==0) d/=i;
		}
	}
	if (d>1) ps.push_back(d);
	for (int i = 1; i <= q; ++i) {
		ll u, v;
		scanf("%lld%lld", &v, &u);
		ll g = getgcd(v, u);
		ll res = solve(v, g) * solve(u, g) % mod;
		printf("%lld\n", res);
	}
  return 0;
}
