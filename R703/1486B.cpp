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
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		vector<int> xs,ys;
		xs.clear();
		ys.clear();
		for (int i = 1; i <= n; ++i) {
			int x,y;
			scanf("%d%d", &x, &y);
			xs.push_back(x);
			ys.push_back(y);
		}
		sort(xs.begin(), xs.end());
		sort(ys.begin(), ys.end());
		if (n%2) {
			printf("%d\n", 1);
		} else {
			int a1 = xs[n/2-1];
			int a2 = xs[n/2];
			int b1 = ys[n/2-1];
			int b2 = ys[n/2];
			ll ans = (ll)(a2-a1+1) * (ll)(b2-b1+1);
			printf("%lld\n", ans);
		}
	}
  return 0;
}
