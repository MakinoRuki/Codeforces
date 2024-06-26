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
#include <list>
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int ans;
int dis[N];
int par[N];
void dfs(int u, int p, int d) {
  par[u]=p;
  dis[u]=d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int x,y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    if (n == 1) {
      puts("0");
      continue;
    }
    dfs(x, 0, 0);
    int mx=0;
    if (x == y) {
      for (int i = 1; i <= n; ++i) {
        mx=max(mx, dis[i]);
      }
      printf("%d\n", 2*(n-1)-mx);
      continue;
    }
    vector<int> v;
    v.clear();
    int ans=0;
    int cur=y;
    v.push_back(y);
    while(true) {
      cur=par[cur];
      v.push_back(cur);
      if (cur == x) {
        break;
      }
    }
    int sz=(int)v.size();
    if ((sz%2)==0) {
      int mx1=0,mx2=0;
      dfs(v[sz/2-1], 0, 0);
      for (int i = 1; i <= n; ++i) {
        mx1=max(mx1, dis[i]);
      }
      dfs(v[sz/2], 0, 0);
      for (int i = 1; i <= n; ++i) {
        mx2=max(mx2, dis[i]);
      }
      mx=max(mx1, mx2);
      ans += min((sz)/2+2*(n-1)-mx1+1, sz/2-1+2*(n-1)-mx2+1);
    } else {
      ans += sz/2;
      dfs(v[sz/2], 0, 0);
      for (int i = 1; i <= n; ++i) {
        mx=max(mx, dis[i]);
      }
      ans += 2*(n-1)-mx;
    }
    printf("%d\n", ans);
  }
  return 0;
}
