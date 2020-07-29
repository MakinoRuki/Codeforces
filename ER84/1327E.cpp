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
#define N 100005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
ll getpw(ll a, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		if (i == n) {
			cout<<10<<endl;
		} else {
			ll res=0LL;
			if (i <= n-2) {
				res = 810LL * getpw(10, n-i-2)%mod;
				res = res * (ll)(n-i-1) % mod;
			}
			ll res2= 180LL*getpw(10, n-i-1)%mod;
			res = (res+res2)%mod;
			printf("%lld ", res);
		}
	}
  return 0;
}
