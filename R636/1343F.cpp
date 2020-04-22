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
#define N 202
using namespace std;
typedef long long ll;
int t, n;
int cnt[N];
vector<int> gs[N];
vector<int> ans;
vector<vector<int>> sgs;
bool solve(int x, int y) {
//	if (x==3 && y == 1) cout<<"ok"<<endl;
	ans.clear();
	ans.push_back(x);
	ans.push_back(y);
	bool vis[N];
	for (int i = 1; i <= n; ++i) {
		vis[i] = false;
	}
	int cnt2[N];
	for (int i = 1; i <= n; ++i) {
		cnt2[i] = cnt[i];
	}
	vis[x] = true;
	vis[y] = true;
	for (int i = 0; i < gs[x].size(); ++i) {
	//	if (x==3 && y==1) cout<<"*"<<x<<" "<<gs[x][i]<<endl;
		cnt2[gs[x][i]]--;
	}
	for (int i = 0; i < gs[y].size(); ++i) {
	//	if (x==3 && y == 1)cout<<"x"<<x<<" "<<gs[y][i]<<endl;
		cnt2[gs[y][i]]--;
	}
	int id = -1;
	for (int i = 1; i < n; ++i) {
		if (cnt2[i] == 1) {
			if (id<0) id = i;
			else return false;
		}
	}
//	if (x==3 && y == 1) cout<<"id="<<id<<endl;
	for (int i = 3; i <= n; ++i) {
		if (id < 0) return false;
		vector<int> r1;
		vector<int> r2;
		for (int j = 1; j < sgs[id-1].size(); ++j) {
			r2.push_back(ans[i-1-j]);
		}
		sort(r2.begin(), r2.end());
		int x;
		for (int j = 0; j < sgs[id-1].size(); ++j) {
			if (!vis[sgs[id-1][j]]) {
				x = sgs[id-1][j];
			} else {
				r1.push_back(sgs[id-1][j]);
			}
		}
		sort(r1.begin(), r1.end());
		for (int j = 0; j < r1.size(); ++j) if (r1[j] != r2[j]) return false;
	//	if (x == 3 && y == 1) cout<<"i="<<i<<" "<<x<<endl;
		ans.push_back(x);
		vis[x] = true;
		id = -1;
		for (int j = 0; j < gs[x].size(); ++j) {
			cnt2[gs[x][j]]--;
			if (cnt2[gs[x][j]]==1) {
				if (id < 0) id = gs[x][j];
				else return false;
			}
		}
	}
	return true;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		vector<vector<int>> st;
		st.clear();
		sgs.clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i<= n; ++i) {
			gs[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int k;
			scanf("%d", &k);
			cnt[i] = k;
			vector<int> tmp;
			for (int j = 1; j <= k; ++j) {
				int x;
				scanf("%d", &x);
				tmp.push_back(x);
				gs[x].push_back(i);
			}
			sgs.push_back(tmp);
			if (k==2) st.push_back(tmp);
		}
		for (int i = 0; i < st.size(); ++i) {
			if (solve(st[i][0], st[i][1])) {
				break;
			}
			if (solve(st[i][1], st[i][0])) {
				break;
			}
		}
		for (int j = 0; j < ans.size(); ++j) {
			printf("%d", ans[j]);
			if (j < ans.size()-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
