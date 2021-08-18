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
#define N 2002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int dp[N];
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i <= n; ++i) {
			dp[i] = -1;
		}
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (dp[i] < 0) continue;
			for (int j = i+1; j <= n; ++j) {
				if (a[j] > j) continue;
				int det1=i-a[i];
				int det2=j-a[j];
				if (det1 <= det2 && det2-det1 <= j-i-1) {
					dp[j] = max(dp[j], dp[i]+1);
				}
			}
		}
		int ans=INT_MAX;
		for (int i = 0; i <= n; ++i) {
			if (dp[i] >= k) {
				ans = min(ans, i-a[i]);
			}
		}
		printf("%d\n", (ans<INT_MAX ? ans : -1));
	}
  return 0;
}
