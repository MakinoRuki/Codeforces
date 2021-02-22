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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll a[N];
ll x[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
		map<ll, int> idx;
		idx.clear();
		ll maxv=0LL, sum=0LL;
		for (int i = 1; i <= n; ++i) {
			sum += a[i];
			if (sum > maxv) {
				maxv = sum;
				idx[maxv] = i;
			}
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%lld", &x[i]);
			if (maxv <= 0) {
				printf("%d", -1);
			} else {
				if (maxv < x[i] && sum <= 0) {
					printf("%d", -1);
				} else {
					ll det = 0LL;
					if (x[i]> maxv) {
						det = (x[i]-maxv+sum-1)/sum;
					}
					ll ans = det*n;
					x[i] -= det*sum;
					if (x[i]>0) {
						auto itr = idx.lower_bound(x[i]);
						ans += itr->second-1;
					}
					printf("%lld", ans);
				}
			}
			if (i <m) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
