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
#define M 10005
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int a[N];
int b[N];
int idx[N];
bool vis[N];
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			idx[a[i]] = i;
			vis[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
		}
		int cnt=0;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				int x=idx[b[i]];
				while(x != i) {
					vis[x] = true;
					x = idx[b[x]];
				}
				vis[i] = true;
				cnt++;
			}
		}
		ll ans = 1LL;
		for (int i = 1; i <= cnt; ++i) {
			ans = ans * 2LL % mod;
		}
		printf("%lld\n", ans);
	}
  return 0;
}
