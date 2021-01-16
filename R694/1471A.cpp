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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t, n, x;
int a[N];
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		ll minv = 0LL, maxv = 0LL;
		for (int i = 1; i <= n; ++i) {
			minv += (ll)a[i];
			maxv += (ll)(a[i] + x - 1) / (ll)x;
		}
		minv = (minv + x - 1) / (ll)x;
		printf("%lld %lld\n", minv, maxv);
	}
	return 0;
}
