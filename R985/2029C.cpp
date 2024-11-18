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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
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
      for (int j = 0; j < 3; ++j) {
        dp[i][j] = -1;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (dp[i][j] >= 0) {
          int dt = 0;
          if (dp[i][j]<a[i+1]) dt++;
          else if (dp[i][j]>a[i+1]) dt--;
          if (j==0) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+dt);
            dp[i+1][1] = max(dp[i+1][1], dp[i][j]);
          } else if (j==1) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][2] = max(dp[i+1][2], dp[i][j]+dt);
          } else {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+dt);
          }
        }
      }
    }
    int ans=max(dp[n][1], dp[n][2]);
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

