#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 3002
using namespace std;
typedef long long ll;
const ll inf = 2000000000000000000LL;
int n;
vector<int> edges[N];
int c[N];
int a[N];
vector<int> b;
int dfs(int cur) {
	int sons = 1;
	if (edges[cur].size() == 0) {
		if (c[cur] > 0) {
			return -1;
		}
		b.insert(b.begin() + c[cur], cur);
		return sons;
	}
	for (int i = 0; i < edges[cur].size(); ++i) {
		int v = edges[cur][i];
		int num = dfs(v);
		if (num < 0) return -1;
		sons += num;
	}
	if (c[cur] >= sons) {
		return -1;
	}
	b.insert(b.begin() + c[cur], cur);
	return sons;
}
int main() {
	cin>>n;
	int root=0;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; ++i) {
		int p;
		cin>>p>>c[i];
		if (p == 0) root = i;
		else edges[p].push_back(i);
	}
	b.clear();
	int res=dfs(root);
	if (res < 0) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		for (int i = 0; i < n; ++i) {
			a[b[i]] = i+1;
		}
		for (int i = 1; i <= n; ++i) {
			cout<<a[i];
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
