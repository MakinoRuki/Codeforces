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
#include <list>
#include <random>
#define N 200005
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
vector<int> edges[N];
vector<int> us;
int deg[3][N];
int dp[N];
int main() {
  cin>>n>>m;
  memset(deg, 0, sizeof(deg));
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    deg[1][u]++;
    deg[0][v]++;
    deg[2][v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[2][i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    auto u = q.front();
    q.pop();
    us.push_back(u);
    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i];
      deg[2][v]--;
      if (deg[2][v] == 0) {
        q.push(v);
      }
    }
  }
  memset(dp, 0, sizeof(dp));
  int res = 1;
  for (int i = us.size()-1; i >= 0; --i) {
    int u = us[i];
    if (deg[0][u] > 1) {
      dp[u] = 1;
      if (deg[1][u] > 1) {
        for (int j = 0; j < edges[u].size(); ++j) {
          int v = edges[u][j];
          dp[u] = max(dp[u], dp[v]+1);
          res=max(res,dp[u]);
        }
      }
    } else if (deg[0][u] == 1) {
      if (deg[1][u] > 1) {
        for (int j = 0; j < edges[u].size(); ++j) {
          int v = edges[u][j];
          res=max(res,dp[v]+1);
        }
      }
    } else {
      if (deg[1][u] > 1) {
        for (int j = 0; j < edges[u].size(); ++j) {
          int v = edges[u][j];
          res=max(res,dp[v]+1);
        }
      }
    }
  }
  cout<<res<<endl;
  return 0;
}
