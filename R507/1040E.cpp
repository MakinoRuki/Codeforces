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
#define M 21
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
ll c[N];
unordered_map<ll, vector<pair<int,int>>> es;
vector<int> edges[N];
bool vis[N];
//bool vis2[N];
void dfs(int u, int& cnt) {
  if (vis[u]) {
    return;
  }
  cnt++;
  vis[u]=true;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v=edges[u][i];
    dfs(v, cnt);
  }
}
ll getpw(ll a, ll b) {
  ll res=1LL;
  while(b) {
    if (b&1) res=res*a%mod;
    a=a*a%mod;
    b/=2;
  }
  return res;
}
int main() {
  es.clear();
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &c[i]);
  }
  vector<pair<ll, pair<int,int>>> rk;
  rk.clear();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    rk.push_back(make_pair(c[u]^c[v], make_pair(u, v)));
  }
  sort(rk.begin(), rk.end());
  memset(vis, false, sizeof(vis));
  ll ans = 0LL;
  int i = 0;
  ll tot=(1LL<<k);
  while(i < rk.size()) {
    int j = i;
    unordered_set<int> vs;
    vs.clear();
    while(j < rk.size() && rk[j].first == rk[i].first) {
      int u=rk[j].second.first;
      int v=rk[j].second.second;
      vs.insert(u);
      vs.insert(v);
      edges[u].push_back(v);
      edges[v].push_back(u);
      j++;
    }
    ll tmp=1LL;
    vector<int> vv(vs.begin(), vs.end());
    for (auto v : vv) {
      if (!vis[v]) {
        int cnt=0;
        dfs(v, cnt);
        tmp = tmp * 2LL % mod;
      }
    }
    ll det=n-(ll)vv.size();
    tmp = tmp * getpw(2LL, det) % mod;
    ans = (ans + tmp) % mod;
    for (auto v : vv) {
      vis[v] = false;
      edges[v].clear();
    }
    tot--;
    i = j;
  }
  // for (auto itr : es) {
  //   auto vv = itr.second;
  //   unordered_set<int> vs;
  //   vs.clear();
  //   // unordered_map<int, int> par;
  //   // unordered_map<int, int> cnt;
  //   // cnt.clear();
  //   // par.clear();
  //   for (int i = 0; i <vv.size(); ++i) {
  //     int u=vv[i].first;
  //     int v=vv[i].second;
  //     vs.insert(u);
  //     vs.insert(v);
  //     edges[u].push_back(v);
  //     edges[v].push_back(u);
  //     // vis1[u] = true;
  //     // vis1[v] = true;
  //     // par[u]=u;
  //     // cnt[u]=1;
  //     // par[v]=v;
  //     // cnt[v]=1;
  //   }
  //   ll tmp=1LL;
  //   for (auto v : vs) {
  //     if (!vis[v]) {
  //       int cnt=0;
  //       dfs(v, cnt);
  //       tmp = tmp * 2LL % mod;
  //     }
  //   }
  //   ll det=n-(ll)vs.size();
  //   tmp = tmp * getpw(2LL, det) % mod;
  //   ans = (ans + tmp) % mod;
  //   for (auto v : vs) {
  //     vis[v] = false;
  //     edges[v].clear();
  //   }
  // }
 // cout<<(int)es.size()<<endl;
 // ll tot=(1LL<<k)-(ll)es.size();
//  cout<<ans<<" "<<tot<<endl;
  tot %= mod;
  ans = (ans + tot * getpw(2LL, n) % mod) % mod;
  cout<<ans<<endl;
  return 0;
}
