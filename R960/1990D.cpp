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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int dp[N][3];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = dp[i][1] = dp[i][2] = n+1;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        dp[i+1][0] = min(dp[i+1][0], dp[i][j] + 1);
        if (a[i+1] <= 0) {
          dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
        }
        if (j == 0) {
          if (a[i+1] <= 2) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][j]+1);
          }
        } else if (j == 1) {
          if (a[i+1] <= 2) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
          } else if (a[i+1] <= 4) {
            dp[i+1][2] = min(dp[i+1][2], dp[i][j]+1);
          }
        } else {
          if (a[i+1] <= 4) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][j]+1);
          }
        }
      }
    }
    printf("%d\n", dp[n][0]);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
