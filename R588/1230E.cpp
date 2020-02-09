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
int n;
ll x[N];
vector<int> edges[N];
unordered_map<ll, ll> cnt[N];
ll ans;
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}
void dfs(int cur, int p) {
	cnt[cur][x[cur]]++;
	ans = (ans + x[cur]) % mod;
	for (auto w : cnt[p]) {
		ll g = gcd(x[cur], w.first);
		ans = (ans + g * w.second % mod) % mod;
		cnt[cur][g] += w.second;
	}
	for (int i = 0; i < edges[cur].size(); ++i) {
		int v=edges[cur][i];
		if (v == p) continue;
		dfs(v, cur);
	}
}
int main() {
	cin>>n;
	for (int i =1; i <= n; ++i) {
		scanf("%lld", &x[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d",&u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	ans = 0LL;
	dfs(1, 0);
	cout<<ans<<endl;
	return 0;
}
