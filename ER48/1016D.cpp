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
#define M 21
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[N], b[N];
int ans[N][N];
int main() {
	cin>>n>>m;
	int res1=0,res2=0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		res1^=a[i];
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		res2^=b[i];
	}
	memset(ans, 0, sizeof(ans));
	if (res1 != res2) {
		puts("NO");
	} else {
		for (int i = 30; i >= 0; --i) {
			for (int r = 1; r < n; ++r) {
				if ((1<<i) & a[r]) {
					ans[r][1] |= (1<<i);
				}
			}
			for (int c = 1; c <= m; ++c) {
				int res=0;
				for (int r = 1; r < n; ++r) {
					if ((1<<i) & ans[r][c]) {
						res ^= 1;
					}
				}
				int res2=(b[c] & (1<<i))>0;
				if (res != res2) {
					ans[n][c] |= (1<<i);
				}
			}
		}
		puts("YES");
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("%d", ans[i][j]);
				if (j < m) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}
