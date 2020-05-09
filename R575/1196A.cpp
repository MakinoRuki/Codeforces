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
#define N 202
using namespace std;
typedef long long ll;
int q;
ll a,b,c;
ll getres(ll x, ll y, ll z) {
	if (x>y) swap(x,y);
	ll det=y-x;
	if (det > z) {
		return x+z;
	}
	z -= det;
	x += det;
	x += z/2;
	return x;
}
int main() {
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld%lld",&a,&b,&c);
		ll res=getres(a, b, c);
		res = max(res, getres(b, c, a));
		res = max(res, getres(a, c, b));
		cout<<res<<endl;
	}
	return 0;
}
