#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 200005
#define M 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, q, m;
int a[N];
int st[N];
int idx[N];
vector<int> ps[N];
int dp[N][22];
int main() {
	cin>>n>>q;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(idx, -1, sizeof(idx));
	int j = n;
	for (int i = n; i >= 1; --i) {
		ps[i].clear();
		int x = a[i];
		for (int j = 2; j*j <= x; ++j) {
			if (x%j == 0) {
				ps[i].push_back(j);
				while(x%j==0) {
					x /= j;
				}
			}
		}
		if (x>1) ps[i].push_back(x);
		int pid = 2*n;
		for (int p : ps[i]) {
			if (idx[p] > 0) {
				pid = min(pid, idx[p]);
			}
		}
		if (pid <= n) {
			while(j >= pid) {
				for (int p : ps[j]) {
					idx[p] = -1;
				}
				j--;
			}
		}
		st[i] = j;
		for (int p : ps[i]) {
			idx[p] = i;
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = n; i >= 1; --i) {
		dp[i][0] = st[i];
	}
	for (int i = 1; i <= 20; ++i) {
		for (int j = n; j >= 1; --j) {
			int id1 = dp[j][i-1];
			if (id1 >= 1 && id1 < n && dp[id1+1][i-1] >= 1) {
				dp[j][i] = dp[id1+1][i-1];
			}
		}
	}
	while(q-->0) {
		int l, r;
		scanf("%d%d", &l, &r);
		int tot=0;
		int cur = l;
		for (int i = 20; i >= 0; --i) {
			if (dp[cur][i] <= 0) continue;
			if (dp[cur][i] == r) {
				tot += (1<<i);
				cur = r+1;
				break;
			} else if (dp[cur][i] < r) {
				tot += (1<<i);
				cur = dp[cur][i]+1;
			}
		}
		if (cur <= r) tot++;
		printf("%d\n", tot);
	}
	return 0;
}

/*myturn.ca.gov*/
