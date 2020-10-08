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
#include <queue>
#include <cmath>
#define N 300002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,m;
string s;
vector<int> edges[N];
int vis[N];
int dp[N];
bool dfs(int u) {
	if (vis[u]<0) return false;
	vis[u]=-1;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (vis[v]==1) continue;
		if (!dfs(v)) return false;
	}
	vis[u]=1;
	return true;
}
int dfs2(int u, int c) {
	if (dp[u]>=0) return dp[u];
	dp[u]=0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		dp[u]=max(dp[u],dfs2(v,c));
	}
	dp[u] += (s[u]=='a'+c ? 1: 0);
	return dp[u];
}
int main() {
	cin>>n>>m;
	cin>>s;
	bool found=false;
	for (int i = 0; i < m; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		edges[x-1].push_back(y-1);
		if (x==y) {
			found=true;
		}
	}
	if (found) {
		cout<<-1<<endl;
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (vis[i]==0) {
			if (!dfs(i)) {
				found=true;
				break;
			}
		}
	}
	if (found) {
		cout<<-1<<endl;
		return 0;
	}
	int ans=0;
	for (int c=0;c<26; ++c) {
		for (int i = 0; i < n; ++i) {
			dp[i]=-1;
		}
		for (int i=0;i<n; ++i) {
			if (dp[i]<0) {
				dfs2(i,c);
			}
		}
		for (int i = 0;i<n; ++i) {
			ans=max(ans, dp[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
