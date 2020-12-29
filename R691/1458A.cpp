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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
ll a[N], b[N];
ll getgcd(ll x, ll y) {
	return y== 0 ? x : getgcd(y, x%y);
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &b[i]);
	}
	if (n == 1) {
		for (int i = 1; i <= m; ++i) {
			printf("%lld", b[i]+a[n]);
			if (i < m) cout<<" ";
			else cout<<endl;
		}
	} else {
		ll g=abs(a[2]-a[1]);
		for (int i = 3; i <= n; ++i) {
			g = getgcd(g, abs(a[i]-a[i-1]));
		}
		for (int i = 1; i <= m; ++i) {
			ll res=getgcd(g, b[i]+a[1]);
			printf("%lld", res);
			if (i < m) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
