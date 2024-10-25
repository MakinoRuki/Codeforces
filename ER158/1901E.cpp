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
#include <stack>
#define N 500005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<int> edges[N];
ll dp[N][4];
ll ans;
void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = dp[u][2] = dp[u][3] = -(1LL<<61);
  dp[u][0] = 0;
  for (int i = 0; i < edges[u].size(); ++i) {
    int v  = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
    for (int i = 3; i >= 0; --i) {
      ll x = max(max(dp[v][0],dp[v][1]), max(dp[v][2], dp[v][3]));
      dp[u][min(i+1, 3)] = max(dp[u][min(i+1, 3)], dp[u][i] + x);
    }
  }
  //cout<<"u="<<u<<endl;
  for (int i = 0; i < 4; ++i) {
   // cout<<"i="<<i<<" "<<dp[u][i]<<endl;
    ans = max(ans, dp[u][i] + (i == 2 ? 0 : a[u]));
    dp[u][i] = dp[u][i] + (i == 1 ? 0 : a[u]);
    //cout<<"i2="<<i<<" "<<dp[u][i]<<endl;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    ans = 0LL;
    dfs(1, 0);
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

