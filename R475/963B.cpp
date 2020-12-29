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
ll mod = 1000000009LL;
ll mod2 = 998244353LL;
int t;
int n;
int p[N];
int deg[N];
int deg2[N];
vector<int> edges[N];
int main() {
	cin>>n;
	vector<int> ans(n, 0);
	int l = 0, r = n-1;
	memset(deg, 0, sizeof(deg));
	memset(deg2, 0, sizeof(deg2));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		if (p[i]==0) continue;
		edges[p[i]].push_back(i);
		edges[i].push_back(p[i]);
		deg[i]++;
		deg[p[i]]++;
		deg2[i]++;
		deg2[p[i]]++;
	}
	if (n==1) {
		cout<<"YES"<<endl;
		cout<<1<<endl;
		return 0;
	}
	if (n % 2==0) {
		cout<<"NO"<<endl;
		return 0;
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if (deg[u] % 2) {
			ans[r--] = u;
		} else {
			ans[l++] = u;
			for (int i = 0; i < edges[u].size(); ++i) {
				int v=edges[u][i];
				deg[v]--;
			}
		}
		for (int i = 0; i < edges[u].size(); ++i) {
			int v=edges[u][i];
			deg2[v]--;
			if (deg2[v] == 1) {
				q.push(v);
			}
		}
	}
	if (l > r) {
		cout<<"YES"<<endl;
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d\n", ans[i]);
		}
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}
