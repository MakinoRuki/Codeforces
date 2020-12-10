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
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
int a[N];
int q;
int dp[N][N];
int b[N][N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			if (i==j) b[i][j] = a[i];
			else {
				b[i][j]= b[i][j-1]^b[i+1][j];
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i; j <= n; ++j) {
			dp[i][j]= (i==j ? b[i][j] : max(max(dp[i+1][j], dp[i][j-1]),b[i][j]));
		}
	}
	cin>>q;
	while(q-->0) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l][r]);
	}
	return 0;
}
