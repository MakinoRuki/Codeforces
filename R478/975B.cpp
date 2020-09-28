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
ll a[15];
ll check(int id) {
	ll b[15];
	for (int i = 0; i < 14; ++i) {
		b[i] = a[i];
	}
	ll num=b[id];
	b[id]=0;
	ll det=num/14;
	ll r=num%14;
	for (int i = 1; i <= r; ++i) {
		b[(id+i)%14]++;
	}
	for (int i = 0; i < 14; ++i) {
		b[i] += det;
	}
	ll tot=0LL;
	for (int i = 0; i < 14; ++i) {
		if (b[i]%2==0) {
			tot += b[i];
		}
	}
	return tot;
}
int main() {
	for (int i = 0; i < 14; ++i) {
		scanf("%lld", &a[i]);
	}
	ll ans=0;
	for (int i = 0; i < 14; ++i) {
		ll res=check(i);
		ans=max(ans, res);
	}
	cout<<ans<<endl;
	return 0;
}
