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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<int> edges[N];
ll dp[N][2][2];
int dep[N];
void dfs(int u, int p, int d) {
  dep[u] = d;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}
void dfs2(int u, int p) {
  int cnt=0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    cnt++;
    dfs2(v, u);
  }
  if (u == 1) return;
  if (dep[u] == 1) {
    dp[u][1][1] = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      dp[u][1][1] += min(min(dp[v][1][0], dp[v][0][0]), min(dp[v][1][1], dp[v][0][1]));
    }
    dp[u][1][1] = min(dp[u][1][1], (ll)inf);
  } else if (dep[u] == 2) {
    dp[u][1][1] = 1;
    dp[u][1][0] = 0;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      dp[u][1][1] += min(min(dp[v][1][0], dp[v][0][0]), min(dp[v][1][1], dp[v][0][1]));
      dp[u][1][0] += min(dp[v][1][0], dp[v][1][1]);
    }
    dp[u][1][1] = min(dp[u][1][1], (ll)inf);
    dp[u][1][0] = min(dp[u][1][0], (ll)inf);
  } else {
    if (cnt == 0) {
      dp[u][1][1] = 1;
      dp[u][0][0] = 0;
      return ;
    }
    dp[u][1][1] = 1;
    dp[u][0][0] = 0;
    ll sum = 0LL;
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      dp[u][1][1] += min(min(dp[v][1][0], dp[v][0][0]), min(dp[v][1][1], dp[v][0][1]));
      //dp[u][1][0] += dp[v][1][1];
      sum += min(dp[v][1][0], dp[v][1][1]);
      dp[u][0][0] += dp[v][1][0];
    }
    dp[u][1][1] = min(dp[u][1][1], (ll)inf);
    //dp[u][1][0] = min(dp[u][1][0], (ll)inf);
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      if (v == p) continue;
      dp[u][1][0] = min(dp[u][1][0], sum - min(dp[v][1][0], dp[v][1][1]) + dp[v][1][1]);
    }
    dp[u][0][0] = min(dp[u][0][0], (ll)inf);
  }
}
int main() {
  cin>>n;
  // vector<int> tmp = {1};
  // for (int i = 2; i <= n; ++i) {
  //   int id = rand()%(int)tmp.size();
  //   printf("%d %d\n", i, tmp[id]);
  //   tmp.push_back(i);
  // }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j1 = 0; j1 < 2; ++j1) {
      for (int j2 = 0; j2 < 2; ++j2) {
        dp[i][j1][j2] = inf;
      }
    }
  }
  dfs2(1, 0);
  // for (int i = 1; i <= n; ++i) {
  //   cout<<"i="<<i<<" "<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
  // }
  int ans=0;
  for (int i = 0; i < edges[1].size(); ++i) {
    int v = edges[1][i];
    ans += min(dp[v][1][0], dp[v][1][1]);
  }
  cout<<ans<<endl;
  return 0;
}
