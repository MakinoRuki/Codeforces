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
#define N 300005
#define M 750
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
int dp[N][5][5][5];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      for (int j1 = 0; j1 < 5; ++j1) {
        for (int j2=0; j2 < 5; ++j2) {
          for (int l=0;l<=3; ++l) {
            dp[i][j1][j2][l] = 0;
          }
        }
      }
    }
    dp[0][0][0][0] = 1;
    int ans=0;
    for (int i = 0; i < n; ++i) {
      for (int j1=0; j1 < 4; ++j1) {
        for (int j2=0; j2< 4; ++j2) {
          int s1=(j1&1)>0;
          int s2=(j1&(1<<1))>0;
          int t1=(j2&1)>0;
          int t2=(j2&(1<<1))>0;
          for (int l=0;l<=3; ++l) {
            dp[i+1][j1][j2][l] = (dp[i+1][j1][j2][l] + dp[i][j1][j2][l]) % mod2;
            if (a[i+1] == 1) {
              if (!s1&&!s2) {
                dp[i+1][j1|1][j2|1][min(l+1,3)] = (dp[i+1][j1|1][j2|1][min(l+1,3)] + dp[i][j1][j2][l]) % mod2;
                if (!t1 && !t2 && l>=2) ans = (ans + dp[i][j1][j2][l]) % mod2;
              }
            } else if (a[i+1] == 2) {
              if (s1 || (!s1&&!s2)) {
                if (t1) dp[i+1][j1|2][(j2^1)|2][min(l+1,3)] = (dp[i+1][j1|2][(j2^1)|2][min(l+1,3)] + dp[i][j1][j2][l]) % mod2;
                else dp[i+1][j1|2][j2|2][min(l+1,3)] = (dp[i+1][j1|2][j2|2][min(l+1,3)] + dp[i][j1][j2][l]) % mod2;
                if (!t2 && l>=2) ans = (ans + dp[i][j1][j2][l]) % mod2; 
              }
            } else {
              if (s1 || s2 || (!s1 &&!s2)) {
                if (l>=2) ans = (ans + dp[i][j1][j2][l]) % mod2;
              }
            }
          }
        }
      }
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
