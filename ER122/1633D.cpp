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
#define N 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int cnt[N];
int dp[N][N*16];
int b[N], c[N];
int main() {
  for (int i = 1; i <= 1000; ++i) {
    cnt[i] = inf;
  }
  cnt[1] = 0;
  for (int i = 1; i <= 1000; ++i) {
    for (int j = 1; j <= i+1; ++j) {
      if (i + i/j > i && i+i/j <= 1000) {
        cnt[i+i/j] = min(cnt[i+i/j], cnt[i] + 1);
      }
    }
  }
 // cout<<cnt[5]<<" "<<cnt[2]<<" "<<cnt[6]<<" "<<cnt[3]<<endl;
  // int mx=0;
  // for (int i = 1; i <= 1000; ++i) {
  //   mx=max(mx, cnt[i]);
  // }
  // cout<<mx<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i]);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n*14; ++j) {
        dp[i][j] = -1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= min(k,i*14); ++j) {
        if (dp[i][j] >= 0) {
          int j2 = j + cnt[b[i+1]];
          if (j2 <= min(n*14, k)) {
            dp[i+1][j2] = max(dp[i+1][j2], dp[i][j] + c[i+1]);
          }
          dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
      }
    }
  //  cout<<dp[1][3]<<" "<<dp[2][4]<<" "<<dp[3][4]<<" "<<dp[4][7]<<" "<<dp[5][9]<<endl;
    int ans=0;
    for (int i = 0; i <= min(n*14, k); ++i) {
      ans=max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
