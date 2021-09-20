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
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, k;
ll n;
int m;
ll dp[N], mat[N][N];
int main() {
  cin>>n>>m;
  for (int i = 0; i < m; ++i) {
    dp[i] = 1;
    if (i < m-1) mat[i][i+1]=1;
    else {
      mat[i][0] = mat[i][i] = 1;
    }
  }
  while(n) {
    if (n&1) {
      ll res[N];
      for (int k = 0; k < m; ++k) {
        res[k] = 0LL;
        for (int i = 0; i < m; ++i) {
          res[k] = (res[k] + mat[k][i] * dp[i] % mod) % mod;
        }
      }
      for (int k = 0; k < m; ++k) {
        dp[k] = res[k];
      }
    }
    ll tmp[N][N];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        tmp[i][j] = 0LL;
        for (int k = 0; k < m; ++k) {
          tmp[i][j] = (tmp[i][j] + mat[i][k] * mat[k][j] % mod) % mod;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        mat[i][j] = tmp[i][j];
      }
    }
    // for (int i = 0; i < m; ++i) {
    //   cout<<dp[i]<<endl;
    // }
    // for (int i = 0; i < m; ++i) {
    //   for (int j = 0; j < m; ++j) {
    //     cout<<mat[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    n/=2;
  }
  printf("%lld\n", dp[0]);
  return 0;
}
