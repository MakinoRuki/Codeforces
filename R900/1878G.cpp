#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define N 200005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int nxt[N][32];
int dep[N];
int par[N][23];
int ors[N][23];

//这里的cur数组一定要copy。
void dfs(int u, int p, int d, vector<int> cur) {
	dep[u] = d;
	par[u][0] = p;
	ors[u][0] = a[p];
	for (int i = 30; i >= 0; --i) {
		nxt[u][i] = cur[i];
		if ((1<<i) & a[u]) {
			cur[i] = u;
		}
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v= edges[u][i];
		if (v == p) continue;
		dfs(v, u, d+1, cur);
	}
}
int getlca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; --i) {
		if (par[x][i] && dep[par[x][i]] >= dep[y]) {
			//if (x == 2 && y ==1) cout<<"i="<<i<<" "<<par[x][i]<<endl;
			x = par[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; --i) {
		if (par[x][i] > 0 && par[y][i] > 0 && par[x][i] != par[y][i]) {
			x= par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
int calc(int x, int y) {
	int res=a[x];
	for (int i = 20; i >= 0; --i) {
		if (par[x][i]>0 && dep[par[x][i]] >= dep[y]) {
			res |= ors[x][i];
			x = par[x][i];
		}
	}
	return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i= 1; i <= n; ++i) {
    	scanf("%d", &a[i]);
    	edges[i].clear();
    	for (int j = 0; j <= 20; ++j) {
    		par[i][j] = 0;
    	}
    }
    for (int i = 1; i < n; ++i) {
    	int u,v;
    	scanf("%d%d", &u, &v);
    	edges[u].push_back(v);
    	edges[v].push_back(u);
    }
    vector<int> cur(31,0);
    dfs(1, 0, 0, cur);
    for (int i = 1; i <= 20; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (par[j][i-1] > 0 && par[par[j][i-1]][i-1] > 0) {
    			par[j][i] = par[par[j][i-1]][i-1];
    			ors[j][i] = ors[j][i-1] | ors[par[j][i-1]][i-1];
    		}
    	}
    }
    scanf("%d", &q);
    vector<int> anss;
    anss.clear();
   // getlca(2, 1);
    //cout<<"pp="<<getlca(2, 1)<<endl;
    while(q-->0) {
    	int x,y;
    	scanf("%d%d", &x, &y);
    	int ans=0;
    	int lca = getlca(x, y);
    	int r1 = calc(x, lca);
    	int r2 = calc(y, lca);
    	//if (x==2&&y==3) cout<<"r1="<<r1<<" "<<"r2="<<r2<<endl;
    	for (int i = 0; i <= 30; ++i) {
    		int u = nxt[x][i];
    		//if (i==0 && x==2&&y==3) {cout<<"u="<<u<<endl;cout<<getlca(u,x)<<endl;}

    		if (u > 0 && dep[u] >= dep[lca]) {
    			//if (x ==2 && y==3) cout<<"ux="<<u<<" "<<i<<endl;
    			int res=__builtin_popcount(calc(x, u)) + __builtin_popcount(calc(u, lca) | calc(y, lca));
    			ans = max(ans, res);
    		}
    		u = nxt[y][i];
    		if (u > 0 && dep[u] >= dep[lca]) {
    		//	if (x==2 && y == 3) cout<<"uy="<<u<<" "<<i<<endl;
    			int res=__builtin_popcount(calc(y, u)) + __builtin_popcount(calc(u, lca) | calc(x, lca));
    			ans = max(ans, res);
    		}
    	}
    	ans = max(ans, __builtin_popcount(a[x]) + __builtin_popcount(r1 | r2));
    	ans = max(ans, __builtin_popcount(a[y]) + __builtin_popcount(r1 | r2));
    	ans = max(ans, __builtin_popcount(r1) + __builtin_popcount(r2));
    	anss.push_back(ans);
    }
    for (int i = 0; i < anss.size(); ++i) {
    	printf("%d ", anss[i]);
    }
    cout<<endl;
  }
  return 0;
}
