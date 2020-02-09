#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
vector<int> edges[N];
int q;
int id[N], od[N];
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin>>a>>b;
		if (a < b) swap(a, b);
		od[a]++;
		id[b]++;
		edges[b].push_back(a);
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		ans += (ll)id[i] * (ll)od[i];
	}
	cout<<ans<<endl;
	cin>>q;
	for (int i = 1; i <= q; ++i) {
		int v;
		cin>>v;
		ans -= (ll)id[v] * (ll)od[v];
		for (int j = 0; j < edges[v].size(); ++j) {
			int x = edges[v][j];
			ans -= id[x];
			od[x]--;
			id[x]++;
			ans += od[x];
			edges[x].push_back(v);
		}
		od[v] += id[v];
		id[v] = 0;
		edges[v].clear();
		cout<<ans<<endl;
	}
	return 0;
}
