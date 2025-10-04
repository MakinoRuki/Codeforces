
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
#define N 600005
#define M 305
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
int dp[2][M][M];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[i][j][k] = 0;
        }
      }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int now=i&1;
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[now^1][j][k]=0;
        }
      }
      int v = a[i+1];
      for (int j = 0; j <= n; ++j) {
        for (int k = 0; k <= n; ++k) {
          dp[now^1][j][k] = (dp[now^1][j][k] + dp[now][j][k]) % mod;
          if (v < k) continue;
          if (j == 0 || v >= j) {
            dp[now^1][v][k] = (dp[now^1][v][k] + dp[now][j][k]) % mod;
          } else if (k == 0 || v >= k) {
            dp[now^1][j][v] = (dp[now^1][j][v] + dp[now][j][k]) % mod;
          } else {
            dp[now^1][j][k] = (dp[now^1][j][k] + dp[now][j][k]) % mod;
          }
        }
      }
    }
    int ans=0;
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= n; ++k) {
        ans = (ans + dp[n&1][j][k]) % mod;
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
