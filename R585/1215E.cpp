#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 400005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int a[N];
ll dp[1<<20];
ll cnt[21][21];
vector<int> pos[21];
int main() {
	cin>>n;
	for (int i = 1; i <= 20; ++i) {
		pos[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			if (i == j) continue;
			int p1 = 0;
			int p2 = 0;
			while(p2 < pos[j].size()) {
				if (p1 >= pos[i].size()) break;
				if (pos[j][p2] < pos[i][p1]) {
					cnt[i][j] += pos[i].size()-p1;
					p2++;
				} else {
					p1++;
				}
			}
		}
	}
	//cout<<cnt[3][4]<<" "<<cnt[3][2]<<" "<<cnt[4][2]<<endl;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < (1<<20); ++i) {
		if (dp[i] >= 0) {
			for (int j = 0; j < 20; ++j) {
				if ((1<<j) & i) continue;
				ll cost = dp[i];
				for (int k = 0; k < 20; ++k) {
					if ((1<<k) & i) {
						cost += cnt[k+1][j+1];
					}
				}
			//	if (i == 14) cout<<j<<" "<<dp[i]<<" "<<cost<<endl;
				if (dp[i | (1<<j)] < 0) dp[i|(1<<j)] = cost;
				else dp[i|(1<<j)] = min(dp[i|(1<<j)], cost);
			}
		}
	}
//	cout<<dp[14]<<endl;
	cout<<dp[(1<<20)-1]<<endl;
	return 0;
}
