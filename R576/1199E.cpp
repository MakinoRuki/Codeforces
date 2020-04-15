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
#include <queue>
#define N 400005
using namespace std;
typedef long long ll;
int t, n, m;
bool vis[N];
int main() {
	cin>>t;
	for (int cas= 1; cas<= t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= 3*n; ++i) {
			vis[i] = false;
		}
		vector<int> ans;
		ans.clear();
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (!vis[u] && !vis[v]) {
				ans.push_back(i+1);
				vis[u] = vis[v] = true;
			}
		}
		if (ans.size() >= n) {
			puts("Matching");
			for (int i = 1; i <= n; ++i) {
				printf("%d", ans[i-1]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		} else {
			ans.clear();
			for (int i = 1; i <= 3*n; ++i) {
				if (!vis[i]) {
					ans.push_back(i);
				}
			}
			puts("IndSet");
			for (int i = 1; i <= n; ++i) {
				printf("%d", ans[i-1]);
				if (i < n) cout<<" ";
				else cout<<endl;
			}
		}
	}
	return 0;
}
