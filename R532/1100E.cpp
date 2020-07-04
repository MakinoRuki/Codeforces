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
#define N 100005
#define M 10
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<pair<pair<int,int>,int>> es;
int idx[N];
vector<int> edges[N];
int deg[N];
bool check(int x) {
	for (int i = 1; i <= n; ++i) {
		edges[i].clear();
	}
	memset(idx, 0, sizeof(idx));
	memset(deg, 0, sizeof(deg));
	for (int i = 0; i < m; ++i) {
		int u = es[i].first.first;
		int v = es[i].first.second;
		int c = es[i].second;
		if (c > x) {
			edges[u].push_back(v);
			deg[v]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (deg[i]==0) {
			q.push(i);
		}
	}
	int cnt=0;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		idx[cur] = ++cnt;
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v = edges[cur][i];
			deg[v]--;
			if (deg[v]==0) {
				q.push(v);
			}
		}
	}
	if (cnt != n) {
		return false;
	}
	return true;
}
vector<int> getans(int x) {
	check(x);
	vector<int> ans;
	ans.clear();
	for (int i = 0; i < m; ++i) {
		int u = es[i].first.first;
		int v = es[i].first.second;
		int c = es[i].second;
		if (c <= x) {
			if (idx[u] > idx[v]) {
				ans.push_back(i+1);
			}
		}
	}
	return ans;
}
int main() {
  cin>>n>>m;
  es.clear();
  for (int i = 1; i <= m; ++i) {
  	int u, v, c;
  	scanf("%d%d%d", &u,&v,&c);
  	es.push_back(make_pair(make_pair(u,v), c));
  }
  int l = 0, r = inf;
  while(l < r) {
  	int mid = (l+r)/2;
  	if (check(mid)) r = mid;
  	else l = mid+1;
  }
  vector<int> ans = getans(r);
  cout<<r<<" "<<ans.size()<<endl;
  for (int i = 0; i < ans.size(); ++i) {
  	printf("%d", ans[i]);
  	if (i < ans.size()-1) cout<<" ";
  	else cout<<endl;
  }
  return 0;
}
