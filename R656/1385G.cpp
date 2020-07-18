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
int n;
int a[2][N];
int par[N];
vector<int> cols[N];
vector<int> edges[N];
int col[N];
int cnt[N];
bool rev[N];
bool dfs(int u, int c, vector<int>& v0, vector<int>& v1) {
	if (col[u] >= 0) {
		if (col[u] != c) return false;
		return true;
	}
	col[u] = c;
	if (c==0) { v0.push_back(u); }
	else { v1.push_back(u); }
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (!dfs(v, !c, v0, v1)) return false;
	}
	return true;
}
int find(int u) {
	return u==par[u] ? u : par[u] = find(par[u]);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		for (int i = 1; i <= n; ++i) {
			cols[i].clear();
			edges[i].clear();
		}
	//	cout<<"ok"<<endl;
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				cols[a[i][j]].push_back(j);
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			if (cols[i].size() != 2) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout<<-1<<endl;
			continue;
		}
		// cout<<"ok"<<endl;
		// for (int i = 1; i <= n; ++i) {
		// 	cout<<i<<" "<<edges[i].size()<<endl;
		// }
		for (int i = 1; i <= n; ++i) {
			par[i] = i;
			cnt[i] = 1;
			col[i] = -1;
			rev[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			int c1 = cols[i][0];
			int c2 = cols[i][1];
			if ((a[0][c1]==i&&a[1][c2]==i) || (a[1][c1]==i&&a[0][c2]==i)) {
				int p1 = find(c1);
				int p2 = find(c2);
				if (p1 != p2) {
					par[p1] = p2;
					cnt[p2] += cnt[p1];
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			int c1 = cols[i][0];
			int c2 = cols[i][1];
			if (c1==c2) continue;
			if ((a[0][c1]==i&&a[0][c2]==i) || (a[1][c1]==i&&a[1][c2]==i)) {
				int p1 = find(c1);
				int p2 = find(c2);
				if (p1 == p2) {
					ok = false;
					break;
				}
				edges[p1].push_back(p2);
				edges[p2].push_back(p1);
			}
		}
		if (!ok) {
			cout<<-1<<endl;
			continue;
		}
		// cout<<"ok"<<endl;
		// for (int i = 1; i <= n; ++i) {
		// 	cout<<i<<" "<<edges[i].size()<<endl;
		// }
		for (int i = 1; i <= n; ++i) {
			par[i] = find(i);
			if (par[i] == i && col[i] < 0) {
				vector<int> v0, v1;
				v0.clear();
				v1.clear();
			//	cout<<"sz1="<<v1.size()<<endl;
				if (!dfs(i, 0, v0, v1)) {
					ok = false;
					break;
				}
			//	cout<<"sz2="<<v1.size()<<endl;
				int n0=0,n1=0;
				for (int j = 0; j < v0.size(); ++j) {
					n0 += cnt[v0[j]];
				}
				for (int j = 0; j <v1.size(); ++j) {
					n1 += cnt[v1[j]];
				}
				if (n0 < n1) {
					for (int j = 0; j < v0.size(); ++j) {
						rev[v0[j]] = true;
					}
				} else {
					for (int j = 0; j < v1.size(); ++j) {
				//		cout<<"v1="<<v1[j]<<endl;
						rev[v1[j]] = true;
					}
				}
			}
		}
		if (!ok) {
			cout<<-1<<endl;
		} else {
			vector<int> ans;
			// for (int i = 1; i <= n; ++i) {
			// 	cout<<"rev="<<i<<" "<<rev[i]<<endl;
			// }
			for (int i = 1; i <= n; ++i) {
				par[i] = find(i);
				if (rev[par[i]]) {
					ans.push_back(i);
				}
			}
			cout<<ans.size()<<endl;
			for (int i = 0; i < ans.size(); ++i) {
				printf("%d", ans[i]);
				if (i < ans.size()-1) cout<<" ";
				else cout<<endl;
			}
		}
	}
  return 0;
}
