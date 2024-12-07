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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[2][N];
int dp[2][M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = -inf;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int now=i&1;
        for (int j = 0; j <= n; ++j) {
            dp[now^1][j][0] = dp[now^1][j][1] = -inf;
        }
        for (int j = 0; j <= i; ++j) {
            if (dp[now][j][1] > -inf) {
                dp[now^1][j][1] = max(dp[now^1][j][1], dp[now][j][1]+a[1][i+1]);
                dp[now^1][j+1][1] = max(dp[now^1][j+1][1], dp[now][j][1] + a[0][i+1]);
            }
            if (dp[now][j][0] > -inf) {
                dp[now^1][j][0] = max(dp[now^1][j][0], dp[now][j][0]+a[1][i+1]);
                dp[now^1][j+1][0] = max(dp[now^1][j+1][0], dp[now][j][0] + a[0][i+1]);
                dp[now^1][j][1] = max(dp[now^1][j][1], dp[now][j][0]+a[0][i+1]+a[1][i+1]);
            }
        }
    }
    int ans=-inf;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[n&1][i][1]);
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

