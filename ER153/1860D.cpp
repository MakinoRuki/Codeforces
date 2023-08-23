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
#define N 105
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int p[N];
int dp[2][N][N*N];
int main() {
  string s;
  cin>>s;
  int c0=0,c1=0;
  n = (int)s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') c1++;
    else c0++;
  }
  int limit = n*(n-1)/2;
  if (c0 > 0) limit -= c0*(c0-1)/2;
  if (c1 > 0) limit -= c1*(c1-1)/2;
  limit/=2; 
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n*n; ++k) {
        dp[i][j][k] = inf;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int now = i&1;
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n * n; ++k) {
        dp[now^1][j][k] = inf;
      }
    }
    for (int j = 0; j <= i; ++j) {
      for (int k = 0; k <= n*n; ++k) {
        if (dp[now][j][k] < inf) {
          int n1 = c1 - j;
          if (i-j < c0 && k+n1<=limit) {
            dp[now^1][j][k+n1] = min(dp[now][j][k], dp[now^1][j][k+n1]);
          }
          if (j + 1 <= c1) {
            dp[now^1][j+1][k] = min(dp[now^1][j+1][k], dp[now][j][k] + (s[i] == '0'));
          }
        }
      }
    }
  }
  cout<<dp[n&1][c1][limit]<<endl;
  return 0;
}
