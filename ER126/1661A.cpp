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
#define N 30
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m;
int t;
int a[N];
int b[N];
ll dp[N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i][j] = (1LL<<61)-1;
      }
    }
    dp[1][0] = 0;
    dp[1][1] = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (dp[i][j] < (1LL<<61)-1) {
          ll x = a[i];
          ll y = b[i];
          if (j == 1) swap(x, y);
          dp[i+1][0] = min(dp[i+1][0], dp[i][j] + abs(a[i+1]-x) + abs(b[i+1]-y));
          dp[i+1][1] = min(dp[i+1][1], dp[i][j] + abs(b[i+1]-x) + abs(a[i+1]-y));
        }
      }
    }
    // for (int i = 2; i <= n; ++i) {
    //   cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }
    printf("%lld\n", min(dp[n][0], dp[n][1]));
  }
  return 0;
}
