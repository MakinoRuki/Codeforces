#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, q;
ll k;
int t;
ll a[N];
vector<int> edges[N];
int vis[N];
int dp[N];
bool dfs(int u, ll x) {
  if (vis[u] < 0) {
    return true;
  }
  if (vis[u] == 0) {
    vis[u] = -1;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (a[v] <= x && dfs(v, x)) {
        return true;
      }
    }
    vis[u] = 1;
  }
  return false;
}
int dfs2(int u, ll x) {
  if (dp[u] > -1) return dp[u];
  dp[u] = 1;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (a[v] <= x) {
      auto res=dfs2(v, x);
      dp[u] = max(dp[u], res+1);
    }
  }
  return dp[u];
}
bool check(ll v) {
  for (int i =1; i <= n; ++i) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && a[i] <= v) {
      bool res = dfs(i, v);
   //   if (v==3 && res) cout<<"i="<<i<<endl;
      if (res) return true;
    }
  }
  for (int i =1; i <= n; ++i) {
    dp[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    if (dp[i] < 0 && a[i] <= v) {
      dfs2(i, v);
    }
  }
  int len=-1;
  for (int i = 1; i <= n; ++i) {
//    if (v==3 && a[i]<=v) cout<<"i="<<i<<" "<<dp[i]<<endl;
    if (a[i] <= v) len=max(len, dp[i]);
  }
  if (len >= k) {
    return true;
  }
  return false;
}
int main() {
  cin>>n>>m>>k;
  ll mn, mx;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    mn = (i == 1 ? a[i] : min(a[i], mn));
    mx = (i == 1 ? a[i] : max(a[i], mx));
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
  }
  ll l = mn, r = mx;
  while(l < r) {
    ll mid=(l+r)/2;
 //   cout<<l<<" "<<r<<" "<<mid<<endl;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  if (check(r)) {
    printf("%lld\n", r);
  } else {
    puts("-1");
  }
  return 0;
}
