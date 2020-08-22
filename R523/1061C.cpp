#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N];
ll dp[N];
int main() {
	cin>>n;
	memset(dp, 0LL, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		vector<int> ps;
		ps.clear();
		for (ll i = 2; i * i <= x; ++i) {
			if (x%i==0) {
				ps.push_back(i);
				if (x/i != i) {
					ps.push_back(x/i);
				}
			}
		}
		ps.push_back(x);
		sort(ps.begin(), ps.end());
		for (int j = ps.size()-1; j >= 0; --j) {
			if (ps[j] > 1 && ps[j] <= n) {
				dp[ps[j]] = (dp[ps[j]] + dp[ps[j]-1]) % mod;
			}
		}
		dp[1] = (dp[1]+1)%mod;
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		ans = (ans + dp[i]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
