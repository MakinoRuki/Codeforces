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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll s;
vector<pair<int,ll>> edges[N];
vector<pair<ll, int>> es;
int dfs(int u, int p) {
	int cnt=0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v==p) continue;
		int ss = dfs(v, u);
		es.push_back(make_pair(edges[u][i].second, ss));
		cnt += ss;
	}
	if (cnt==0) return 1;
	return cnt;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i =1 ; i < n; ++i) {
			int u, v;
			ll w;
			scanf("%d%d%lld",&u,&v,&w);
			edges[u].push_back(make_pair(v,w));
			edges[v].push_back(make_pair(u,w));
		}
		es.clear();
		dfs(1, 0);
		set<pair<ll,int>> ss;
		ss.clear();
		ll tot = 0LL;
		for (int i = 0; i < es.size(); ++i) {
			tot += es[i].first*(ll)es[i].second;
		}
		if (tot <= s) {
			cout<<0<<endl;
			continue;
		}
		for (int i = 0; i < es.size(); ++i) {
			ll det = es[i].first/2;
			det = (es[i].first-det)*(ll)es[i].second;
			ss.insert(make_pair(-det, i));
		}
		ll ans = 0LL;
		while(tot > s) {
			auto top = *ss.begin();
			ll det = -top.first;
			int id = top.second;
			tot -= det;
			es[id].first /= 2;
			ss.erase(top);
			det = es[id].first/2;
			det = (es[id].first-det)*(ll)es[id].second;
			if (det > 0) {
				ss.insert(make_pair(-det, id));
			}
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
