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
vector<int> edges[N];
bool odd[N];
void dfs(int u, int p, int d) {
	if (d%2) odd[u] = true;
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v == p) continue;
		dfs(v, u, d+1);
	}
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	map<int, vector<int>> mp;
	for (int i = 1; i <= n; ++i) {
		if (edges[i].size() == 1) {
			mp[edges[i][0]].push_back(i);
		}
	}
	int tot=0;
	for (auto itr : mp) {
		if (itr.second.size() > 1) {
			tot += itr.second.size()-1;
		}
	}
	int ans=n-1;
	int root=-1;
	for (int i = 1; i <= n; ++i) {
		if (edges[i].size()>1) {
			root = i;
			break;
		}
	}
	memset(odd, false, sizeof(odd));
	dfs(root,0, 0);
	bool ok = true;
	int n1=0;
	int n2 = 0;
	for (int i = 1; i <= n; ++i) {
		if (edges[i].size()==1) {
			n1++;
			if (odd[i]) n2++;
		}
	}
	if (n2 > 0 && n2 < n1) {
		cout<<3<<" "<<ans-tot<<endl;
	} else {
		cout<<1<<" "<<ans-tot<<endl;
	}
	return 0;
}
