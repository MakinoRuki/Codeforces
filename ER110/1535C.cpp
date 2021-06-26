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
#define M 52
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
string s;
ll dp[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>s;
		int pre = -1;
		n = (int)s.size();
		for (int i = 0; i <= n; ++i) {
			dp[i] = 0;
		}
		ll ans = 0LL;
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?') {
				if (pre >= 0) {
					int det = i-pre;
					if (s[pre] == s[i]) {
						if (det % 2==0) {
							dp[i] = (ll)det + dp[pre];
						} else {
							dp[i] = (ll)det;
						}
					} else {
						if (det % 2) {
							dp[i] = (ll)det + dp[pre];
						} else {
							dp[i] = (ll)det;
						}
					}
				} else {
					dp[i] = (ll)i+1;
				}
				pre = i;
			} else {
				if (pre >= 0) {
					int det = i-pre;
					dp[i] = (ll)det + dp[pre];
				} else {
					dp[i] = (ll)i+1;
				}
			}
			ans += dp[i];
		}
		printf("%lld\n", ans);
	}
  return 0;
}
