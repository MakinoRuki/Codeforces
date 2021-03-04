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
#define eps 1e-7
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int a[600][600];
int p[N], c[N];
int p2[N];
int find(int x) {
	while(p[x] >= 1) {
		x=p[x];
	}
	return x;
}
int main() {
	cin>>n;
	m = n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; ++i) {
		p2[i] = i;
	}
	vector<pair<int, pair<int,int>>> rk;
	rk.clear();
	for (int i = 1; i <= n; ++i) {
		c[i] = a[i][i];
		for (int j = i+1; j <= n; ++j) {
			rk.push_back(make_pair(a[i][j], make_pair(i, j)));
		}
	}
	sort(rk.begin(), rk.end());
	for (int i = 0; i < rk.size(); ++i) {
		int s = rk[i].first;
		int u = rk[i].second.first;
		int v = rk[i].second.second;
		int pu = find(u);
		int pv = find(v);
		if (pu != pv) {
			if (pu >= 1 && c[pu] == s) {
				p[pv] = pu;
			} else if (pv >= 1 && c[pv] == s) {
				p[pu] = pv;
			} else {
				c[++m] = s;
				p[pu] = m;
				p[pv] = m;
			}
		}
		// int u1 = rk[i].second.first;
		// int v1 = rk[i].second.second;
		// int u = u1;
		// int v= v1;
		// while(p[u] >= 1) {
		// 	u = p[u];
		// }
		// while(p[v] >= 1) {
		// 	v=p[v];
		// }
		// if (p[u]<0 && p[v]<0) {
		// 	c[++m] = s;
		// 	p[u] = m;
		// 	p[v]=m;
		// 	p2[u1] = p[u];
		// 	p2[v1] = p[v];
		// } else if (p[u] < 0 && p[v]>0) {
		// 	if (c[p[v]] == s) {
		// 		p[u] = p[v];
		// 		p2[u1] = p[u];
		// 	} else {
		// 		c[++m] = s;
		// 		p[u] = m;
		// 		p[v] = m;
		// 		p2[u1] = p[u];
		// 		p2[v1] = p[v];
		// 	}
		// } else if (p[u] > 0 && p[v] < 0) {
		// 	if (c[p[u]] == s) {
		// 		p[v] = p[u];
		// 		p2[v1] = p[v];
		// 	} else {
		// 		c[++m] = s;
		// 		p[u] = m;
		// 		p[v] = m;
		// 		p2[u1] = p[u];
		// 		p2[v1] = p[v];
		// 	}
		// } else {
		// 	if (p[u]==p[v]) continue;
		// 	if (c[p[u]] == s) {
		// 		p[v]=p[u];
		// 		p2[v1] = p[v];
		// 	} else if (c[p[v]] == s) {
		// 		p[u] = p[v];
		// 		p2[u1] = p[u];
		// 	} else {
		// 		c[++m] = s;
		// 		p[u] = m;
		// 		p[v]=m;
		// 		p2[u1] = p[u];
		// 		p2[v1] = p[v];
		// 	}
		// }
	//	cout<<"x="<<u<<" "<<v<<" "<<p[u]<<" "<<p[v]<<endl;
		//cout<<u<<" "<<
		
	}
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i) {
		printf("%d", c[i]);
		if (i < m) cout<<" ";
		else cout<<endl;
	}
	// int r=1;
	// for (int i = 1; i <= m; ++i) {
	// 	if (p[i] < 0) {
	// 		r=i;
	// 		break;
	// 	}
	// }
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i) {
		if (i != m && p[i] >= 1) {
			printf("%d %d\n", i, p[i]);
		}
	}
  return 0;
}
