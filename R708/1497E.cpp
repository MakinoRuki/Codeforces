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
#define M 25
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int a[N];
int b[N];
int idx[N][M];
int dp[N][M];
int cnt[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		vector<pair<int,int>> rk;
		rk.clear();
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			for (int j = 2; j*j <= a[i]; ++j) {
				if (a[i]%(j*j)==0) {
					while(a[i]%(j*j) == 0) {
						a[i] /= (j*j);
					}
				}
			}
			rk.push_back(make_pair(a[i], i));
		}
		sort(rk.begin(), rk.end());
		for (int i = 0; i < rk.size(); ++i) {
			if (i == 0 || rk[i].first != rk[i-1].first) {
				tot++;
			}
			b[rk[i].second] = tot;
		}
		for (int x = 0; x <= k; ++x) {
			int j = 1;
			int num=0;
			for (int i = 1; i <= tot; ++i) {
				cnt[i] = 0;
			}
			for (int i = 1; i <= n; ++i) {
				cnt[b[i]]++;
				if (cnt[b[i]] == 1) {
					num++;
				}
		//		if (x==1) cout<<"i="<<i<<" "<<b[i]<<" "<<cnt[b[i]]<<" "<<num<<endl;
				while(j<=i && (i-j+1-num) > x) {
					cnt[b[j]]--;
					if (cnt[b[j]] == 0) num--;
					j++;
				}
			//	if (x==1) cout<<"ij="<<i<<" "<<j<<endl;
				idx[i][x] = j;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[i][j] = INT_MAX;
				for (int j2 = 0; j2 <= j; ++j2) {
					int i2 = idx[i][j2];
					if (dp[i2-1][j-j2] < INT_MAX) {
						dp[i][j] = min(dp[i][j], dp[i2-1][j-j2] + 1);
					}
				}
			//	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
		int ans=INT_MAX;
		for (int i = 0; i <= k; ++i) {
			ans = min(ans, dp[n][i]);
		}
		printf("%d\n", ans);
	}
  return 0;
}
