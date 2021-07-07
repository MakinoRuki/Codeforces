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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
ll k;
int x, y;
ll mat[N][N];
int main() {
	cin>>n>>m>>k>>x>>y;
	if (n == 1) {
		ll det = k/m;
		ll r = k%m;
		ll maxv = (r > 0 ? det + 1 : det);
		ll minv = det;
		ll ans = det;
		if (y <= r) ans = det+1;
		cout<<maxv<<" "<<minv<<" "<<ans<<endl;
		return 0;
	}
	ll det = k / (2*(n-1)*m);
	ll r = k % (2*(n-1)*m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			mat[i][j] = ((i == 1 || i == n) ? det : 2LL*det);
		}
	}
	for (int i = 1; i < n; ++i) {
		if (r == 0) break;
		for (int j = 1; j <= m; ++j) {
			if (r == 0) break;
			mat[i][j]++;
			r--;
		}
	}
	for (int i = n; i >= 1; --i) {
		if (r == 0) break;
		for (int j = 1; j <= m; ++j) {
			if (r == 0) break;
			mat[i][j]++;
			r--;
		}
	}
	ll maxv = -1;
	ll minv = -1;
	ll ans = mat[x][y];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1) {
				maxv = mat[i][j];
				minv = mat[i][j];
			} else {
				maxv = max(maxv, mat[i][j]);
				minv = min(minv, mat[i][j]);
			}
		}
	}
	cout<<maxv<<" "<<minv<<" "<<ans<<endl;
  return 0;
}
