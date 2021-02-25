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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<int> edges[N];
vector<int> cnt[N];
int idx[N];
int ans[N];
void dfs(int u, int p) {
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (p==v) continue;
		dfs(v, u);
		if (cnt[u].size() < cnt[v].size()) {
			swap(cnt[u], cnt[v]);
			idx[u] = idx[v];
		}
		int szu=(int)cnt[u].size();
		int szv=(int)cnt[v].size();
		for (int j = 0; j < cnt[v].size(); ++j) {
			cnt[u][szu-1-j] += cnt[v][szv-1-j];
			if (idx[u] < 0 || cnt[u][idx[u]] < cnt[u][szu-1-j] || (cnt[u][idx[u]]==cnt[u][szu-1-j] && idx[u]<szu-1-j)) {
				idx[u] = szu-1-j;
			}
		}
		cnt[v].clear();
	}
	cnt[u].push_back(1);
	if (idx[u] < 0 || cnt[u][idx[u]]<cnt[u].back() || (cnt[u][idx[u]]==cnt[u].back())) {
		idx[u] = cnt[u].size()-1;
	}
	ans[u] = cnt[u].size()-1-idx[u];
}
int main() {
	cin>>n;
	for (int i = 1; i < n; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	memset(idx, -1, sizeof(idx));
	for (int i = 1; i <= n; ++i) {
		cnt[i].clear();
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
  return 0;
}
