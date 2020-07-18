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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n,m;
vector<int> edges[N];
vector<pair<int, pair<int,int>>> es;
int ids[N];
int deg[N];
void bfs() {
	int cnt=0;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (deg[i]==0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		ids[cur] = ++cnt;
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v = edges[cur][i];
			deg[v]--;
			if (deg[v]==0) {
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
			deg[i]=0;
			ids[i]=-1;
		}
		es.clear();
		for (int i = 1; i <= m; ++i) {
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if (t==0) {
				es.push_back(make_pair(i,make_pair(x,y)));
			} else {
				edges[x].push_back(y);
				deg[y]++;
			}
		}
		bfs();
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (ids[i] < 0) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout<<"NO"<<endl;
			continue;
		}
		for (int i = 0; i < es.size(); ++i) {
			int id = es[i].first;
			int u = es[i].second.first;
			int v = es[i].second.second;
			if (ids[u] < ids[v]) {
				edges[u].push_back(v);
			} else {
				edges[v].push_back(u);
			}
		}
		cout<<"YES"<<endl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < edges[i].size(); ++j) {
				printf("%d %d\n", i, edges[i][j]);
			}
		}
	}
  return 0;
}
