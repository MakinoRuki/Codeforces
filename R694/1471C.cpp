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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t, n, m;
int k[N];
int c[N];
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &k[i]);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &c[i]);
		}
		sort(k+1, k+1+n);
		ll tot=0LL;
		int r = n;
		int l = 1;
		while(c[l] < c[k[r]]) {
			tot += c[l++];
			r--;
		}
		while(r>0) {
			tot += c[k[r]];
			r--;
		}
		printf("%lld\n", tot);
	}
	return 0;
}
