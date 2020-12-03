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
#define M 20005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t[N];
vector<int> ts[N];
int par[N];
int find(int x) {
	return x==par[x] ? x : par[x] = find(par[x]);
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		ts[t[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		par[i] = i;
	}
	int tot=n-1;
	for (int i = 1; i <= n; ++i) {
		if (i - 1 >= 1 && t[i] == t[i-1]) {
			tot--;
		}
	}
	printf("%d\n" ,tot);
	for (int i = 1; i < m; ++i) {
		//printf("%d\n", tot-1);
		int a,b;
		scanf("%d%d", &a, &b);
	//	int a1=a,b1=b;
		int pa=find(a);
		int pb=find(b);
		if (ts[pa].size() > ts[pb].size()) {
			swap(pa,pb);
		}
		for (int j = 0; j < ts[pa].size(); ++j) {
			if (ts[pa][j]-1>=1 && find(t[ts[pa][j]-1]) == pb) {
				tot--;
			}
			if (ts[pa][j]+1<=n && find(t[ts[pa][j]+1]) == pb) {
				tot--;
			}
		}
		par[pa] = pb;
		while(!ts[pa].empty()) {
			ts[pb].push_back(ts[pa].back());
			ts[pa].pop_back();
		}
		printf("%d\n", tot);
	}
	return 0;
}
