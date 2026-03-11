#include <iostream>
#include <sstream>
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
#include <bitset>
#include <chrono>
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
vector<int> edges[N];
ll ans;
ll dp[N][2];
void dfs(int u, int p) {
  dp[u][0] = 0;
  dp[u][1] = 0;
  for (auto v : edges[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u][1] = max(dp[u][1], dp[v][1]);
    dp[u][0] = min(dp[u][0], dp[v][0]);
  }
  ll dt = a[u] + dp[u][0] + dp[u][1];
  if (dt > 0) dp[u][0] -= dt;
  else dp[u][1] -= dt;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  dfs(1, 0);
  ll ans = abs(dp[1][0]) + abs(dp[1][1]);
  cout<<ans<<endl;
  return 0;
}
 
