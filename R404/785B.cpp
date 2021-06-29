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
int l[N][2], r[N][2];
int getres(int l1, int r1, int l2, int r2) {
	if (l1 <= r2 && l2 <= r1) {
		return 0;
	}
	if (r2 < l1) return l1 - r2;
	return l2 - r1;
}
int main() {
	// cin>>t;
	// for (int cas=1; cas<=t; ++cas) {
	// 	scanf("%d", &n);
	// }
	vector<pair<int,int>> rk[2];
	rk[0].clear();
	rk[1].clear();
	int r1 = INT_MAX;
	int l1 = INT_MIN;
	int r2 = INT_MAX;
	int l2 = INT_MIN;
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i][0], &r[i][0]);
		l1 = max(l1, l[i][0]);
		r1 = min(r1, r[i][0]);
	}
	cin>>m;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i][1], &r[i][1]);
		l2 = max(l2, l[i][1]);
		r2 = min(r2, r[i][1]);
		// rk[0].push_back(make_pair(r[i][1], l[i][1]));
		// rk[1].push_back(make_pair(l[i][1], r[i][1]));
	}
	// sort(rk[0].begin(), rk[0].end());
	// sort(rk[1].begin(), rk[1].end());
	int ans = INT_MIN;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, getres(l[i][0], r[i][0], l2, r2));
	}
	for (int i = 1; i <= m; ++i) {
		ans = max(ans, getres(l[i][1], r[i][1], l1, r1));
	}
	cout<<ans<<endl;
  return 0;
}
