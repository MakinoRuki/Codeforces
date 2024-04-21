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
#include <list>
#define N 1000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int cnt[N];
ll dp[M][M][2];
int main() {
  cin>>n;
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    tot += a[i];
  }
  sort(a+1, a+n+1);
  ll ans = 0LL;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= tot; ++j) {
      dp[i][j][0]=dp[i][j][1] = 0LL;
    }
  }
  dp[0][0][0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    ll tmp;
    for (int j = 0; j <= tot; ++j) {
      if (j >= a[i]) {
        tmp = (dp[i-1][j-a[i]][0]+dp[i-1][j-a[i]][1])%mod2;
        dp[i][j][1] = (dp[i][j][1] + tmp)%mod2;
      }
      tmp = (dp[i-1][j][0] + dp[i-1][j][1])%mod2;
      dp[i][j][0] = (dp[i][j][0] + tmp)%mod2;
    }
    for (int j = 0; j <= tot; ++j) {
      if (j >= 2*a[i]) {
        tmp = (j+1)/2LL*dp[i][j][1]%mod2;
      } else {
        tmp = a[i]*dp[i][j][1]%mod2;
      }
      ans = (ans + tmp)%mod2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
