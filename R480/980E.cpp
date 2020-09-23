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
#define M 20005
#define N 1000002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
vector<int> edges[N];
int par[N][21];
bool vis[N];
void dfs(int u, int p) {
	par[u][0] = p;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs(v, u);
	}
}
int main() {
	cin>>n>>k;
	for (int i = 1; i < n; ++i) {
		int a,b;
		scanf("%d%d", &a,&b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	memset(par, -1, sizeof(par));
	dfs(n, -1);
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (par[j][i-1]>0 && par[par[j][i-1]][i-1]>0) {
				par[j][i] = par[par[j][i-1]][i-1];
			}
		}
	}
//	cout<<"p="<<par[2][0]<<endl;
	memset(vis, false, sizeof(vis));
	int tot=0;
	vis[n]=true;
	tot++;
	for (int i = n-1; i >= 1; --i) {
		if (vis[i]) continue;
		int x=i;
		int cnt=1;
		for (int j = 20 ; j>=0; --j) {
			if (par[x][j]<=0) continue;
			if (!vis[par[x][j]]) {
			//	if (i==2) cout<<"j="<<x<<" "<<j<<" "<<par[x][j]<<endl;
				x=par[x][j];
				cnt += (1<<j);
			}
		}
		if (cnt +tot<=n-k) {
			int y=i;
			while(y != x) {
				tot++;
				vis[y]=true;
				y=par[y][0];
			}
			vis[y]=true;
			tot++;
		}
		//cout<<"i="<<i<<" "<<cnt<<" "<<tot<<endl;
	}
	int cnt=0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			printf("%d", i);
			cnt++;
			if (cnt == n-k) {
				cout<<endl;
			} else {
				cout<<" ";
			}
		}
	}
	return 0;
}
