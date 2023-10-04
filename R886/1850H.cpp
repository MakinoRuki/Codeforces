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
int par[N];
ll dis[N];
int find(int u) {
  if (u == par[u]) {
    return u;
  }
  int pa = find(par[u]);
  dis[u] = dis[u] + dis[par[u]];
  par[u] = pa;
  return par[u];
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      dis[i] = 0;
    }
    bool ok = true;
    for (int i = 1; i <= m; ++i) {
      int a,b,d;
      scanf("%d%d%d", &a, &b, &d);
      int fa = find(a);
      int fb = find(b);
      if (fa != fb) {
        par[fa] = fb;
        dis[fa] = d - dis[a] + dis[b];
      } else {
        if (-dis[b] + dis[a] != d) {
          ok=false;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
