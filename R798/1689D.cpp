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
#define N 1003
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N][N];
int rc[N][2];
int cc[N][2];
int dp[N][N][4];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      for (int j = 1; j <= m; ++j) {
        a[i][j] = (s[j-1]=='B' ? 1 : 0);
      }
    }
    for (int i = 1; i <= n; ++i) {
      rc[i][0] = rc[i][1] = -1;
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) {
          if (rc[i][0] < 0) {
            rc[i][0] = j;
            rc[i][1] = j;
          } else {
            rc[i][1] = j;
          }
        }
      }
    }
    for (int j = 1; j <= m; ++j) {
      cc[j][0] = cc[j][1] = -1;
      for (int i = 1; i <= n; ++i) {
        if (a[i][j]) {
          if (cc[j][0] < 0) {
            cc[j][0] = i;
            cc[j][1] = i;
          } else {
            cc[j][1] = i;
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int c = 0; c < 4; ++c) {
          dp[i][j][c] = -1;
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) dp[i][j][0] = 0;
        if (i-1>=1 && j-1>=1 && dp[i-1][j-1][0] >= 0) {
          dp[i][j][0] = max(dp[i-1][j-1][0] + 2, dp[i][j][0]);
        }
        if (rc[i][0] >= 0 && rc[i][0] <= j) {
          dp[i][j][0] = max(dp[i][j][0], j-rc[i][0]);
        }
        if (cc[j][0] >= 0 && cc[j][0] <= i) {
          dp[i][j][0] = max(dp[i][j][0], i-cc[j][0]);
        }
      }
    }
    // if (n==5 && m == 5) {
    //   for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //       cout<<dp[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    //   }
    // }
    for (int i = 1; i <= n; ++i) {
      for (int j = m; j >=1; --j) {
        if (a[i][j]) dp[i][j][1] = 0;
        if (i-1>=1 && j+1<=m && dp[i-1][j+1][1] >= 0) {
          dp[i][j][1] = max(dp[i-1][j+1][1] + 2, dp[i][j][1]);
        }
        if (rc[i][1] >= 0 && rc[i][1] >= j) {
          dp[i][j][1] = max(dp[i][j][1], rc[i][1]-j);
        }
        if (cc[j][0] >= 0&&cc[j][0] <= i) {
          dp[i][j][1] = max(dp[i][j][1], i-cc[j][0]);
        }
      }
    }
    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i][j]) dp[i][j][2] = 0;
        if (i+1<=n && j-1>=1 && dp[i+1][j-1][2] >= 0) {
          dp[i][j][2] = max(dp[i+1][j-1][2] + 2, dp[i][j][2]);
        }
        if (rc[i][0]>=0 && rc[i][0] <= j) {
          dp[i][j][2] = max(dp[i][j][2], j-rc[i][0]);
        }
        if (cc[j][1]>=0 && cc[j][1] >= i) {
          dp[i][j][2] = max(dp[i][j][2], cc[j][1]-i);
        }
      }
    }
    for (int i = n; i >=1; --i) {
      for (int j = m; j >= 1; --j) {
        if (a[i][j]) dp[i][j][3] = 0;
        if (i+1<=n && j+1<=m && dp[i+1][j+1][3] >= 0) {
          dp[i][j][3] = max(dp[i+1][j+1][3] + 2, dp[i][j][3]);
        }
        if (rc[i][1]>= 0 && rc[i][1] >= j) {
          dp[i][j][3] = max(dp[i][j][3], rc[i][1]-j);
        }
        if (cc[j][1] >= 0 && cc[j][1] >= i) {
          dp[i][j][3] = max(dp[i][j][3], cc[j][1]-i);
        }
      }
    }
    int ax = -1, ay = -1;
    int d = -1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int res = max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3]));
        // if (i == 4 && j == 3) {
        //   cout<<"v="<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<dp[i][j][2]<<" "<<dp[i][j][3]<<endl;
        // }
        if (res >= 0) {
          if (ax < 0) {
            ax=i;
            ay=j;
            d = res;
          } else if (res < d) {
            ax=i;
            ay=j;
            d = res;
          }
        }
      }
    }
    printf("%d %d\n", ax, ay);
  }
  return 0;
}
