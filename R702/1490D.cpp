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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int d[N];
void dfs(int l, int r, int dep) {
	if (l >r )return;
	if (l == r) {
		d[l] = dep;
		return;
	}
	int id = l;
	for (int i = l+1; i <= r; ++i) {
		if (a[i] > a[id]) {
			id = i;
		}
	}
	d[id] = dep;
	dfs(l, id-1, dep+1);
	dfs(id+1, r, dep+1);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		memset(d, 0, sizeof(d));
		dfs(1, n, 0);
		for (int i = 1; i <= n; ++i) {
			printf("%d", d[i]);
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
  return 0;
}

