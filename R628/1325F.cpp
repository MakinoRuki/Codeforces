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
int n, m;
vector<int> edges[N];
int deg[N];
bool removed[N];
int incycle[N];
int main() {
	cin>>n>>m;
	int sq=1;
	while(sq*sq<n) sq++;
	for (int i = 1; i <= m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	set<pair<int, int>> ss;
	for (int i = 1; i <= n; ++i) {
		ss.insert(make_pair(deg[i], i));
	}
	vector<int> ans1;
	vector<int> ans2;
	memset(removed, false, sizeof(removed));
	while(ans1.size() < sq) {
		auto t = *ss.begin();
		if (t.first >= sq-1) {
			break;
		}
		int v = t.second;
		ans1.push_back(v);
		removed[v] = true;
		ss.erase(t);
		for (int i = 0; i < edges[v].size(); ++i) {
			int u = edges[v][i];
			if (removed[u]) continue;
			ss.erase(make_pair(deg[u], u));
			removed[u] = true;
			for (int j = 0; j < edges[u].size(); ++j) {
				int v2 = edges[u][j];
				if (removed[v2]) continue;
				ss.erase(make_pair(deg[v2], v2));
				deg[v2]--;
				ss.insert(make_pair(deg[v2], v2));
			}
		}
	}
	if (ans1.size() == sq) {
		cout<<1<<endl;
		for (int i = 0; i < ans1.size(); ++i) {
			cout<<ans1[i];
			if (i < ans1.size()-1) cout<<" ";
			else cout<<endl;
		}
	} else {
		auto t = *ss.begin();
		memset(incycle, 0, sizeof(incycle));
		int u = t.second;
		ans2.push_back(u);
		incycle[u] = ans2.size();
		while(true) {
			int minp = n+2;
			int v = -1;
			for (int i = 0; i < edges[u].size(); ++i) {
				if (removed[edges[u][i]]) continue;
				if (incycle[edges[u][i]] < minp) {
					minp = incycle[edges[u][i]];
					v = edges[u][i];
				}
			}
			if (!minp) {
				ans2.push_back(v);
				incycle[v] = ans2.size();
				u = v;
			} else {
				cout<<2<<endl;
				cout<<ans2.size()-minp+1<<endl;
				for (int i = minp-1; i < ans2.size(); ++i) {
					cout<<ans2[i];
					if (i < ans2.size()-1) cout<<" ";
					else cout<<endl;
				}
				break;
			}
		}
	}
	return 0;
}
