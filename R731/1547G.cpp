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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 400005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<int> edges[N];
int ans[N];
int cnt[N];
bool vis[N];
int dfn[N],low[N],idx[N];
bool sf[N];
vector<int> st;
int sum,col;
void tarjan(int u) {
  dfn[u]=low[u]=++sum;
  vis[u]=true;
  st.push_back(u);
  for(int i=0;i<edges[u].size();i++) {
    int v=edges[u][i];
    if(!dfn[v]) {
      tarjan(v);
      low[u]=min(low[u],low[v]);
    } else if(vis[v]) {
    	low[u]=min(low[u],low[v]);
  	}
  }
  if(low[u]==dfn[u]) {
    idx[u]=++col;
    vis[u]=false;
    while(st.back()!=u) {
      idx[st.back()]=col;
      vis[st.back()]=false;
      st.pop_back();
    }
    st.pop_back();
  }
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			ans[i] = 0;
			cnt[i] = 0;
			vis[i] = false;
			sf[i] = false;
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			if (u == v) sf[u] = true;
		}
		queue<int> q;
		q.push(1);
		cnt[1]++;
		ans[1] = 1;
		while(!q.empty()) {
			int cur=q.front();
			q.pop();
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v = edges[cur][i];
				ans[v] = 1;
				cnt[v]++;
				if (cnt[v] == 1) {
					q.push(v);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > 1) {
				q.push(i);
				vis[i] = true;
				ans[i] = 2;
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
					if (ans[v] == 1) ans[v] = 2;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			vis[i] = false;
			dfn[i] = 0;
			low[i] = 0;
			idx[i] = 0;
			cnt[i] = 0;
		}
		st.clear();
		sum = 0, col = 0;
		for(int i=1;i<=n;i++) {
		  if(!dfn[i]) {
		  	tarjan(i);
		  }
		}
	//	cout<<"col="<<col<<endl;
		for (int i = 1; i <= n; ++i) {
		//	cout<<i<<" "<<idx[i]<<endl;
			cnt[idx[i]]++;
		}
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= col; ++i) {
			if (cnt[i] > 1) {
				ss.insert(i);
			}
		}
		for (int i = 1; i <= n; ++i) {
			vis[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			if (ans[i] == 0) continue;
			if (ss.find(idx[i]) != ss.end()) {
				q.push(i);
				vis[i] = true;
				if (ans[i] == 2) ans[i] = -1;
			} else if (sf[i] && !vis[i]) {
				q.push(i);
				vis[i] = true;
				if (ans[i] == 2) ans[i] = -1;
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
					if (ans[v] == 2) ans[v] = -1;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", ans[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}
