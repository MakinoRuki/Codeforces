#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int n, q, m;
vector<int> edges[N];
int lev[N];
vector<int> lvs, nodes;
int id[N];
int dp[3*N][18];
int f[18][N],h[N];
// void dfs(int u, int p, int l) {
// 	id[u] = lvs.size();
// 	lvs.push_back(l);
// 	nodes.push_back(u);
// 	lev[u] = l;
// 	for (int i = 0;i<edges[u].size(); ++i) {
// 		int v = edges[u][i];
// 		if (v != p) {
// 			dfs(v, u, l+1);
// 			lvs.push_back(l);
// 			nodes.push_back(u);
// 		}
// 	}
// }
// int getlca(int u, int v) {
// 	int id1 = id[u];
// 	int id2 = id[v];
// 	if (id1 > id2) swap(id1, id2);
// 	int len = 0;
// 	while((1<<len) <= id2-id1+1) {
// 		len++;
// 	}
// 	len--;
// 	id2 = id2 - (1<<len) + 1;
// 	int p = (lvs[dp[id1][len]] < lvs[dp[id2][len]] ? nodes[dp[id1][len]] : nodes[dp[id2][len]]);
// 	return p;
// }
void dfs(int x){
	for(auto&i:edges[x])if(i!=f[0][x]){
		f[0][i]=x;h[i]=h[x]+1;dfs(i);
	}
}
int getlca(int x,int y){
	if(h[x]<h[y])swap(x,y);
	for(int i=17; i>=0; --i)if((h[x]-h[y])>>i)x=f[i][x];
	if(x==y)return x;
	for(int i=17; i>=0; --i)if(f[i][x]!=f[i][y])x=f[i][x],y=f[i][y];
	return f[0][x];
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
// 	nodes.clear();
// 	lvs.clear();
// 	dfs(1, 0, 0);
// 	m = nodes.size();
// 	for (int i = 0; i < m; ++i) {
// 		dp[i][0] = i;
// 	}
// //	int x = (int)log(m) + 1;
// 	for (int i = 1; i <= 17; ++i) {
// 		for (int j = 0; j + (1<<i) <= m; ++j) {
// 			int v1 = dp[j][i-1];
// 			int v2 = dp[j+(1<<(i-1))][i-1];
// 			dp[j][i] = (lvs[v1] < lvs[v2] ? v1 : v2);
// 		}
// 	}
	dfs(1);
	for(int i=1;i<=17;++i)for(int j=1;j<=n;++j)f[i][j]=f[i-1][f[i-1][j]];
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		int x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		bool ok = false;
		int p = getlca(a, b);
		int dab = h[a] + h[b] - 2 * h[p];
		int dax = h[a] + h[x] - 2*h[getlca(a, x)];
		int day = h[a] + h[y] - 2*h[getlca(a, y)];
		int dbx = h[b] + h[x] - 2*h[getlca(b, x)];
		int dby = h[b] + h[y] - 2*h[getlca(b, y)];
		int dxy = h[x] + h[y] - 2*h[getlca(x, y)];
		// cout<<getlca(a,b)<<" "<<getlca(a,x)<<" "<<getlca(a,y)<<endl;
		// cout<<getlca(b,x)<<" "<<getlca(b,y)<<" "<<getlca(x,y)<<endl;
	//	cout<<"lca="<<getlca(a,b)<<" "<<lev[a]<<" "<<lev[b]<<endl;
		if (k >= dab && ((k-dab) % 2 == 0)) {
			ok = true;
		//	cout<<"???"<<endl;
		} else {
			int d2 = k-(dax+1+dby);
			if (d2 >= 0) {
			//	if (d2 % 2 == 0) ok=true;
				int r = dxy+1;
			//	cout<<"a="<<dax<<" "<<dby<<" "<<dxy<<endl;
				if ((d2 % r == 0) || (d2 % 2 == 0)) ok = true;
				else {
					int r2 = d2 % r;
				//	cout<<"b="<<r2<<" "<<d2/r<<endl;
					if (r2 % 2 == 0) ok = true;
					else if ((r%2) && (d2/r)>=1) ok = true;
				}
			}
		//	cout<<"d1="<<ok<<endl;
			d2 = k-(day+1+dbx);
			if (d2 >= 0) {
			//	if (d2 % 2 == 0) ok = true;
				int r = dxy+1;
				if ((d2 % r == 0) || (d2 % 2 == 0)) ok = true;
				else {
					int r2 = d2 % r;
					if (r2 % 2 == 0) ok = true;
					else if ((r%2) && (d2/r)>=1) ok = true;
				}
			}
		//	cout<<"d2="<<ok<<endl;
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
