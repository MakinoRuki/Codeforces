// 防止TLE：预处理；不要用hashmap，直接用数组。

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
int n;
int a[N];
vector<int> ps[N*10];
vector<pair<int, int>> edges[N*10];
int fp[N*10];
int dis[N*10];
int bfs(int u) {
//	cout<<"u="<<u<<endl;
	queue<pair<int, int>> q;
	dis[u] = 0;
//	if (u == 1) cout<<"u==1!!!"<<endl;
	for (auto v : edges[u]) {
		//if (u == 1) cout<<"v="<<v.first<<endl;
		q.push(v);
		if (v.first == u) return 1;
		dis[v.first] = 1;
	}
	int res = -1;
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		int v = cur.first;
		int p = cur.second;
		for (auto v2 : edges[v]) {
			if (v2.second == p) continue;
			if (dis[v2.first] < 0 && v2.first != u) {
				dis[v2.first] = dis[v]+1;
				q.push(v2);
			} else {
				res = (res < 0 ? dis[v2.first]+dis[v]+1 : min(res, dis[v2.first]+dis[v]+1));
			}
		}
	}
	return res;
}
int main() {
	vector<int> prs;
	prs.clear();
	prs.push_back(1);
	for (int i = 2; i <= 1000000; ++i) {
		if (!fp[i]) {
			prs.push_back(i);
			for (int j = i; j <= 1000000; j+= i) {
				fp[j] = i;
			}
		}
		//cout<<i<<" "<<fp[i]<<endl;
		ps[i] = ps[i/fp[i]];
		auto itr = find(ps[i].begin(), ps[i].end(), fp[i]);
		if (itr == ps[i].end()) {
			ps[i].push_back(fp[i]);
		} else {
			ps[i].erase(itr);
		}
	}
	scanf("%d",&n);
	// map<int, int> rk;
	// rk.clear();
	int maxv = 0;
	for (int i = 1 ; i <= n; ++i) {
		scanf("%d", &a[i]);
		maxv = max(maxv, a[i]);
	}
//	edges.clear();
	for (int i = 1; i <= n; ++i) {
		if (ps[a[i]].size() < 2) {
			ps[a[i]].push_back(1);
		}
		if (ps[a[i]].size() < 2) {
			ps[a[i]].push_back(1);
		}
		int p1 = ps[a[i]][0];
		int p2 = ps[a[i]][1];
	//	cout<<i<<" "<<p1<<" "<<p2<<endl;
		edges[p1].push_back(make_pair(p2, i));
		edges[p2].push_back(make_pair(p1, i));
	}
	// cout<<"sz="<<edges.size()<<endl;
	// for (auto itr : edges) {
	// 	cout<<"itr="<<itr.first<<endl;
	// }
	int ans = -1;
	for (int v : prs) {
		//cout<<"v=="<<v<<endl;
		if (v*v > maxv) {
			break;
		}
		for (int v2 : prs) {
			dis[v2] = -1;
		}
		int res = bfs(v);
		if (res >= 0) {
			ans = (ans < 0 ? res : min(ans, res));
		}
	}
	printf("%d\n", ans);
	return 0;
}
