#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int t;
int n;
ll k;
ll p[N];
ll dp[N];
int main() {
	cin>>t;
	for (int cas=1;cas<=t; ++cas) {
		cin>>n>>k;
		p[0] = p[1] = 1;
		for (int i =2 ; i <= n; ++i) {
			// 当方案数过多(多于k,k<=10^18)时，可以不必再计算。
			if (p[i-1] <= inf/(ll)i) {
				p[i] = p[i-1] * (ll)i;
			} else {
				p[i] = inf;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[n] = 1;
		dp[n+1] = 1;
		for (int i = n-1; i >= 1; --i) {
			dp[i] = p[n-i-1];
			for (int j = i+1; j <= n; ++j) {
				if (p[max(j-i-2,0)] <= inf/dp[j]) {
					ll v = p[max(j-i-2, 0)] * dp[j];
					if (dp[i] <= inf - v) {
						dp[i] += v;
					} else {
						dp[i] = inf;
					}
				} else {
					dp[i] = inf;
				}
			}
		}
		if (dp[1] < k) {
			cout<<"-1"<<endl;
			continue;
		}
		vector<int> ans(n+1, -1);
		bool vis[N];
		memset(vis, false, sizeof(vis));
		int i = 1;
		int tot=n;
		while(i <= n) {
		//	cout<<i<<" "<<tot<<endl;
			int j;
			for (j = 1; j <= tot; ++j) {
				ll v = p[max(j-2, 0)] * dp[i+j];
				if (v < k) {
					k -= v;
					continue;
				} else {
					break;
				}
			}
		//	cout<<"j="<<j<<endl;
			ans[i] = n-tot+j;
			vis[n-tot+j] = true;
			for (int t = 1; t < j; ++t) {
				for (int t2 = 1; t2 < j; ++t2) {
					if (vis[n-tot+t2] || t2 == t + 1) continue;
					if (t < j-1) {
						int nxt = ans[n-tot+t2];
						while(nxt != -1 && nxt != i+t) {
							nxt = ans[nxt];
						}
						if (nxt == i+t) continue;
					}
					int lft = j-t-1;
					ll v = (p[max(lft-1, 0)] <= inf/dp[i+j] ? p[max(lft-1, 0)] * dp[i+j] : inf);
					if (v < k) {
						k -= v;
						continue;
					}
					ans[i+t] = n-tot+t2;
					vis[n-tot+t2] = true;
					break;
				}
			}
			i += j;
			tot -= j;
		//	cout<<"k="<<k<<endl;
		}
		for (int i = 1; i <= n; ++i) {
			cout<<ans[i];
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
