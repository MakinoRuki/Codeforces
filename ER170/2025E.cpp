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
#define M 510
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
int dp1[M][M];
int dp2[M][M];
int g[M][M][M];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%")
  // }

  scanf("%d%d", &n, &m);
  memset(g, 0, sizeof(g));
  memset(dp1, 0, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  g[0][0][0]=1;
  for (int i = 0; i < m; ++i) {
    for (int j1 = 0; j1 <= m; ++j1) {
        for (int j2 = 0; j2 <= m; ++j2) {
            if (g[i][j1][j2]) {
                if (j2) {
                    g[i+1][j1][j2-1] = (g[i+1][j1][j2-1] + g[i][j1][j2])%mod2;
                    if (j2+1<=m) g[i+1][j1][j2+1] = (g[i+1][j1][j2+1] + g[i][j1][j2])%mod2;
                } else {
                    if (j2+1<=m) g[i+1][j1][j2+1] = (g[i+1][j1][j2+1]+g[i][j1][j2])%mod2;
                    if (j1+1<=m) g[i+1][j1+1][j2] = (g[i+1][j1+1][j2]+g[i][j1][j2])%mod2;
                }
            }
        }
    }
  }
  dp1[0][0]=1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j <= m; ++j) {
        if (dp1[i][j]) {
            if (j==0) {
                if (j+1<=m) dp1[i+1][j+1]= (dp1[i+1][j+1]+dp1[i][j])%mod2;
            } else {
                dp1[i+1][j-1] = (dp1[i+1][j-1]+dp1[i][j])%mod2;
                if (j+1<=m) dp1[i+1][j+1] = (dp1[i+1][j+1]+dp1[i][j])%mod2;
            }
            // if (j == m) {
            //     if (j-1>=0) dp1[i+1][j-1] = (dp1[i+1][j-1]+dp1[i][j])%mod2;
            // } else {
            //     dp1[i+1][j+1] = (dp1[i+1][j+1]+dp1[i][j])%mod2;
            //     if (j-1>=0) dp1[i+1][j-1] = (dp1[i+1][j-1]+dp1[i][j])%mod2;
            // }
        }
    }
  }
  for (int i = 0; i <= m; ++i) {
    dp2[1][i] = g[m][i][0];
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
        if (dp2[i][j]) {
           // cout<<"ij="<<i<<" "<<j<<" "<<dp2[i][j]<<endl;
            for (int j2 = 0; j2 <= m; ++j2) {
                if (j >= j2) {
                    dp2[i+1][j-j2] = (dp2[i+1][j-j2] + 1LL*dp2[i][j]*dp1[m][j2]%mod2)%mod2;
                }
            }
        }
    }
  }
  int ans = dp2[n][0];
  printf("%d\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
