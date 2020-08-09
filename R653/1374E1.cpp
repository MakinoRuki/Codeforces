#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int t[N], a[N], b[N];
ll sum[3][N];
int main() {
	cin>>n>>k;
	vector<int> ts[3];
	ts[0].clear();
	ts[1].clear();
	ts[2].clear();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &t[i], &a[i], &b[i]);
		if (a[i]==1 && b[i]==0) {
			ts[0].push_back(t[i]);
		} else if (a[i]==0 && b[i]==1) {
			ts[1].push_back(t[i]);
		} else if (a[i]==1 && b[i]==1) {
			ts[2].push_back(t[i]);
		}
	}
	for (int i = 0; i < 3; ++i) {
		sort(ts[i].begin(), ts[i].end());
		sum[i][0] = 0LL;
		for (int j = 1; j <= ts[i].size(); ++j) {
			sum[i][j] = sum[i][j-1] + ts[i][j-1];
		}
	}
	ll ans = (1LL<<61);
	for (int i = 0; i <= ts[2].size(); ++i) {
		int d1 = max(0, k-i);
		if (d1 <= ts[1].size() && d1 <= ts[0].size()) {
			ll c = sum[2][i] + sum[0][d1] + sum[1][d1];
			ans = min(ans, c);
		}
	}
	if (ans < (1LL<<61)) {
		cout<<ans<<endl;
	} else {
		cout<<-1<<endl;
	}
	return 0;
}
