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
int t, n;
int a[N];
int b[N];
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll tot = 0;
		for (int i = 1; i <= n; ++i) {
			b[i] = a[i]-a[1];
			if (i > 1) {
				tot += (ll)abs(b[i]-b[i-1]);
			}
		}
		ll ans=tot;
		for (int i = 1; i <= n; ++i) {
			int x = b[i];
			ll cur=0;
			if (i-1>=1) cur+=(ll)abs(b[i]-b[i-1]);
			if (i+1<=n) cur += (ll)abs(b[i+1]-b[i]);
			if (i-1>=1) {
				b[i]=b[i-1];
				ll cur2 = 0;
				if (i+1<=n) cur2 += (ll)abs(b[i+1]-b[i]);
				ans = min(ans, tot-cur+cur2);
				b[i]=x;
			}
			if (i+1<=n) {
				b[i]= b[i+1];
				ll cur2=0;
				if (i-1>=1) cur2 += (ll)abs(b[i]-b[i-1]);
				ans=min(ans, tot-cur+cur2);
				b[i]=x;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
