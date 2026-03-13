
#include <iostream>
#include <sstream>
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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
ll a[N];
vector<int> edges[N];
ll sum[N];
int dep[N];
int mxd[N];
ll ans[N];
ll val[N];
int dfs(int u, int p, int d) {
  dep[u] = d;
  sum[u] = a[u];
  mxd[u] = dep[u];
  val[u]=0LL;
  for (auto v : edges[u]) {
    if (v== p) continue;
    int dd = dfs(v, u, d+1);
    mxd[u] = max(mxd[u], dd);
    sum[u] += sum[v];
    val[u] += val[v] + sum[v];
  }
  return mxd[u];
}
void dfs2(int u, int p) {
  set<pair<int,int>> ss;
  ss.clear();
  ans[u]=val[u];
 // ll cur = 0LL;
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs2(v, u);
    ans[u] = max(ans[u], val[u]-val[v]+ans[v]);
    ss.insert(make_pair(mxd[v],v));
  }
  for (auto v : edges[u]) {
    if (v == p) continue;
    ss.erase(make_pair(mxd[v], v));
    if (!ss.empty()) {
      auto dd = (*ss.rbegin()).first;
      auto dt = max(dd + 1 - dep[v], 0);
      ans[u] = max(ans[u], val[u] + sum[v]*dt);
    }
    ss.insert(make_pair(mxd[v], v));
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
  //  int x,y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      edges[i].clear();
    }
    for (int i =1; i < n; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs(1,0, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}

