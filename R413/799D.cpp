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
#define N 100005
#define M 42
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a,b,h,w;
ll s[N];
ll dp[M][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>a>>b>>h>>w>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &s[i]);
  }
  sort(s+1, s+n+1);
  int l= 1, r = n;
  while(l < r) {
    swap(s[l], s[r]);
    l++;
    r--;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][h] = w;
  if ((h>=a&&w>=b) ||(h>=b&&w>=a)) {
    puts("0");
    return 0;
  }
  int ans=-1;
  for (int i = 0; i < min(n, 41); ++i) {
    for (int j = h; j <= 100000; ++j) {
      if (dp[i][j] >= 0) {
        ll h2 = min((ll)j * (ll)s[i+1], 100000LL);
        dp[i+1][h2] = max(dp[i+1][h2], dp[i][j]);
        if ((h2>=a&&dp[i+1][h2]>=b) || (h2>=b&&dp[i+1][h2]>=a)) {
          ans=(ans <0 ?i+1:min(ans,i+1));
        }
        ll w2 = min((ll)dp[i][j] * (ll)s[i+1], 100000LL);
        dp[i+1][j] = max(dp[i+1][j], w2);
        if ((j>=a&&dp[i+1][j]>=b) || (j>=b&&dp[i+1][j]>=a)) {
          ans=(ans <0 ?i+1:min(ans,i+1));
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
