#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 200
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N][N];
int idx1[N];
int idx2[N];
ll dp[N][2];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    idx1[i] = inf;
    idx2[i] = -1;
    for (int j = i; j >= 1; --j) {
      if (a[j][i] == 1) {
        idx1[i] = min(idx1[i], j);
      } else if (a[j][i] == 2) {
        idx2[i] = max(idx2[i], j);
      }
    }
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    int j;
    for (j = 1; j <= i; ++j) {
      if (idx2[j] > 0) {
        break;
      }
    }
    if (j > i) {
      dp[i][1] = 1;
      dp[i][0] = 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int k;
      for (k = j+1; k <= i; ++k) {
        // if (i == n && j == 1) {
        //   cout<<"k="<<k<<" "<<idx1[k]<<" "<<idx2[k]<<endl;
        // }
        if (idx1[k] <= j) break;
        if (idx2[k] > j) break;
      }
      if (k > i) {
       // cout<<"ji="<<j<<" "<<i<<endl;
       // if (j == 1 && i == 3) cout<<"x="<<dp[j][0]<<" "<<dp[j][1]<<
        dp[i][1] = (dp[j][0] + dp[i][1]) % mod2;
        dp[i][0] = (dp[j][1] + dp[i][0]) % mod2;
      }
    }
  }
 // cout<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[2][0]<<" "<<dp[2][1]<<" "<<dp[3][0]<<" "<<dp[3][1]<<endl;
  ll ans = (dp[n][0] + dp[n][1]) % mod2;
  cout<<ans<<endl;
  return 0;
}
