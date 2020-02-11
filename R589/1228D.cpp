#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
unordered_set<int> edges[N];
int col[N];
vector<int> gs[4];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin>>a>>b;
		edges[a].insert(b);
		edges[b].insert(a);
	}
	memset(col, 0, sizeof(col));
	for (int i =1; i <= 3; ++i) {
		int j;
		for (j = 1; j <= n; ++j) {
			if (!col[j]) break;
		}
		if (j > n) {
			cout<<"-1"<<endl;
			return 0;
		}
		col[j] = i;
		gs[i].push_back(j);
		for (int k =1; k <= n; ++k) {
			if (k != j && !col[k] && edges[j].find(k) == edges[j].end()) {
				col[k] = i;
				gs[i].push_back(k);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!col[i]) {
			cout<<"-1"<<endl;
			return 0;
		}
	}
	bool ok = true;
	for (int c1 = 1; c1 <= 3; ++c1) {
		for (int c2 = 1; c2 <= 3; ++c2) {
			if (c1 == c2) continue;
			for (auto v : gs[c1]) {
				for (auto v2 : gs[c2]) {
					if (edges[v].find(v2) == edges[v].end()) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
			}
			if (!ok) break;
		}
		if (!ok) break;
	}
	for (int i = 1; i <= n; ++i) {
		for (auto v : edges[i]) {
			if (col[i] == col[v]) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	if (!ok) {
		cout<<"-1"<<endl;
	} else {
		for (int i = 1; i <= n; ++i) {
			cout<<col[i];
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
