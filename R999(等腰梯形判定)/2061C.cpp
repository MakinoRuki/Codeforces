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
#define N 200005
#define M 1005
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
int dp[N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = dp[i][1] = 0;
    }
    if (a[1] == 0) {
      dp[1][1] = 1;
      dp[1][0] = 1;
    } else {
      dp[1][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (j == 0) {
          int pre=0;
          if (i-1>=1) pre=a[i-1];
          pre++;
          if (a[i+1] == pre) dp[i+1][1] = (dp[i+1][1]+dp[i][j])%mod2;
          else dp[i+1][1] = 0;
        } else {
          if (a[i+1] == a[i]) dp[i+1][1] = (dp[i+1][1] + dp[i][j])%mod2;
          dp[i+1][0] = (dp[i+1][0] + dp[i][j])%mod2;
        }
      }
    }
    int ans=(dp[n][1]+dp[n][0])%mod2;
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
