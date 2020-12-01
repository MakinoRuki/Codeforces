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
int t, n;
vector<pair<int,int>> edges[N];
vector<pair<int,int>> ev;
int par[N];
int pre[N];
bool vis[N];
void dfs(int u, int p, int id) {
	pre[u] = p;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i].first;
		int id2=edges[u][i].second;
		if (id2==id || v==p) continue;
		dfs(v, u, id);
	}
}
void dfs2(int u, int p, ll& cnt2) {
	if (!vis[u]) cnt2++;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i].first;
		if (v==p || vis[v]) continue;
		dfs2(v, u, cnt2);
	}
}
int find(int u) {
	return u==par[u]?u:par[u]=find(par[u]);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			par[i]=i;
			pre[i]=-1;
			vis[i]=false;
		}
		ev.clear();
		for (int i = 0; i < n; ++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			ev.push_back(make_pair(u,v));
			edges[u].push_back(make_pair(v, i));
			edges[v].push_back(make_pair(u, i));
		}
		for (int i = 0; i < ev.size(); ++i) {
			int u = ev[i].first;
			int v = ev[i].second;
			int pu=find(u);
			int pv=find(v);
			if (pu != pv) {
				par[pu]=pv;
			} else {
				dfs(u, 0, i);
				ll cnt=0;
				int cur=v;
				while(cur != u) {
					cnt++;
					vis[cur]=true;
					cur=pre[cur];
				}
				vis[cur]=true;
				cnt++;
				vector<ll> cnts;
				cnts.clear();
				for (int j = 1; j <= n; ++j) {
					if (vis[j]) {
						ll cnt2=0;
						dfs2(j, 0, cnt2);
						if (cnt2>0) {
							cnts.push_back(cnt2);
						}
					}
				}
			//	cout<<cnt<<" "<<cnt2<<" "<<cnt3<<endl;
				ll ans=cnt*(cnt-1);
				ll tot=0LL;
				for (int j = 0; j < cnts.size(); ++j) {
					ll cnt2=cnts[j];
					ans += cnt2*(cnt2+1)/2+cnt2*(cnt-1)*2;
					ll cnt3=n-cnt-cnt2;
					tot += cnt2*cnt3*2;
				}
				ans += tot/2;
				// if (cnt2>0) {
				// 	ans += cnt2*(cnt2+1)/2+2*(n-cnt2-1)*cnt2;
				// }
				// if (cnt3>0) {
				// 	ans += cnt3*(cnt3+1)/2+cnt3*(cnt-1)*2;
				// }
				// ans += cnt*(cnt-1);
				printf("%lld\n", ans);
				break;
			}
		}
	}
	return 0;
}
