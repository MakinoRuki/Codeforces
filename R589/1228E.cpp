#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#define N 252
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll k;
ll comb[N][N];
ll getpw(ll a, ll b) {
	ll res=1LL;
	while(b) {
		if (b&1) {
			res = res*a%mod;
		}
		a = a * a % mod;
		b /= 2;
	}
	return res;
}
int main() {
	cin>>n>>k;
	for (int i = 0; i <= n; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
		}
	}
	ll ans = 0LL;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			int t = i+j;
			ll tmp = comb[n][i] * comb[n][j] % mod;
			tmp = tmp * getpw(k, n*n-n*(i+j)+i*j) % mod;
			tmp = tmp * getpw(k-1, n*(i+j) - i*j) % mod;
			if (t % 2 == 0) {
				ans = (ans + tmp) % mod;
			} else {
				ans = (ans - tmp + mod) % mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
