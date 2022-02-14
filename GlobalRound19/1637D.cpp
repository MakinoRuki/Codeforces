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
#define N 110
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int b[N];
ll dp[N][N*N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n * 100; ++j) {
        dp[i][j] = (1LL<<61)-1;
      }
    }
    ll tot=0LL;
    dp[n][a[n]] = 0LL;
    dp[n][b[n]] = 0LL;
    tot += a[n]+b[n];
    for (int i = n; i > 1; --i) {
      for (int j = 1; j <= 100 * (n-i+1); ++j) {
        if (dp[i][j] < (1LL<<61)-1) {
          ll det = tot-j;
          dp[i-1][a[i-1]+j] = min(dp[i-1][a[i-1]+j], dp[i][j] + (ll)a[i-1] * (ll)j + (ll)b[i-1]* det);
          dp[i-1][b[i-1]+j] = min(dp[i-1][b[i-1]+j], dp[i][j] + (ll)b[i-1] * (ll)j + (ll)a[i-1] * det);
        }
      }
      tot += a[i-1]+b[i-1];
    }
    ll ans = (1LL<<61)-1;
    for (int i = 1; i <= 100 * n; ++i) {
      if (dp[1][i] < (1LL<<61)-1) {
        ans = min(ans, dp[1][i]);
      }
    }
    ans *= 2;
    for (int i = 1; i <= n; ++i) {
      ans += (ll)a[i] * (ll)a[i] * (ll)(n-1);
      ans += (ll)b[i] * (ll)b[i] * (ll)(n-1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
