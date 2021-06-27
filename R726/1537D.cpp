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
int t, n, m;
int k;
int q;
int a[N];
int dp[N][2];
int dfs(int x, int p) {
	if (dp[x][p] >= 0) return dp[x][p];
	int res = 1;
	bool found = false;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			found=true;
			res &= dfs(x-i, !p);
			if (x/i != i) {
				res &= dfs(x-x/i, !p);
			}
		}
	}
	if (!found) {
		return dp[x][p] = 0;
	}
	return dp[x][p] = !res;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		int x = n;
		int cnt=0;
		if (n % 2) {
			puts("Bob");
		} else {
			while(x % 2 == 0) {
				cnt++;
				x /= 2;
			}
			if (x > 1) {
				puts("Alice");
			} else {
				if (cnt % 2) {
					puts("Bob");
				} else {
					puts("Alice");
				}
			}
		}
		// memset(dp, -1, sizeof(dp));
		// int res = dfs(n, 0);
		// cout<<res<<endl;
	}
	// for (n = 2; n <= 200; ++n) {
	// 	memset(dp, -1, sizeof(dp));
	// 	int res = dfs(n, 0);
	// 	if (res) cout<<"n="<<n<<" "<<res<<endl;
	// }
  return 0;
}
