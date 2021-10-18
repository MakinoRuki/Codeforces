#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#define eps 1e-7
#define M 502
#define N 42
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int m, k, t;
int n;
int a,b;
string s;
int dp[N][N][N][N*2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &a, &b);
    cin>>s;
    for (int i = 0; i < n; ++i) {
      for (int k1 = 0; k1 < a; ++k1) {
        for (int k2 = 0; k2 < b; ++k2) {
          for (int d = -n; d <= n; ++d) {
            dp[i][k1][k2][d+n] = inf;
          }
        }
      }
    }
    dp[0][(s[0]-'0')%a][0][n+1] = 50;
    dp[0][0][(s[0]-'0')%b][n-1] = -50;
    for (int i = 0; i < n-1; ++i) {
      for (int k1 = 0; k1 < a; ++k1) {
        for (int k2 = 0; k2 < b; ++k2) {
          for (int d = -n; d <= n; ++d) {
            if (dp[i][k1][k2][d+n] < inf) {
              int d2 = (s[i+1]-'0');
              if (dp[i+1][(k1*10+d2)%a][k2][d+1+n] >= inf) dp[i+1][(k1*10+d2)%a][k2][d+1+n] = k1+50;
              if (dp[i+1][k1][(k2*10+d2)%b][d-1+n] >= inf) dp[i+1][k1][(k2*10+d2)%b][d-1+n] = -50+k2;
              // if (i==n-2 && (k2*10+d2)%b == 0 && d-1+n == 8) {
              //   cout<<k1<<" "<<k2<<" "<<d<<" "<<dp[i][k1][k2][d+n]<<endl;
              // }
            }
          }
        }
      }
    }
    // for (int i = 0; i < n; ++i) {
    //   for (int k1 = 0; k1 < a; ++k1) {
    //     for (int k2 = 0; k2 < b; ++k2) {
    //       for (int d = -n; d <= n; ++d) {
    //         if (dp[i][k1][k2][d+n] >= 0) cout<<i<<" "<<k1<<" "<<k2<<" "<<d<<" "<<dp[i][k1][k2][d+n]<<endl;
    //       }
    //     }
    //   }
    // }
    int mind = n+1;
    int x = n+1;
    for (int d = -n+1; d < n; ++d) {
      if (dp[n-1][0][0][d+n] < inf) {
        if (abs(d) < mind) {
          mind = abs(d);
          x = d+n;
        }
      }
    }
    if (mind > n) {
      puts("-1");
    } else {
      string ans="";
      int k1=0, k2=0;
      int d = x;
   //   cout<<x<<endl;
      for (int i = n-1; i >= 0; --i) {
        int dg = s[i]-'0';
        if (dp[i][k1][k2][d] > 0) {
          ans.push_back('R');
          k1 = dp[i][k1][k2][d] - 50;
          d--;
        } else {
          ans.push_back('B');
          k2 = dp[i][k1][k2][d] + 50;
          d++;
        }
      }
      reverse(ans.begin(), ans.end());
      cout<<ans<<endl;
    }
    // for (int i = 0; i < n; ++i) {
    //   for (int j1=0; j1<2; ++j1) {
    //     for (int j2=0; j2<2; ++j2) {
    //       for (int k1 = 0; k1 < a; ++k1) {
    //         for (int k2 = 0; k2 < b; ++k2) {
    //           if (dp[0][i][j1][j2][k1][k2] < INT_MAX) {
    //             update(0, i+1, j1, j2, k1, k2, dp[0][i][j1][j2][k1][k2]);
    //             if (dp[0][i][j1][j2][k1][k2] == 0) {
    //               update(1, i+1, j1, j2, k1, k2, dp[0][i][j1][j2][k1][k2]);
    //             }
    //             update(0, i+1, j1|1, j2, (k1+s[i]-'0')%a, k2, dp[0][i][j1][j2][k1][k2]+1);
    //             if (dp[0][i][j1][j2][k1][k2] - 1 >= 0) {
    //               update(0, i+1, j1, j2|1, k1, (k2+s[i]-'0')%b, dp[0][i][j1][j2][k1][k2]-1);
    //             }
    //             if (dp[0][i][j1][j2][k2][k2]-1 <= 0) {
    //               update(1, i+1, j1, j2|1, k1, (k2+s[i]-'0')%b, dp[0][i][j1][j2][k1][k2]-1);
    //             }
    //           }
    //           if (dp[1][i][j1][j2][k1][k2] > INT_MIN) {
    //             update(1, i+1, j1, j2, k1, k2, dp[1][i][j1][j2][k1][k2]);
    //             if (dp[1][i][j1][j2][k1][k2] == 0) {
    //               update(0, i+1, j1, j2, k1, k2, dp[1][i][j1][j2][k1][k2]);
    //             }
    //             update(1, i+1, j1, j2|1, k1, (k2+s[i]-'0')%b, dp[1][i][j1][j2][k1][k2]-1);
    //             if (dp[1][i][j1][j2][k1][k2] + 1 >= 0) {
    //               update(0, i+1, j1|1, j2, (k1+s[i]-'0')%a, k2, dp[1][i][j1][j2][k1][k2]+1);
    //             }
    //             if (dp[1][i][j1][j2][k2][k2]+1 <= 0) {
    //               update(1, i+1, j1|1, j2, (k1+s[i]-'0')%a, k2, dp[1][i][j1][j2][k1][k2]+1);
    //             }
    //           }
    //         }
    //       }
    //     }
    //   }
    // }
    // dp[0][n][1][1][0][0]
  }
  return 0;
}
