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
#define N 310
#define M 180005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
int t;
int a[N];
ll dp[2][M];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(dp, 0LL, sizeof(dp));
  int dt = n*300;
  dp[1][dt] = 1LL;
  for (int i = 1; i < n-1; ++i) {
    int now = i&1;
    for (int j = 0; j <= 2*dt; ++j) {
      dp[now^1][j] = 0LL;
    }
    for (int j = 0; j <= 2*dt; ++j) {
      if (dp[now][j] > 0) {
        if (j + a[i+1] <= 2*dt) {
          dp[now^1][j+a[i+1]] = (dp[now^1][j+a[i+1]] + dp[now][j])%mod2;
        }
        if (2*dt-j-a[i+1] != j+a[i+1] && 2*dt-j-a[i+1] <= 2*dt) {
          int x = 2*dt-j-a[i+1];
          dp[now^1][x] = (dp[now^1][x] + dp[now][j])%mod2;
        }
      }
    }
  }
  ll ans = 0LL;
  for (int i = 0; i <= 2*dt; ++i) {
    if (dp[(n-1)&1][i]) {
      ans = (ans + dp[(n-1)&1][i])%mod2;
    }
  }
  cout<<ans<<endl;
  return 0;
}
