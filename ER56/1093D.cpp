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
#define M 2000005
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
vector<int> edges[N];
int col[N];
bool dfs(int u, int c, int& bn, int& wn) {
  if (col[u] >= 0) {
    if (col[u] != c) {
      return false;
    } else {
      return true;
    }
  }
  col[u] = c;
  if (c == 1) bn++;
  else wn++;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (!dfs(v, !c, bn, wn)) return false;
  }
  return true;
}
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x% mod2;
    x=x*x%mod2;
    y /= 2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      edges[i].clear();
      col[i] = -1;
    }
    for (int i = 1; i <= m; ++i) {
      int u,v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ll ans = 1LL;
    for (int i = 1; i <= n; ++i) {
      if (col[i] < 0) {
        int bn = 0, wn = 0;
        if (!dfs(i, 0, bn, wn)) {
          ans=0LL;
          break;
        }
        ll cur = (getpw(2LL, bn) + getpw(2LL, wn)) % mod2;
        ans = ans * cur % mod2;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
