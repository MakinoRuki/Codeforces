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
int t, n, m;
int k;
int q;
int a[N], b[N];
int col[N];
vector<int> edges[N];
bool dfs(int u, int c) {
	if (col[u] < 0) {
		col[u] = c;
	} else {
		return col[u] == c;
	}
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (!dfs(v, !c)) {
			return false;
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		ll s1=0LL, s2 = 0LL;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			s1 += (ll)a[i];
			edges[i].clear();
			col[i] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			s2 += (ll)b[i];
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		ll as1 = abs(s1);
		ll as2 = abs(s2);
		if ((as1 % 2) != (as2 % 2)) {
			puts("NO");
		} else {
			if (dfs(1, 0)) {
				s1 = 0, s2 = 0;
				for (int i = 1; i <= n; ++i) {
				//	cout<<i<<" "<<col[i]<<endl;
					if (col[i]) s1 += b[i]-a[i];
					else s2 += b[i]-a[i];
				}
				if (s1 == s2) {
					puts("YES");
				} else {
					puts("NO");
				}
			} else {
				puts("YES");
			}
		}
	}
  return 0;
}
