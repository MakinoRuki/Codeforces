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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll a,b;
		scanf("%lld%lld", &a, &b);
		if (a == b) {
			printf("%d %d\n", 0, 0);
		} else {
			ll d = abs(a-b);
			ll r = a % d;
			ll res = min(r, d-r);
			printf("%lld %lld\n", d, res);
		}
	}
  return 0;
}
