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
#define M 21
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, h;
int n;
ll k;
int q;
ll dp[N][N];
ll comb[N][N];
ll dfs(int n, int x) {
  if (dp[n][x] >= 0) {
    return dp[n][x];
  }
  if (x <= n-1) return 0LL;
  if (n == 0) return 0LL;
  if (n == 1) {
    return dp[n][x] = x;
  }
  vector<ll> pw;
  pw.clear();
  for (int i = 0; i <= n; ++i) {
    if (i == 0) pw.push_back(1);
    else {
      pw.push_back(pw[i-1] * (ll)(n-1) % mod2);
    }
  }
  dp[n][x] = 0LL;
  for (int i = 0; i <= n; ++i) {
    dp[n][x] = (dp[n][x] + dfs(n-i, x-(n-1)) * comb[n][i] % mod2 * pw[i] % mod2) % mod2;
  }
//  cout<<n<<" "<<x<<" "<<dp[n][x]<<endl;
  return dp[n][x];
}
int main() {
  int x;
  cin>>n>>x;
  memset(dp, -1, sizeof(dp));
  memset(comb, 0LL, sizeof(comb));
  for (int i = 0; i <= n; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod2;
    }
  }
  ll ans = 1LL;
  for (int i = 1; i <= n; ++i) {
    ans = ans * (ll)x % mod2;
  }
  ans = (ans - dfs(n, x) + mod2) % mod2;
//  ans = (ans - dp[n][x] + mod2) % mod2;
  cout<<ans<<endl;
  return 0;
}
