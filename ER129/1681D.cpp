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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
map<ll, int> dp;
int ans;
int dfs(ll x) {
  if (dp.find(x) != dp.end()) {
    return dp[x];
  }
  dp[x] = inf;
  ll nx = x;
  vector<int> ds;
  ds.clear();
  bool vis[10] = {0};
  while(nx) {
    ds.push_back(nx%10);
    vis[nx%10] = true;
    nx/=10;
  }
  if (ds.size() == n) {
    return dp[x] = 0;
  }
  if (ds.size() > n) return dp[x];
  for (int d = 0; d < 10; ++d) {
    if (d == 1) continue;
    if (vis[d]) {
      if (d == 0) {
        if (n == 1) {
          dfs(x * d);
        }
      } else {
        dp[x] = min(dp[x], dfs(x * d) + 1);
      }
    }
  }
  return dp[x];
}
int main() {
//   cin>>t;
// //  mt19937 rnd(time(0));
//   for (int cas=1; cas<=t; ++cas) {
//     scanf("%d", &n);

//   }
  ll x;
  cin>>n>>x;
  dp.clear();
  ans = inf;
  dfs(x);
  if (dp[x] >= inf) {
    puts("-1"); 
  } else {
    printf("%d\n", dp[x]);
  }
  return 0;
}
