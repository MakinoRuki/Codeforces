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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,q;
int n;
int a[N];
vector<int> edges[N];
vector<int> ps[N];
int dp[N][10];
int ans;
void dfs(int u, int p) {
	for (int j = 0; j < edges[u].size(); ++j) {
			int v=edges[u][j];
			if (v==p) continue;
			dfs(v, u);
	}
	for (int i = 0; i < ps[u].size(); ++i) {
		dp[u][i] = 1;
		int m1=-1;
		int m2=-1;
		for (int j = 0; j < edges[u].size(); ++j) {
			int v=edges[u][j];
			if (v==p) continue;
			for (int j2 = 0; j2 < ps[v].size(); ++j2) {
			//	if (u == 1) cout<<i<<" "<<v<<" "<<j2<<" "<<ps[u][i]<<" "<<ps[v][j2]<<endl;
				if (ps[v][j2] == ps[u][i]) {
					if (dp[v][j2] > m2) {
						m1=m2;
						m2=dp[v][j2];
					} else if (dp[v][j2] > m1) {
						m1 = dp[v][j2];
					}
				}
			}
		}
		int res=dp[u][i];
		if (m2 >= 0) res += m2;
		if (m1 >= 0) res += m1;
		if (res >= 1) ans = max(ans, res);
		if (m1 >= 0) dp[u][i]=max(dp[u][i], m1+1);
		if (m2>=0) dp[u][i]=max(dp[u][i], m2+1);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		int x=a[i];
		ps[i].clear();
		for (int j = 2; j*j <= x; ++j) {
			if (x%j==0) {
				ps[i].push_back(j);
				while(x%j==0) {
					x/=j;
				}
			}
		}
		if (x>1) ps[i].push_back(x);
	}
	ans = 0;
	memset(dp, 0, sizeof(dp));
	dfs(1, 0);
//	cout<<ps[3][0]<<" "<<dp[3][0]<<endl;
	printf("%d\n", ans);
	return 0;
}
