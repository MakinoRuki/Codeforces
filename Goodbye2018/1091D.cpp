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
#define M 31
#define N 1000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
ll fac[N];
ll an[N];
int main() {
	cin>>n;
	fac[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i-1]*(ll)i%mod2;
	}
	an[0] = 1LL;
	for (int i = 1; i <= n; ++i) {
		an[i] = an[i-1]*(ll)(n-i+1)%mod2;
	}
	ll ans=fac[n];
	for (int i = 1; i <= n; ++i) {
		ll cur = an[i] * ((fac[n-i]-1+mod2) % mod2) % mod2;
		ans = (ans + cur) % mod2;
	}
	cout<<ans<<endl;
	return 0;
}
