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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
vector<int> edges[N];
int st[N], rg[N];
vector<pair<int,int>> ps[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		edges[i].clear();
		ps[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	memset(st, -1, sizeof(st));
	memset(rg, -1, sizeof(rg));
	int cur = 1;
	for (int i = 1; i <= n; ++i) {
		if (edges[i].size() > 0) {
			st[i] = cur;
			rg[i] = edges[i].size();
			cur += rg[i];
			for (int j = st[i]; j < st[i]+rg[i]; ++j) {
				ps[i].push_back(make_pair(j, j));
				if (j > st[i]) {
					ps[i].push_back(make_pair(st[i], j));
				}
			}
		} else {
			ps[i].push_back(make_pair(cur, cur));
			cur++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int cc = st[i];
		for (int j = 0; j < edges[i].size(); ++j) {
			int u = edges[i][j];
			if (u > i) {
				ps[i].push_back(make_pair(st[u], cc));
				st[u]++;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", (int)ps[i].size());
		for (int j = 0; j < ps[i].size(); ++j) {
			printf("%d %d\n", ps[i][j].first, ps[i][j].second);
		}
	}
  return 0;
}
