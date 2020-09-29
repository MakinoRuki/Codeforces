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
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int s, k;
int a[N];
vector<int> edges[N];
int dis[102][N];
void bfs(int tp, vector<int>& st) {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		dis[tp][i]=1000000000;
	}
	for (int i = 0; i < st.size(); ++i) {
		int u=st[i];
		dis[tp][u]=0;
		q.push(u);
	}
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i = 0; i < edges[u].size(); ++i) {
			int v=edges[u][i];
			if (dis[tp][v]>dis[tp][u]+1) {
				dis[tp][v]=dis[tp][u]+1;
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>n>>m>>k>>s;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for (int i = 1; i <= k; ++i) {
		vector<int> st;
		st.clear();
		for (int j = 1; j <= n; ++j) {
			if (a[j]==i) {
				st.push_back(j);
			}
		}
		bfs(i, st);
	}
	for (int i = 1; i <= n; ++i) {
		vector<int> rk;
		rk.clear();
		for (int j = 1; j <= k; ++j) {
			rk.push_back(dis[j][i]);
		}
		sort(rk.begin(), rk.end());
		ll ans=0LL;
		for (int j = 0; j < s; ++j) {
			ans += rk[j];
		}
		printf("%lld", ans);
		if (i<n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
