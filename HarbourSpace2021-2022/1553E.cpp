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
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int p[N];
int cnt[N];
int id[N];
bool vis[N];
bool check(int k) {
	for (int i = 1; i <= k; ++i) {
		id[n-k+i] = i;
	}
	for (int i = 1; i <= n-k; ++i) {
		id[i] = k+i;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		vis[i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = true;
		res++;
		int j = id[p[i]];
		while(j != i) {
			vis[j] = true;
			j = id[p[j]];
		}
	}
	return n - res <= m;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d",&n,&m);
		for (int i = 0; i <= n; ++i) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
			cnt[(i-p[i]+n)%n]++;
		}
		vector<int> ans;
		ans.clear();
		for (int k = 0; k < n; ++k) {
			if (cnt[k] >= n-2*m && check(k)) {
				ans.push_back(k);
			}
		}
		printf("%d", (int)ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf(" %d", ans[i]);
		}
		cout<<endl;
	}
  return 0;
}
