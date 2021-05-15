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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll x;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld", &x);
		if (x == 0) {
			printf("%d %d\n", 1, 1);
		} else {
			bool found=false;
			for (ll n = 1; n <= 100000LL; ++n) {
				if (n*n > x) {
					ll det = n*n-x;
					if (det <= 0) continue;
					ll sq = (ll)sqrt(det);
					if (sq*sq == det) {
						ll m = n/sq;
						if (n/m == sq) {
							printf("%lld %lld\n", n, m);
							found = true;
							break;
						}
					}
				}
			}
			if (!found) puts("-1");
		}
	}
	// cin>>x;
	// ll n = 31853LL;
	// cout<<n*n<<" "<<n*n-x<<endl;
	// ll det = n*n-x;
	// ll sq = (ll)sqrt(det);
	// cout<<det<<" "<<sq*sq<<" "<<sq<<endl;
	// cout<<n/8<<endl;

  return 0;
}
