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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
ll k;
// ll dp[N];
// ll sum[N];
int main() {
	// memset(dp, 0LL, sizeof(dp));
	// memset(sum, 0LL, sizeof(sum));
	// dp[1] = 1LL;
	// sum[1] = 1LL;
	// for (int i = 2; i <= 60; ++i) {
	// 	dp[i] = sum[i-1]+1LL;
	// 	if (sum[i-1] + dp[i] > 4000000000000000000LL) {
	// 	 	sum[i] = 4000000000000000000LL;
	// 	 } else {
	// 		sum[i] = sum[i-1]+dp[i];
	// 	}
	// 	//cout<<i<<" "<<sum[i]<<endl;
	// }
//	cout<<dp[69]<<" "<<dp[110]<<endl;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d%lld", &n, &k);
		vector<int> ans;
		ans.clear();
		if (n <= 60 && ((1LL<<(n-1)) < k)) {
			puts("-1");
		} else {
			int cur=1;
			while(ans.size() < n) {
				if (n - cur > 60) {
					ans.push_back(cur);
					cur++;
				} else {
					for (int i = cur; i <= n; ++i) {
						int det = n - i;
						ll det2 = (det > 0 ? (1LL<<(det-1)) : 1);
						if (det2<k) {
							k -= det2;
						} else {
							for (int j = i; j >= cur; --j) {
								ans.push_back(j);
							}
							cur = i+1;
							break;
						}
					}
				}
			}
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i]);
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}
