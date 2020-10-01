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
#define M 20005
#define N 1000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n,k,m,d;
int main() {
	cin>>n>>k>>m>>d;
	ll ans=0LL;
	for (int t=1; t<=d; ++t) {
		if (t-1>=(n+k-1)/k) {
			continue;
		}
		ll x=n/((ll)(t-1)*k+1);
		x=min(x, m);
		if (x==0) continue;
		ll y=((n/x)+k-1)/k;
		if (y>t) continue;
		ans=max(ans, x*t);
	}
	cout<<ans<<endl;
	return 0;
}
