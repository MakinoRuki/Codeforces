
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int dp[M][M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll n;
    scanf("%lld%d", &n, &k);
    for (int i = 0; i <= 35; ++i) {
      for (int j = 0; j <= 35; ++j) {
        dp[i][j][0] = dp[i][j][1] = -1;
      }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < 31; ++i) {
      for (int j = 0; j <= min(31, k); ++j) {
        for (int x = 0; x < 2; ++x) {
          if (dp[i][j][x] >= 0) {
            int bt = ((1LL<<i) & n) > 0;
            int q = (bt+x)/2;
            int r = (bt+x)%2;
            dp[i+1][j][q] = max(dp[i+1][j][q], dp[i][j][x]+q);
            if (j+1<=k) {
              q = (bt+x+1)/2;
              r = (bt+x+1)%2;
              dp[i+1][j+1][q] = max(dp[i+1][j+1][q], dp[i][j][x]+q);
            }
          }
        }
      }
    }
    ll ans = 0LL;
    for (int i = 0; i <= min(31, k); ++i) {
      if (dp[31][i][0] >= 0) {
        ans = max(ans, (ll)dp[31][i][0] + max(k-i-1, 0));
      }
      if (dp[31][i][1] >= 0) {
        ans = max(ans, (ll)dp[31][i][1] + k-i);
      }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
