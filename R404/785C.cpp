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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n, m;
int k;
int q;
int main() {
	// cin>>t;
	// for (int cas=1; cas<=t; ++cas) {
	// 	scanf("%d", &n);
	// }
	cin>>n>>m;
	if (n < m) {
		cout<<n<<endl;
	} else {
		ll det = 2LL * (n-m);
		ll l = 0, r = det;
		while(l < r) {
			ll mid = (l+r)/2;
			if (mid >= 2000000000LL || mid * (mid+1) >= det) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		printf("%lld\n", m + r);
	}
  return 0;
}
