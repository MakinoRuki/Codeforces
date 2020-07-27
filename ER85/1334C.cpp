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
#define N 300005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll a[N], b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 0; i < n; ++i) {
			scanf("%lld%lld", &a[i], &b[i]);
		}
		ll ans=0LL;
		for (int i = 0; i < n; ++i) {
			ll pre = b[(i-1+n)%n];
			ll det = max(a[i]-pre, 0LL);
			a[i] = min(a[i], pre);
			ans += det;
		}
		ll minv = 1000000000002LL;
		for (int i = 0; i < n; ++i) {
			minv = min(minv, a[i]);
		}
		ans += minv;
		printf("%lld\n" ,ans);
	}
  return 0;
}
