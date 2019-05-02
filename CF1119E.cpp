#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
int n;
ll a[N];
int main() {
	cin>>n;
	ll ans = 0LL;
	ll rem = 0LL;
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		if (rem) {
			ll det = min(rem, a[i]/2);
			ans += det;
			rem -= det;
			a[i] -= det*2;
		}
		ans += a[i]/3;
		a[i] %= 3;
		rem += a[i];
	//	cout<<i<<" "<<ans<<" "<<rem<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
