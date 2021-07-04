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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
string s;
int a[30];
int idx[N];
ll dp[N][3];
int main() {
	cin>>n;
	cin>>s;
	for (int i = 0; i < 26; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; --i) {
		bool vis[26];
		memset(vis, false, sizeof(vis));
		idx[i] = 1;
		for (int j = i; j >= 1; --j) {
			vis[s[j-1]-'a'] = true;
			int len = i-j+1;
			int k=0;
			for (k = 0; k < 26; ++k) {
				if (vis[k] && a[k] < len) {
					break;
				}
			}
			if (k < 26) {
				break;
			} else {
				idx[i] = j;
			}
		}
	//	cout<<"i="<<i<<" "<<idx[i]<<endl;
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = 0;
		dp[i][1] = -1;
		dp[i][2] = INT_MAX;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= idx[i]; --j) {
			dp[i][0] = (dp[i][0] + dp[j-1][0]) % mod;
			dp[i][1] = max(dp[i][1], max((ll)(i-j+1), dp[j-1][1]));
			dp[i][2] = min(dp[i][2], dp[j-1][2]+1);
		}
	}
	for (int i = 0; i < 3; ++i) {
		printf("%lld\n", dp[n][i]);
	}
  return 0;
}
