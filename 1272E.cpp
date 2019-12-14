#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200020
#define inf 1000000000
using namespace std;
int n;
int a[N];
vector<int> edges[N];
int dis[N];
void bfs(vector<int>& ss) {
	queue<int> q;
	for (int i =1; i <= n; ++i) {
		dis[i] = inf;
	}
	for (int i = 0; i < ss.size(); ++i) {
		q.push(ss[i]);
		dis[ss[i]] = 0;
	}
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for (int i = 0; i <edges[cur].size(); ++i) {
			int v = edges[cur][i];
			if (dis[v] > dis[cur]+1) {
				dis[v] = dis[cur]+1;
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>a[i];
		if (i-a[i] >= 1) {
			edges[i-a[i]].push_back(i);
		}
		if (i + a[i] <= n) {
			edges[i+a[i]].push_back(i);
		}
	}
	// 倒过来做bfs。
	vector<int> ans(n+1, -1);
	vector<int> ss;
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 2==1) {
			ss.push_back(i);
		}
	}
	bfs(ss);
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 2==0 && dis[i] < inf) {
			ans[i] = dis[i];
		}
	}
	ss.clear();
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 2== 0) {
			ss.push_back(i);
		}
	}
	bfs(ss);
	for (int i = 1; i <= n; ++i) {
		if (a[i] % 2==1 && dis[i] < inf) {
			ans[i] = dis[i];
		}
	}
	for (int i = 1; i <= n; ++i) {
		 cout<<ans[i];
		 if (i < n) cout<<" ";
		 else cout<<endl;
	}
	return 0;
}
