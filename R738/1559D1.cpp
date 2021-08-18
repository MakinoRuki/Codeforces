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
int t, n, m1, m2, k;
int p1[N], p2[N];
int find(int* par, int u) {
	return u == par[u] ? u : par[u] = find(par, par[u]);
}
int main() {
	//cin>>t;
	//for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d", &n, &m1, &m2);
		for (int i =1 ; i <= n; ++i) {
			p1[i] = i;
			p2[i] = i;
		}
		int cnt1=0,cnt2=0;
		for (int i = 1; i <= m1; ++i) {
			int u,v;
			scanf("%d%d", &u, &v);
			int pu = find(p1, u);
			int pv = find(p1, v);
			if (pu != pv) {
				p1[pu] = pv;
			}
		}
		for (int i = 1; i <= m2; ++i) {
			int u,v;
			scanf("%d%d", &u, &v);
			int pu = find(p2, u);
			int pv = find(p2, v);
			if (pu != pv) {
				p2[pu] = pv;
			}
		}
		vector<pair<int,int>> ans;
		ans.clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = i+1; j <= n; ++j) {
				int p1u = find(p1, i);
				int p1v = find(p1, j);
				int p2u = find(p2, i);
				int p2v = find(p2, j);
				if (p1u != p1v && p2u != p2v) {
					ans.push_back(make_pair(i,j));
					p1[p1u] = p1v;
					p2[p2u] = p2v;
				}
			}
		}
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
//	}
  return 0;
}
