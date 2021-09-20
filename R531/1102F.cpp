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
#define M 17
#define N 20005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, x, y;
int a[M][N];
ll dp[M][M][1<<16];
ll mx[M][M];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  if (n == 1) {
    ll ans = 0LL;
    for (int i = 2; i <= m; ++i) {
      if (i == 2) ans = abs(a[1][i] - a[1][i-1]);
      else ans = min(ans, (ll)abs(a[1][i] - a[1][i-1]));
    }
    cout<<ans<<endl;
  } else {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ll det = 0;
        for (int k = 1; k <= m; ++k) {
          if (k == 1) det = abs(a[i][k] - a[j][k]);
          else det = min(det, (ll)abs(a[i][k] - a[j][k]));
        }
        mx[i][j] = det;
      }
    }
    memset(dp, 0LL, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      dp[i][i][(1<<i)] = (1LL<<62)-1;
    }
    for (int i = 1; i < (1<<n)-1; ++i) {
      for (int i1 = 0; i1 < n; ++i1) {
        if (!((1<<i1) & i)) continue;
        for (int i2 = 0; i2 < n; ++i2) {
          if (!((1<<i2) & i)) continue;
          for (int j = 0; j < n; ++j) {
            if (j != i1 && j != i2 && !((1<<j) & i)) {
              // if (i == 1 && i1 == 0 && i2 == 0 && j == 1) {
              //   cout<<dp[i1][i2][i]<<" "<<mx[i2][j]<<endl;
              // }
              dp[i1][j][(1<<j) | i] = max(dp[i1][j][(1<<j)|i], min(dp[i1][i2][i], mx[i2+1][j+1]));
              // if (i == 1 && i1 == 0 && i2 == 0 && j == 1) {
              //   cout<<dp[i1][j][(1<<j)|i]<<endl;
              // }
            }
          }
        }
      }
    }
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
      for (int i2 = 0; i2 < n; ++i2) {
        if (i != i2) {
          if (m == 1) {
            ans = max(ans, dp[i][i2][(1<<n)-1]);
          } else {
            ll det = 0LL;
            for (int j = 1; j < m; ++j) {
              if (j == 1) det = abs(a[i2+1][j] - a[i+1][j+1]);
              else det = min(det, (ll)abs(a[i2+1][j] - a[i+1][j+1]));
            }
            ll cur = min(dp[i][i2][(1<<n)-1], det);
            ans = max(ans, cur);
          }
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
