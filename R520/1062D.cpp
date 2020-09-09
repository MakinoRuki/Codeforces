#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, q;
vector<int> edges[N];
bool vis[N];
ll bfs(int s) {
	ll res=0LL;
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for (int i = 0; i < edges[cur].size(); ++i) {
			int v=edges[cur][i];
			if (v<cur) {
				res+=2LL*cur/v;
			} else {
				res+=2LL*v/cur;
			}
			if (!vis[v]) {
				vis[v]=true;
				q.push(v);
			}
		}
	}
	return res;
}
int main() {
	cin>>n;
	memset(vis, false, sizeof(vis));
	ll ans=0LL;
	for (int i = 2; i <= n; ++i) {
		for (int j = i*2; j <= n; j += i) {
			edges[i].push_back(j);
			edges[j].push_back(i);
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			ans = max(ans, bfs(i));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
