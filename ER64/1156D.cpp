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
int n;
vector<pair<int,int>> edges[N];
int cnt[N][2];
ll ans;
void dfs(int u, int p) {
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i].first;
		int c=edges[u][i].second;
		if (v==p) continue;
		dfs(v, u);
		if (c==1) {
			cnt[u][1] += cnt[v][1]+1;
		} else {
			cnt[u][0] += cnt[v][0]+1;
		}
	}
}
void dfs2(int u, int p, int tot0, int tot1) {
	ans += cnt[u][0] + cnt[u][1]+tot0+tot1;
	ans += (ll)cnt[u][0]*(ll)cnt[u][1] + (ll)cnt[u][0]*(ll)tot1 + (ll)cnt[u][1]*(ll)tot0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v=edges[u][i].first;
		int c=edges[u][i].second;
		if (v==p) continue;
		if (c==0) {
			dfs2(v, u, tot0+cnt[u][0]-cnt[v][0], 0);
		} else {
			dfs2(v, u, 0, tot1+cnt[u][1]-cnt[v][1]);
		}
	}
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int x,y,c;
		scanf("%d%d%d", &x, &y, &c);
		edges[x].push_back(make_pair(y,c));
		edges[y].push_back(make_pair(x,c));
	}
	memset(cnt, 0, sizeof(cnt));
	dfs(1, 0);
	ans=0LL;
	dfs2(1, 0, 0, 0);
	cout<<ans<<endl;
	return 0;
}
