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
#define N 200005
#define M 1000005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int dp[2][M];
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int w,f;
    scanf("%d%d", &w, &f);
    scanf("%d", &n);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + a[i];
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j <= sum[n]; ++j) {
        dp[i][j] = inf;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      int now = i&1;
      for (int j = 0; j <= sum[n]; ++j) {
        dp[now^1][j] = inf;
      }
      for (int j = 0; j <= sum[n]; ++j) {
        if (dp[now][j] < inf) {
          if (j+a[i+1] <= sum[n]) {
            int t1 = (j + a[i+1]+w-1)/w;
            int t2 = (sum[i]-j+f-1)/f;
            dp[now^1][j+a[i+1]] = min(dp[now^1][j+a[i+1]], max(t1,t2));
          }
          int t1 = (j+w-1)/w;
          int t2 = (sum[i]-j+a[i+1]+f-1)/f;
          dp[now^1][j] = min(dp[now^1][j], max(t1,t2));
        }
      }
    }
    int ans = inf;
    for (int i = 0; i <= sum[n]; ++i) {
      ans = min(ans, dp[n&1][i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
