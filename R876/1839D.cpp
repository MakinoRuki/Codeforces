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
#define N 300005
#define M 510
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int dp[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    a[0] = 0;
    a[n+1] = n+1;
    for (int i = 0; i <= n+1; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n+1; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k < i; ++k) {
          if (a[k] < a[i]) {
            if (k + 1 < i) {
              if (j) dp[i][j] =min(dp[i][j], dp[k][j-1] + i-k-1);
            } else {
              dp[i][j] = min(dp[i][j], dp[k][j]);
            }
          }
        }
      }
    }
    int ans=dp[n+1][0];
    for (int i = 1; i <= n; ++i) {
      ans = min(ans, dp[n+1][i]);
      printf("%d ", ans);
    }
    cout<<endl;
  }
  return 0;
}
