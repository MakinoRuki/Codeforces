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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll x,y;
ll c1,c2,c3,c4,c5,c6;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld%lld", &x, &y);
		scanf("%lld%lld%lld%lld%lld%lld",&c1,&c2,&c3,&c4,&c5,&c6);
		ll ans=0LL;
		if (x>=0) {
			if (y>=0) {
				ans=x*c6+y*c2;
				if (x>=y) {
					ans=min(ans, c1*x+c5*(x-y));
					ans=min(ans, c1*y+(x-y)*c6);
				} else {
					ans=min(ans, c1*x+(y-x)*c2);
					ans=min(ans, c1*y+(y-x)*c3);
				}
			} else {
				ans=x*c6+abs(y)*c5;
				ans=min(ans, c1*x+(x-y)*c5);
				ans=min(ans, c4*abs(y)+(x-y)*c6);
			}
		} else {
			if (y>=0) {
				ans=abs(x)*c3+y*c2;
				ans=min(ans, c1*y+(y-x)*c3);
				ans=min(ans, c4*abs(x)+(y-x)*c2);
			} else {
				ans=abs(x)*c3+abs(y)*c5;
				if (abs(x)>=abs(y)) {
					ans=min(ans, abs(y)*c4+(y-x)*c3);
					ans=min(ans, abs(x)*c4+(y-x)*c2);
				} else {
					ans=min(ans, abs(x)*c4+(x-y)*c5);
					ans=min(ans, abs(y)*c4+(x-y)*c6);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
