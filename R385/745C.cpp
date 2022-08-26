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
#define N 2000
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int c[N];
vector<int> edges[N];
int par[N];
int cnt[N];
int cnt2[N];
bool vis[N];
vector<pair<int,int>> es;
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  // cin>>t;
  // mt19937 rnd(time(0));
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n>>m>>k;
  es.clear();
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &c[i]);
  }
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    cnt[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
    es.push_back(make_pair(u, v));
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
      par[pu] = pv;
      cnt[pv] += cnt[pu];
    }
  }
  ll ans = 0LL;
  for (int i = 0; i < es.size(); ++i) {
    int u = es[i].first;
    int v = es[i].second;
    int pu = find(u);
    cnt2[pu]++;
  }
  vector<pair<int,int>> rk1, rk2;
  rk1.clear();
  rk2.clear();
  for (int i = 1; i <= k; ++i) {
    int pu = find(c[i]);
    vis[pu] = true;
  }
  for (int i = 1; i <= n; ++i) {
    int pu = find(i);
    if (pu == i) {
      if (vis[i]) {
        rk1.push_back(make_pair(cnt[i], i));
      } else {
        rk2.push_back(make_pair(cnt[i], i));
      }
      ans += cnt[i]*(cnt[i]-1)/2-cnt2[i];
    }
  }
  sort(rk1.begin(), rk1.end());
  sort(rk2.begin(), rk2.end());
  for (int i = rk2.size()-1; i >= 0; --i) {
    ans += rk2[i].first * rk1.back().first;
    rk1.back().first += rk2[i].first;
  }
  printf("%lld\n", ans);
  return 0;
}
