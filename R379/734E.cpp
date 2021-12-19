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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int col[N];
vector<int> edges[N];
int par[N];
int dfs(int u, int p, int& ans) {
  int mx = 0, mx2 = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    int res = dfs(v, u, ans);
    if (res > mx) {
      mx2 = mx;
      mx = res;
    } else if (res > mx2) {
      mx2 = res;
    }
  }
  ans = max(ans, mx + mx2);
  return mx+1;
}
int find(int x) {
  return x== par[x] ? x : par[x] = find(par[x]);
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &col[i]);
    par[i] = i;
  }
  vector<pair<int,int>> es;
  es.clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    es.push_back(make_pair(u, v));
    if (col[u] == col[v]) {
      int pu = find(u);
      int pv = find(v);
      if (pu != pv) {
        par[pu] = pv;
      }
    }
  }
  set<pair<int,int>> ss;
  ss.clear();
  for (int i = 0; i < es.size(); ++i) {
    int u = es[i].first;
    int v = es[i].second;
    int pu = find(u);
    int pv = find(v);
    if (col[u] != col[v]) {
      edges[pu].push_back(pv);
      edges[pv].push_back(pu);
   //   ss.insert(make_pair(min(pu, pv), max(pu, pv)));
    }
  }
  int ans = 0;
  dfs(find(1), 0, ans);
  // int cnt=0;
  // for (int i = 1; i <= n; ++i) {
  //   par[i] = find(i);
  //   if (par[i] == i) cnt++;
  // }
 // if (n == 256) cout<<"v="<<cnt<<endl;
  printf("%d\n", (ans+1)/2);
  return 0;
}
