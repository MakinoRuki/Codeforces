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
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n, m;
ll sons[N];
ll h[N];
ll p[N];
vector<int> edges[N];
bool dfs(int u, int par) {
	ll ss = 0LL, hs = 0LL;
	sons[u] = p[u];
	for (int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if (v==par) continue;
		if (!dfs(v, u)) return false;
		ss += sons[v];
		hs += h[v];
	}
	sons[u] += ss;
	ll a1 = (ss+hs);
	ll b1 = (ss-hs);
	if (a1 >= 0 && a1%2==0 && b1>=0 && b1%2==0) {
		a1 = a1/2;
		b1 = b1/2;
		ll a = (sons[u]+h[u]);
		ll b = (sons[u]-h[u]);
		if (a >= 0 && a%2==0 && b>=0 && b % 2==0) {
			a/=2;
			b/=2;
			ll det = a+b-a1-b1;
			if (det<0 || det > p[u]) return false;
			if (a1 > a) return false;
			if (b1 < b && b-b1 > p[u]) {
				return false;
			}
			if (b1 > b && b1-b+a1 > a) {
				return false;
			}
		//	cout<<"u="<<u<<endl;
			return true;
		} else {
			return false;
		}
	}
	return false;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &p[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &h[i]);
		}
		for (int i = 1; i <= n; ++i) {
			edges[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		bool ok = dfs(1, 0);
		if (ok) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
  return 0;
}
