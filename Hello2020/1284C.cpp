#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 250005
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
ll n, m;
ll p[N];
int main() {
	cin>>n>>m;
	ll ans=0LL;
	p[0]=1LL;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i-1]*(ll)i % m;
	}
	for (int l = 1; l <= n; ++l) {
		ll res= (ll)(n-l+1)*(ll)(n-l+1)%m;
		res = res*p[l]%m;
		res = res*p[n-l]%m;
		ans = (ans+res)%m;
	}
	cout<<ans<<endl;
	return 0;
}
