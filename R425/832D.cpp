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
#define M 22
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, q;
vector<int> edges[N];
int lev[N];
int dp[N][M];
void dfs(int u, int p, int lv) {
  lev[u] = lv;
  if (p > 0) {
    dp[u][0] = p;
  }
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, lv+1);
  }
}
void calc() {
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dp[j][i-1] >= 1) {
        dp[j][i] = dp[dp[j][i-1]][i-1];
      }
    }
  }
}
int getlca(int a, int b) {
  if (lev[a] > lev[b]) {
    swap(a,b);
  }
  for (int i = 20; i>= 0; --i) {
    if (dp[b][i] >= 1 && lev[dp[b][i]] >= lev[a]) {
      b = dp[b][i];
    }
  }
  for (int i = 20; i >= 0; --i) {
    if (dp[a][i] >= 1 && dp[a][i] != dp[b][i]) {
      a = dp[a][i];
      b = dp[b][i];
    }
  }
  if (a != b) {
    return dp[a][0];
  }
  return a;
}
int getdis(int a, int b) {
  int lca = getlca(a, b);
  return lev[a]+lev[b] - 2*lev[lca];
}
int main() {
  cin>>n>>q;
  for (int i = 2; i <= n; ++i) {
    int u;
    scanf("%d", &u);
    edges[u].push_back(i);
    edges[i].push_back(u);
  }
  memset(dp, -1, sizeof(dp));
  dfs(1, 0, 0);
  calc();
  while(q-->0) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int id = -1, lv = -1;
    int lca = getlca(a, b);
    if (lev[lca] > lv) {
      lv = lev[lca];
      id = lca;
    }
  //  cout<<"lca="<<lca<<endl;
    lca = getlca(b, c);
    if (lev[lca] > lv) {
      lv = lev[lca];
      id = lca;
    }
   // cout<<"lca="<<lca<<endl;
    lca = getlca(a, c);
    if (lev[lca] > lv) {
      lv = lev[lca];
      id = lca;
    }
   // cout<<"lca="<<lca<<endl;
    int ans = 0;
    ans = max(getdis(a, id), max(getdis(b, id), getdis(c, id)));
    printf("%d\n", ans+1);
  }
  return 0;
}
