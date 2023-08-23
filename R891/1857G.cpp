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
#include <random>
#include <ctime>
#define N 200005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
vector<pair<int, pair<int,int>>> es;
int par[N];
int cnt[N];
int mx[N];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
ll getpw(ll x, ll y) {
  ll res = 1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s;
    scanf("%d%d", &n, &s);
    es.clear();
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      cnt[i] = 1;
      mx[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      es.push_back(make_pair(w, make_pair(u, v)));
    }
    sort(es.begin(), es.end());
    ll ans = 1LL;
    for (int i = 0; i < es.size(); ++i) {
      int u = es[i].second.first;
      int v = es[i].second.second;
      int w = es[i].first;
      int pu = find(u);
      int pv = find(v);
      int wc = s-w+1;
      ans = ans * getpw(wc, (ll)cnt[pu] * (ll)cnt[pv] - 1) % mod2;
      par[pv] = pu;
      cnt[pu] += cnt[pv];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
