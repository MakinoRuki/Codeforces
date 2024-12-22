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
#define M 210
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[M][M];
ll r[M][M];
ll sum[2*M];
ll dp[M][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = (1LL<<61)-1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        sum[0]=0;
        for (int j = 1; j <= m; ++j) {
            sum[j] = a[1][j];
        }
        for (int j = 1; j <= m; ++j) {
            sum[m+j] = a[1][j];
        }
        for (int j = 1; j <= 2*m; ++j) {
            sum[j] += sum[j-1];
        }
        for (int j = 1; j <= m; ++j) {
            dp[1][i] = min(dp[1][i], k*(ll)(j-1)+sum[j+i-1]-sum[j-1]);
        }
    }
    for (int i = 1; i < n; ++i) {
        sum[0]=0;
        for (int j = 1; j <= 2*m; ++j) {
            if (j<=m) sum[j] = a[i+1][j];
            else sum[j] = a[i+1][j-m];
            sum[j] += sum[j-1];
        }
        for (int l = 1; l <= m; ++l) {
            for (int j = 1; j <= m; ++j) {
                r[j][l] = (1LL<<61)-1;
            }
            r[m][l] = sum[m+l-1]-sum[m-1];
            for (int j = 1; j < m; ++j) {
                ll dt = m-(m-j);
                r[m][l] = min(r[m][l], k*dt + sum[j+l-1]-sum[j-1]);
            }
            for (int j = m-1; j >= 1; --j) {
                r[j][l] = sum[j+l-1]-sum[j-1];
                r[j][l] = min(r[j][l], r[j+1][l]+k);
            }
            // for (int j = 1; j <= m; ++j) {
            //     cout<<"jl="<<i+1<<" "<<j<<" "<<l<<" "<<r[j][l]<<endl;
            // }
        }
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] < (1LL<<61)-1) {
               // cout<<"ij="<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                for (int j2 = j; j2 <= m; ++j2) {
                    int len = j2-j+1;
                    dp[i+1][j2] = min(dp[i+1][j2], dp[i][j] + r[j][len]);
                }
            }
        }
    }
    ll ans = dp[n][m];
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

