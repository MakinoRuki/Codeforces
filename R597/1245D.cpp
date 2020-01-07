#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define N 2005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int x[N], y[N];
int c[N], k[N];
int par[N];
bool lit[N];
int find(int u) {
	return u == par[u] ? u : par[u] = find(par[u]);
}
ll getdis(int u, int v) {
	return abs(x[u]-x[v]) + abs(y[u]-y[v]);
}
int main() {
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>x[i]>>y[i];
	}
	for (int i = 0; i < n; ++i) {
		cin>>c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin>>k[i];
	}
	memset(lit, false, sizeof(lit));
	for (int i = 0; i < n; ++i) {
		par[i] = i;
	}
	vector<pair<ll, pair<int, int>>> rk;
	rk.clear();
	for (int i = 0; i < n; ++i) {
		rk.push_back(make_pair((ll)c[i], make_pair(i, -1)));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			rk.push_back(make_pair(getdis(i, j)*(ll)(k[i]+k[j]), make_pair(i, j)));
		}
	}
	sort(rk.begin(), rk.end());
	ll tot=0;
	vector<int> ps;
	ps.clear();
	vector<pair<int,int>> es;
	es.clear();
	for (int i = 0; i < rk.size(); ++i) {
		ll w = rk[i].first;
		int u = rk[i].second.first;
		int v = rk[i].second.second;
		if (v < 0) {
			int pu = find(u);
			if (!lit[pu]) {
				tot += w;
				lit[pu] = true;
				ps.push_back(u+1);
			}
		} else {
			int pu = find(u);
			int pv = find(v);
			if (pu == pv) continue;
			if (lit[pu] && lit[pv]) continue;
			tot += w;
			par[pu] = pv;
			es.push_back(make_pair(u+1, v+1));
			if (lit[pu] || lit[pv]) {
				lit[pu] = lit[pv] = true;
			}
		}
	}
	cout<<tot<<endl;
	cout<<ps.size()<<endl;
	for (int i = 0; i < ps.size(); ++i) {
		cout<<ps[i];
		if (i < ps.size()-1) cout<<" ";
		else cout<<endl;
	}
	cout<<es.size()<<endl;
	for (int i = 0; i < es.size(); ++i) {
		cout<<es[i].first<<" "<<es[i].second<<endl;
	}
	return 0;
}
