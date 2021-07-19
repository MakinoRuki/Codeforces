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
#define M 205
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
set<int> edges[N];
int deg[N];
int cnt[N];
bool vis[N];
int main() {
	cin>>n>>k;
	memset(deg, 0, sizeof(deg));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; ++i) {
		edges[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	int ans = 0;
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int sz = (int)q.size();
		if (sz == 1) {
			if (ans == k) {
				puts("Yes");
			} else {
				puts("No");
			}
			return 0;
		}
		if (sz == 2) {
			puts("No");
			return 0;
		}
		set<int> tmp;
		tmp.clear();
		for (int i = 0; i < sz; ++i) {
			int u = q.front();
		//	cout<<"u="<<u<<",";
			q.pop();
			vis[u] = true;
			for (auto v : edges[u]) {
				if (vis[v]) continue;
				deg[v]--;
				cnt[v]++;
				tmp.insert(v);
				if (deg[v] == 1) {
					q.push(v);
				}
			} 
		}
		for (auto v : tmp) {
			if (cnt[v] < 3) {
				puts("No");
				return 0;
			}
		}
		ans++;
	//	cout<<endl;
	//	cout<<ans<<endl;
	}
	if (ans == k) {
		puts("Yes");
	} else {
		puts("No");
	}
  return 0;
}
