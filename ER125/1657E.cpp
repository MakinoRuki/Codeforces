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
#define M 202
#define N 260
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int c;
ll dp[N][N];
ll comb[N][N];
ll pw[N][N*N*2];
int main() {
  for (int i = 0; i <= 250; ++i) {
    comb[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
      comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod2;
    }
  }
  for (int i = 1; i <= 250; ++i) {
    pw[i][0] = 1LL;
    for (int j = 1; j <= 250 * 250; ++j) {
      pw[i][j] = pw[i][j-1]  * (ll)i % mod2;
    }
  }
  cin>>n>>k;
  memset(dp, 0LL, sizeof(dp));
  dp[0][0] = 1LL;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] > 0) {
        dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod2;
        for (int j2 = 1; j2 + j < n; ++j2) {
         // if (i+1 == 1 && j + j2 == 1) cout<<"x="<<i<<" "<<j<<" "<<j2<<endl;
          ll det = comb[n-1-j][j2];
          det = det * pw[k-i][j2 * j + j2 * (j2-1)/2] % mod2;
          det = det * dp[i][j] % mod2;
          dp[i+1][j+j2] = (dp[i+1][j+j2] + det) % mod2;
        }
      }
    }
  }
  // for (int i = 1; i <= k; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
  //   }
  // }
  printf("%lld\n", dp[k][n-1]);
  return 0;
}
