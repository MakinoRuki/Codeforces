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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n,x;
int a[N];
int dp[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+n+1);
		dp[n+1] = 0;
		for (int i = n; i >= 1; --i) {
			dp[i] = dp[i+1];
			int num = (x+a[i]-1)/a[i];
			if (i + num-1 <= n) dp[i] = max(dp[i], dp[i+num]+1);
		}
		printf("%d\n", dp[1]);
	}
	return 0;
}
