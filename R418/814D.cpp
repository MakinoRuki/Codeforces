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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
vector<pair<pair<int,int>, int>> cs;
ll dp[N][2][2];
int deg[N];
bool check(int x, int y) {
	ll a1=cs[x-1].first.first;
	ll b1=cs[x-1].first.second;
	ll r1=cs[x-1].second;
	ll a2=cs[y-1].first.first;
	ll b2=cs[y-1].first.second;
	ll r2=cs[y-1].second;
	if (r1>r2 && (a1-a2)*(a1-a2)+(b1-b2)*(b1-b2)<=(r1-r2)*(r1-r2)) {
		return true;
	}
	return false;
}
void dfs(int u, int p) {
	ll r=cs[u-1].second;
	if (edges[u].empty()) {
		for (int j1=0; j1 <2 ;++j1) {
			for (int j2=0; j2<2; ++j2) {
				if (j1==0 && j2==0) {
					dp[u][j1][j2]=-r*r;
				} else {
					dp[u][j1][j2]=r*r;
				}
			}
		}
		return ;
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs(v, u);
	}
	for (int j1=0; j1 <2 ;++j1) {
		for (int j2=0; j2<2; ++j2) {
			if (j1==1 && j2==1) {
				ll tot=0LL;
				for (int i = 0; i < edges[u].size(); ++i) {
					int v=edges[u][i];
					if (v==p) continue;
					tot += max(dp[v][1][0], dp[v][0][1]);
				}
				dp[u][j1][j2]=tot + r*r;
			} else if (j1==0 && j2==0) {
				ll tot=0LL;
				for (int i = 0; i < edges[u].size(); ++i) {
					int v=edges[u][i];
					if (v==p) continue;
					tot += max(dp[v][1][0], dp[v][0][1]);
				}
				dp[u][j1][j2]=tot-r*r;
			} else {
				ll tot1=0LL, tot0=0LL;
				for (int i = 0; i < edges[u].size(); ++i) {
					int v=edges[u][i];
					if (v==p) continue;
					tot1 += dp[v][1][1];
					tot0 += dp[v][0][0];
				}
				dp[u][j1][j2] = max(tot1-r*r, tot0+r*r);
			}
		}
	}
}
int main() {
	cin>>n;
	cs.clear();
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= n; ++i) {
		int x,y,r;
		scanf("%d%d%d", &x, &y, &r);
		cs.push_back(make_pair(make_pair(x,y),r));
	}
	for (int i = 1; i <= n; ++i) {
		int id=-1;
		int r=inf;
		for (int j = 1; j <= n; ++j) {
			if (j != i && check(j, i)) {
				if (cs[j-1].second < r) {
					id=j;
					r=cs[j-1].second;
				}
			}
		}
		if (id>=0) {
			deg[i]++;
			edges[id].push_back(i);
		}
	}
//	cout<<"ok="<<check(1, 2)<<endl;
	// for (int i = 1; i <= n; ++i) {
	// 	cout<<"i="<<i<<endl;
	// 	for (int j = 0; j < edges[i].size(); ++j) {
	// 		cout<<edges[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	ll tot=0LL;
	for (int i = 1; i <= n; ++i) {
		if (deg[i]==0) {
			dfs(i, 0);
			ll res=dp[i][1][1];
			tot += res;
		}
	}
	double ans=tot*acos(-1.0);
	printf("%.10lf\n", ans);
	return 0;
}
