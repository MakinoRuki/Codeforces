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
int t;
int n,a,b,da,db;
vector<int> edges[N];
int dis[N];
void dfs(int u, int p, int d) {
	dis[u] = d;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i];
		if (v==p) continue;
		dfs(v, u, d+1);
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<= t; ++cas) {
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		dfs(b, 0, 0);
		if (dis[a] <= da) {
			cout<<"Alice"<<endl;
		} else {
			if (db < 2*da+1) {
				cout<<"Alice"<<endl;
				continue;
			}
			bool found=false;
			for (int i = 1; i <= n; ++i) {
				if (i == b) {
					continue;
				}
				if (dis[i] >= 2*da+1) {
					found=true;
					break;
				}
			}

			if (found) {
				cout<<"Bob"<<endl;
			} else {
				int maxd=0;
				int id=b;
				for (int i = 1; i <= n; ++i) {
					if (dis[i]>maxd) {
						maxd=dis[i];
						id=i;
					}
				}
				dfs(id, 0, 0);
				maxd=0;
				for (int i = 1; i <= n; ++i) {
					maxd=max(maxd, dis[i]);
				}
				if (maxd>=2*da+1) {
					cout<<"Bob"<<endl;
				} else {
					cout<<"Alice"<<endl;
				}
			}
		}
	}
	return 0;
}
