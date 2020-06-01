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
#define M 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll a[N];
int b[N], c[N];
vector<int> edges[N];
ll ans;
int rzo[N], roz[N];
void dfs(int u, int p, set<pair<int,int>>& ss) {
  int zo = 0, oz = 0;
  ss.insert(make_pair(a[u], u));
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v==p) continue;
    dfs(v, u, ss);
    zo += rzo[v];
    oz += roz[v];
  }
  ss.erase(make_pair(a[u], u));
  if (b[u] == 0 && c[u] == 1) zo++;
  if (b[u] == 1 && c[u] == 0) oz++;
  rzo[u] = zo;
  roz[u] = oz;
  int det = min(rzo[u], roz[u]);
  if (ss.empty()) {
    ans += a[u] * 2LL * det;
    rzo[u] -= det;
    roz[u] -= det;
  } else {
    auto pr = *ss.begin();
    if (a[u] <= pr.first) {
      ans += a[u] * 2LL * det;
      rzo[u] -= det;
      roz[u] -= det;
    }
  }
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%d%d", &a[i], &b[i], &c[i]);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  int zo = 0, oz = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i]==0 && c[i]==1) {
      zo++;
    } else if (b[i]==1 && c[i]==0) {
      oz++;
    }
  }
  if (zo != oz) {
    cout<<-1<<endl;
  } else {
    for (int i = 1; i <= n; ++i) {
      rzo[i] = 0;
      roz[i] = 0;
    }
    set<pair<int, int>> ss;
    ans=0LL;
    dfs(1, 0, ss);
    cout<<ans<<endl;
  }
  return 0;
}
