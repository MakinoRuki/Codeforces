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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int ph[N];
bool pr[N];
int l[N], r[N];
ll dp[2][N];
int det[N];
int main() {
	memset(pr, true, sizeof(pr));
	for (int i = 1; i < N; ++i) {
		ph[i] = 1;
	}
	for (int i = 2 ; i < N; ++i) {
		if (pr[i]) {
			ph[i] = -1;
			if (i <= (int)sqrt(N)) {
				for (int j = i*i; j < N; j += i*i) {
					ph[j] = 0;
				}
			}
			for (int j = 2*i; j < N; j += i) {
				pr[j] = false;
				ph[j] *= -1;
			}
		}
	}
	cin>>n>>m;
//	init(m);
	// for (int i = 1; i <= m; ++i) {
	// 	if (ph[i] != mu[i]) {
	// 		cout<<i<<" "<<ph[i]<<" "<<mu[i]<<endl;
	// 	}
	// }
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
	}
	ll ans = 0LL;
	for (int g = 1; g <= m; ++g) {
		if (ph[g] == 0) continue;
	//	cout<<g<<" "<<ph[g]<<endl;
		bool ok=true;
		ll tot=0LL;
		for (int i = 1; i <= n; ++i) {
			int lb = (l[i]+g-1)/g;
			int rb = r[i]/g;
			if (lb > rb) {
				ok=false;
				break;
			}
			tot += lb;
			det[i] = rb-lb;
		}
		if (!ok || tot > m/g) {
			continue;
		}
		int k = m/g-tot;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[i][j] = 0LL;
			}
		}
		dp[0][0] = 1LL;
		for (int i = 0; i < n; ++i) {
			int now = i&1;
			for (int j = 0; j <= k; ++j) {
				dp[now^1][j] = 0LL;
			}
			for (int j = 0; j <= k; ++j) {
				if (j + det[i+1] + 1 <= k) {
					dp[now^1][j+det[i+1]+1] = (dp[now^1][j+det[i+1]+1] - dp[now][j] + mod2) % mod2;
				}
			}
			for (int j = 0; j <= k; ++j) {
				dp[now^1][j] = (dp[now^1][j] + dp[now][j]) % mod2;
			}
			for (int j = 0; j < k; ++j) {
				dp[now^1][j+1] = (dp[now^1][j+1] + dp[now^1][j]) % mod2;
			}
		}
		tot = 0LL;
		for (int j = 0; j <= k; ++j) {
			tot = (tot + dp[n&1][j]) % mod2;
		}
	//	cout<<"g="<<g<<" "<<tot<<endl;
		if (ph[g] > 0) ans = (ans + tot) % mod2;
		else ans = (ans - tot + mod2) % mod2;
	}
	printf("%lld\n", ans);
  return 0;
}
