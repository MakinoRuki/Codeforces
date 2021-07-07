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
#define N 65
#define SZ 200000002
using namespace std;
typedef long long ll;
const ll inf = 1000000000000000000LL;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, x, y;
ll n;
string ks;
ll dp[N][N];
ll pw[N];
ll getnum(string s) {
	if (s.size() >= 10) return n+2;
	ll res= 0LL;
	for (int i = s.size()-1; i >= 0; --i) {
		res = res * 10LL + s[i]-'0';
	}
	return res;
}
int main() {
	cin>>n>>ks;
	m = (int)ks.size();
	reverse(ks.begin(), ks.end());
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j] = (1LL<<62)-1;
		}
	}
	pw[0] = 1LL;
	for (int i = 1; i <= m; ++i) {
		if (pw[i-1] > ((1LL<<62)-1)/n) {
			pw[i] = (1LL<<62)-1;
		} else {
			pw[i] = pw[i-1] * (ll)n;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (i+1 > 1 && ks[i] == '0') {
			continue;
		}
		ll res = getnum(ks.substr(0, i+1));
		if (res >= n) break;
		dp[i][0] = res;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (dp[i][j] < (1LL<<62)-1) {
				for (int k = i+1; k < m; ++k) {
					if (k-i > 1 && ks[k] == '0') {
						continue;
					}
					ll res = getnum(ks.substr(i+1, k-i));
					if (res >= n) break;
					if (pw[j+1] >= inf || res >= ((1LL<<62)-1)/pw[j+1]) {
						break;
					}
					dp[k][j+1] = min(dp[k][j+1], dp[i][j] + res * pw[j+1]);
				//	if (k == ks.size()-1 && j+1==1) cout<<i<<" "<<j<<" "<<k<<" "<<dp[k][j+1]<<endl;
				}
			}
		}
	}
	ll ans = (1LL<<62)-1;
	for (int i = 0; i < m; ++i) {
	//	cout<<i<<" "<<dp[m-1][i]<<endl;
		ans = min(ans, dp[m-1][i]);
	}
	cout<<ans<<endl;
  return 0;
}
