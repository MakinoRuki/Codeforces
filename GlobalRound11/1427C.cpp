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
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int r,n;
int dp[N];
vector<pair<pair<int,int>,int>> cs;
int main() {
	cin>>r>>n;
	cs.clear();
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		int t,x,y;
		scanf("%d%d%d", &t, &x, &y);
		if (abs(x-1)+abs(y-1)<=t) {
			dp[i]=1;
		}
		cs.push_back(make_pair(make_pair(x,y),t));
	}
	int pre=1;
	int pmaxv=-1;
	for (int i = 1; i <= n; ++i) {
		while(pre<=n && i-pre>=2*r) {
			pmaxv=max(pmaxv, dp[pre]);
			pre++;
		}
		for (int j = 1; j <= 2*r+1; ++j) {
			if (i-j<1) break;
			int dx=abs(cs[i-1].first.first-cs[i-j-1].first.first);
			int dy=abs(cs[i-1].first.second-cs[i-j-1].first.second);
			int dt=abs(cs[i-1].second-cs[i-j-1].second);
			if (dx+dy<=dt && dp[i-j]>=0) {
				dp[i]=max(dp[i], dp[i-j]+1);
			}
		}
		if (pmaxv>=0) {
			dp[i]=max(dp[i], pmaxv+1);
		}
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
