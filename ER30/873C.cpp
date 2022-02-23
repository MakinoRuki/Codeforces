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
int a[N][N];
int sum[N][N];
int dp[N][N*N];
int main() {
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  memset(sum, 0, sizeof(sum));
  for (int j = 1; j <= m; ++j) {
    for (int i = n; i >= 1; --i) {
      sum[i][j] = sum[i+1][j]+a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i <= n*j; ++i) {
      if (dp[j][i] >= 0) {
        int det=0;
        for (int i2 = 1; i2 <= n; ++i2) {
          if (a[i2][j+1]) {
            int add = min(k, n-i2+1);
            add = sum[i2][j+1] - sum[i2+add][j+1];
            dp[j+1][i+det] = max(dp[j+1][i+det], dp[j][i]+add);
            // if (dp[1][1] == 0) {
            //   cout<<"x="<<i<<" "<<j<<" "<<add<<" "<<dp[i][j]<<" "<<det<<" "<<dp[j+1][i+det]<<endl;
            // }
           // if (i2 == 3 && j == 1 && i == 0) cout<<"x="<<dp[j][i]<<" "<<add<<" "<<det<<" "<<dp[j+1][i+det]<<endl;
            det++;
          }
        }
        dp[j+1][i+det] = max(dp[j+1][i+det], dp[j][i]);
      }
    }
  }
  // for (int i = 1; i <= m; ++i) {
  //   for (int j = 0; j <= n*m; ++j) {
  //     cout<<"v="<<i<<" "<<j<<" "<<dp[i][j]<<endl;
  //   }
  // }
  int ans=-1, ans2=-1;
  for (int i = 0; i <= n*m; ++i) {
    if (dp[m][i] >= 0) {
      if (dp[m][i]>ans) {
        ans=dp[m][i];
        ans2 = i;
      } else if (dp[m][i] == ans && i < ans2) {
        ans2 = i;
      }
    }
  }
  cout<<ans<<" "<<ans2<<endl;
  return 0;
}
