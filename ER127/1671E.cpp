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
#define N 400005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
string s;
ll dp[N];
//string v[N];
string dfs(int u) {
  if (u > (1LL<<n)-1) {
    return "";
  }
  string x = dfs(u*2);
  string y = dfs(u*2+1);
  dp[u] = 1LL;
  if (!x.empty()) {
    dp[u] = dp[u] * (dp[2*u] * dp[2*u+1] % mod2) % mod2;
    if (x != y) {
      dp[u] = dp[u] * 2LL % mod2;
    }
    if (x > y) swap(x, y);
    return string(1, s[u-1]) + x + y;
  }
  return string(1, s[u-1]);
}
int main() {
  cin>>n;
  cin>>s;
  // for (int i = 1; i < N; ++i) {
  //   v[i] = "";
  // }
  // for (int i = 1; i <= (1LL<<n)-1; ++i) {
  //   v[i].push_back(s[i-1]);
  // }
  dfs(1);
  printf("%lld\n", dp[1]);
  return 0;
}
