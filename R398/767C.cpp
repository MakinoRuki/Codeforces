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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
int q;
ll sum[N];
vector<int> edges[N];
ll tr[N];
int ind[N], otd[N];
bool mark[N];
ll tot;
vector<int> dfs(int u, int p) {
	sum[u] = tr[u];
	vector<int> ids;
	ids.clear();
	for (int i = 0; i < edges[u].size(); ++i) {
		if (ids.size() >= 2) return ids;
		int v = edges[u][i];
		if (v == p) continue;
		auto tv = dfs(v, u);
		sum[u] += sum[v];
		if (tv.size() >= 2) {
			return tv;
		}
		if (tv.size() == 1) {
			if (sum[v] - sum[tv[0]] == tot) {
				tv.push_back(v);
				return tv;
			} else {
				ids.push_back(tv[0]);
			}
		} else {
			if (sum[v] == tot) {
				ids.push_back(v);
			}
		}
	}
	return ids;
}
int main() {
	cin>>n;
	int rt = 0;
	tot = 0LL;
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d%lld", &v, &tr[i]);
		if (v > 0) {
			edges[v].push_back(i);
		} else {
			rt = i;
		}
		tot += tr[i];
	}
	if (tot % 3 != 0) {
		puts("-1");
		return 0;
	}
	tot /= 3;
	auto res = dfs(rt, 0);
	if (res.size() < 2) {
		puts("-1");
	} else {
		printf("%d %d\n", res[0], res[1]);
	}
  return 0;
}
