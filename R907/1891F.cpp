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
#define N 500005
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
ll bit[N];
int ts[N];
vector<pair<int,int>> qs[N];
vector<int> edges[N];
ll ans[N];
int lowbit(int x) {
	return x&(-x);
}
void update(int tt, ll v) {
	while(tt <= q) {
		bit[tt] += v;
		tt += lowbit(tt);
	}
}
ll query(int tt) {
	ll res=0LL;
	while(tt) {
		res += bit[tt];
		tt -= lowbit(tt);
	}
	return res;
}
void dfs(int u, int p) {
	for (int i = 0; i < qs[u].size(); ++i) {
		int tt = qs[u][i].first;
		ll v = qs[u][i].second;
		update(tt, v);
	}
	ans[u] = query(q) - query(ts[u]);
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
	for (int i = 0; i < qs[u].size(); ++i) {
		int tt = qs[u][i].first;
		ll v = qs[u][i].second;
		update(tt, -v);
	}
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &q);
    n=1;
    for (int i = 0; i <= q+1; ++i) {
    	bit[i] = 0;
    	qs[i].clear();
    	edges[i].clear();
    	ts[i] = 0;
    	ans[i] = 0LL;
    }
    ts[1] = 0;
    for (int i = 1; i <= q; ++i) {
    	int tp;
    	scanf("%d", &tp);
    	if (tp == 1) {
    		int v;
    		scanf("%d", &v);
    		edges[v].push_back(++n);
    		ts[n] = i;
    	} else {
    		int v,x;
    		scanf("%d%d", &v, &x);
    		qs[v].push_back(make_pair(i, x));
    	}
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
    	printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
