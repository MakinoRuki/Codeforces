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
#define N 2005
#define M 520
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
int par[N];
int dep[N];
int up[N][22];
int dp[N][N];
int ans;
void dfs(int u, int p, vector<int>& stk) {
  stk.push_back(u);
  par[u] = p;
  bool found=false;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    found=true;
    dfs(v, u, stk);
  }
  if (!found) {
    int sz = (int)stk.size();
    for (int i = sz-1; i >= 0; --i) {
      for (int j = i; j < sz; ++j) {
        int u = stk[i];
        int v = stk[j];
        if (u == v) dp[u][v] = 1;
        else {
          int u1 = stk[i+1];
          int v1 = stk[j-1];
          int dt = (a[u] == a[v] ? 2 : 0);
          dp[u][v] = max(dp[u1][v], dp[u][v1]);
          if (i+1 == j) dp[u][v] = max(dp[u][v], dt);
          else dp[u][v] = max(dp[u][v], dp[u1][v1]+dt);
        }
        ans=max(ans, dp[u][v]);
      }
    }
  }
  stk.pop_back();
}
int dfs2(int u, int v) {
  if (dp[u][v] >= 0) {
    return dp[v][u] = dp[u][v];
  }
  if (dp[v][u] >= 0) {
    return dp[u][v] = dp[v][u];
  }

  dp[u][v] = max(dfs2(par[u], v), dfs2(u, par[v]));
  int dt = (a[u] == a[v] ? 2 : 0);
  dp[u][v] = max(dp[u][v], dfs2(par[u], par[v])+dt);
 // cout<<"uv="<<u<<" "<<v<<" "<<dp[u][v]<<endl;
  return dp[u][v];
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i =1; i <= n; ++i) {
      a[i] = s[i-1]-'a';
      edges[i].clear();
    }
    for (int i =1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = -1;
      }
    }
    vector<int> stk;
    stk.clear();
    ans=0;
    dfs(1, 0, stk);
    for (int i =1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (dp[i][j] < 0) {
          dfs2(i, j);
          ans = max(ans, dp[i][j]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
