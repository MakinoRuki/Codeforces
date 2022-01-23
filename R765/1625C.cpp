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
#define M 500005
#define N 505
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
int dp[N][N];
int d[N], a[N];
int main() {
  cin>>n>>l>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &d[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  d[n+1] = l;
  for (int i = 0; i <= n+1; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] = 2*inf;
    }
  }
  dp[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i][j] < inf) {
        for (int i2 = i+1; i2 <= n+1; ++i2) {
          int det = i2-i-1;
          if (j+det <= k) {
        //    cout<<i<<" "<<i2<<" "<<a[i]<<" "<<d[i2]-d[i]<<endl;
            dp[i2][j+det] = min(dp[i2][j+det], dp[i][j]+a[i]*(d[i2]-d[i]));
          }
        }
      }
    }
  }
  int ans=2*inf;
  for (int i = 0; i <= k; ++i) {
    ans=min(ans, dp[n+1][i]);
  }
  printf("%d\n", ans);
  return 0;
}
