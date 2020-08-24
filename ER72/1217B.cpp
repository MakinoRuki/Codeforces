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
#define N 105
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int t;
int n;
ll x;
ll d[N], h[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld%lld", &d[i], &h[i]);
		}
		ll ans=2LL*inf;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				ll det = -d[j]+h[j];
				if (det >= 0) {
					if (x <= d[i]) {
						ans = min(ans, 1LL);
					}
				} else {
					if (x <= d[i]) {
						ans = min(ans, 1LL);
					} else {
						det = abs(det);
						ll res = (x-d[i]+det-1)/det;
						ans = min(ans, res+1);
					}
				}
			}
		}
		if (ans>=2LL*inf) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
