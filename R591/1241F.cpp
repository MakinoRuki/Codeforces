#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define N 300005
using namespace std;
typedef long long ll;
int q, n;
int a[N];
map<int, int> nxtx[N];
int nxt[N];
ll dp[N];
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			cin>>a[i];
			nxt[i] = -1;
			nxtx[i].clear();
			dp[i] = 0;
		}
		dp[n+1] = 0;
		nxtx[n+1].clear();
		nxt[n+1] = -1;
		for (int i = n; i >= 1; --i) {
			if (nxtx[i+1].count(a[i])) {
				int r = nxtx[i+1][a[i]];
				nxt[i] = r;
				swap(nxtx[i], nxtx[r+1]);
				if (r + 1 <= n) {
					nxtx[i][a[r+1]] = r+1;
				}
			}
			nxtx[i][a[i]] = i;
		}
		ll ans=0LL;
		for (int i = n ; i >= 1; --i) {
			if (nxt[i] >= 0) {
				dp[i] = dp[nxt[i]+1] + 1;
				ans += dp[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
