#pragma GCC optimize(2)
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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, l, r, k;
string s;
int a[3][N];
ll sum[3][N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &m);
		for (int i = 1; i <= 2; ++i) {
			sum[i][0] = 0LL;
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);
				sum[i][j] = 0LL;
			}
		}
		for (int i = 1; i <= 2; ++i) {
			for (int j = 1; j <= m; ++j) {
				sum[i][j] = sum[i][j-1] + a[i][j];
			}
		}
		ll ans = -1;
		for (int i = 1; i <= m; ++i) {
			ll tot = max(sum[2][i-1], sum[1][m]-sum[1][i]);
			if (ans < 0) ans = tot;
			else ans = min(ans, tot);
		}
		printf("%lld\n", ans);
	}
  return 0;
}
