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
#define M 505
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
ll a[N];
vector<int> edges[N];
ll dp[N][21];
int mn[N][2];
void dfs(int u, int p) {
  for (int i = 0; i < edges[u].size(); ++i) {
    int v = edges[u][i];
    if (v == p) continue;
    dfs(v, u);
  }
//  cout<<"u="<<u<<endl;
  for (int i = 1; i <= 20; ++i) {
    ll tmp = 0LL;
  //  cout<<"i="<<i<<endl;
    for (int j = 0; j < edges[u].size(); ++j) {
      int v= edges[u][j];
      if (v == p) continue;
    //  cout<<"v="<<v<<endl;
      if (mn[v][0] != i) {
      //  cout<<"vv0="<<mn[v][0]<<endl;
        tmp += dp[v][mn[v][0]];
      } else {
        //cout<<"vv1="<<mn[v][1]<<endl;
        tmp += dp[v][mn[v][1]];
      }
    }
    dp[u][i] = tmp + (ll)i * a[u];
  //  cout<<"dp=:"<<dp[u][i]<<endl;
    if (mn[u][0] < 0 || dp[u][i] < dp[u][mn[u][0]]) {
      mn[u][1] = mn[u][0];
      mn[u][0] = i;
    } else if (mn[u][1] < 0 || dp[u][i] < dp[u][mn[u][1]]) {
      mn[u][1] = i;
    }
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      edges[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 20; ++j) {
        dp[i][j] = 9223372036854775807LL;
      }
      for (int j = 0; j < 2; ++j) {
        mn[i][j] = -1;
      }
    }
    dfs(1, 0);
    ll ans = 9223372036854775807LL;
    for (int i = 1; i <= 20; ++i) {
      ans = min(ans, dp[1][i]);
    }
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
