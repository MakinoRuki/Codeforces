#pragma GCC optimize(2)
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
#include <cmath>
#include <queue>
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
set<int> edges[N];
void update(set<int>& ss, int u) {
	bool f1 = (edges[u].upper_bound(u) == edges[u].end());
	bool f2 = (ss.find(u) != ss.end());
	if (f1 && f2) {
		ss.erase(u);
	} else if (!f1 && !f2) {
		ss.insert(u);
	}
}
int main() {
	cin>>n>>m;
	set<int> ss;
	ss.clear();
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].insert(v);
		edges[v].insert(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (edges[i].upper_bound(i) != edges[i].end()) {
			ss.insert(i);
		}
	}
	int q;
	cin>>q;
	while(q-->0) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1 || tp == 2) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (tp == 1) {
				edges[u].insert(v);
				edges[v].insert(u);
			} else {
				edges[u].erase(v);
				edges[v].erase(u);
			}
			update(ss, u);
			update(ss, v);
 		} else {
 			printf("%d\n", n-(int)ss.size());
 		}
	}
  return 0;
}
