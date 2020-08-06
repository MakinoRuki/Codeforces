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
#define N 400005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
ll s;
vector<pair<int,pair<ll,int>>> edges[N];
vector<pair<ll, int>> es[2];
ll res[2][N*10];
int mc1, mc2;
int dfs(int u, int p) {
	int cnt=0;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i].first;
		if (v==p) continue;
		int ss = dfs(v, u);
		if (edges[u][i].second.second == 1) {
			es[0].push_back(make_pair(edges[u][i].second.first, ss));
		} else {
			es[1].push_back(make_pair(edges[u][i].second.first, ss));
		}
		cnt += ss;
	}
	if (cnt==0) return 1;
	return cnt;
}
void calc(int id, int& mc) {
	set<pair<ll,int>> ss;
	ss.clear();
	ll tot = 0LL;
	// for (int i = 0; i < es[id].size(); ++i) {
	// 	tot += es[id][i].first*(ll)es[i].second;
	// }
	for (int i = 0; i < es[id].size(); ++i) {
		ll det = es[id][i].first/2;
		det = (es[id][i].first-det)*(ll)es[id][i].second;
		ss.insert(make_pair(-det, i));
	}
	while(!ss.empty()) {
		auto top = *ss.begin();
		ll det = -top.first;
		int id2 = top.second;
		tot += det;
		es[id][id2].first /= 2;
		ss.erase(top);
		det = es[id][id2].first/2;
		det = (es[id][id2].first-det)*(ll)es[id][id2].second;
		if (det > 0) {
			ss.insert(make_pair(-det, id2));
		}
		mc++;
		res[id][mc] = tot;
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		ll tot=0LL;
		for (int i =1 ; i < n; ++i) {
			int u, v;
			ll w;
			int c;
			scanf("%d%d%lld%d",&u,&v,&w,&c);
			edges[u].push_back(make_pair(v,make_pair(w,c)));
			edges[v].push_back(make_pair(u,make_pair(w,c)));
		}
		es[0].clear();
		es[1].clear();
		dfs(1, 0);
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < es[i].size(); ++j) {
				tot += es[i][j].first * (ll)es[i][j].second;
			}
		}
		mc1=0,mc2=0;
		calc(0, mc1);
		calc(1, mc2);
		ll ans = 1LL<<61;
		for (int i = 0; i <= mc1; ++i) {
			int l = 0, r = mc2;
			while(l<r) {
				int mid=(l+r)/2;
				if (tot-(res[0][i]+res[1][mid])<=s) {
					r = mid;
				} else {
					l = mid+1;
				}
			}
			if (tot-(res[0][i]+res[1][r])<=s) {
				ans = min(ans, (ll)i+(ll)r*2LL);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
