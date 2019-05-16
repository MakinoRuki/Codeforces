// 用一棵树来表示，par[i]=nxt[i]。然后自顶向下dfs时从大到小标号。
// 相当于按照右端点从大到小排序然后从大到小标号，右端点一样的先标区间长的。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500010
using namespace std;
int t, n;
int nxt[N];
vector<int> edges[N];
int cnt;
int ans[N];
void dfs(int cur) {
	ans[cur] = cnt;
	cnt--;
	for (int i = 0; i < edges[cur].size(); ++i) {
		dfs(edges[cur][i]);
	}
}
int main() {
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &nxt[i]);
			nxt[i]--;
			if (nxt[i] == -2) nxt[i] = i + 1;
			edges[nxt[i]].push_back(i);
		}
		cnt = n;
		dfs(n);
		vector<int> s;
		s.clear();
		bool ok = true;
		for (int i = n - 1; i >= 0; --i) {
			while(!s.empty() && ans[s.back()] < ans[i]) {
				s.pop_back();
			}
			if ((s.empty() && nxt[i] != n) || (!s.empty() && nxt[i] != s.back())) {
				ok = false;
				break;
			}
			s.push_back(i);
		}
		if (!ok) {
			cout<<-1<<endl;
		} else {
			for (int i = 0; i < n; ++i) {
				printf("%d", ans[i] + 1);
				if (i < n - 1) printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}
