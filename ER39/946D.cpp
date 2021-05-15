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
#define M 52
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
vector<string> mat;
int cnt[N][N];
int dp[N][N];
int main() {
	cin>>n>>m>>k;
	mat.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		mat.push_back(s);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			cnt[i][j] = INT_MAX;
		}
		int tot=0;
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == '1') {
				tot++;
			}
		}
		cnt[i][tot] = 0;
		for (int k2 = 0; k2 <= k; ++k2) {
			int ub = tot-k2;
			int tot2 = 0;
			int j2 = 0;
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '1') {
					tot2++;
				}
				while(j2 <= j) {
					if (mat[i][j2] == '1') {
						if (tot2 > ub) {
							tot2--;
							j2++;
						} else {
							break;
						}
					} else {
						j2++;
					}
				}
				if (tot2 == ub) {
					cnt[i][k2] = min(cnt[i][k2], j-j2+1);
				}
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j] < INT_MAX) {
				for (int j2 = 0; j+j2 <= k; ++j2) {
					if (cnt[i][j2] < INT_MAX) {
						dp[i+1][j+j2] = min(dp[i+1][j+j2], dp[i][j]+cnt[i][j2]);
					}
				}
			}
		}
	}
//	cout<<"v1="<<dp[1][1]<<" "<<dp[2][1]<<endl;
	int ans = INT_MAX;
	for (int i = 0; i <= k; ++i) {
		ans = min(ans, dp[n][i]);
	}
	printf("%d\n", ans);
  return 0;
}
