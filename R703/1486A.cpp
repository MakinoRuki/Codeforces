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
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
ll h[N];
ll sum[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i =1 ; i <= n; ++i) {
			scanf("%lld", &h[i]);
		}
		sum[0] = 0LL;
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i-1]+h[i];
		}
		bool ok=true;
		for (int i = 1; i <= n; ++i) {
			ll v = (ll)i*(ll)(i-1)/2;
			if (sum[i] < v) {
				ok=false;
				break;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}
