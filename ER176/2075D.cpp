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
#define M 63
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
ll dp[M][M][M];
int main() {
  for (int i = 0; i <= 62; ++i) {
    for (int j = 0; j <= 62; ++j) {
        for (int k = 0; k <= 62; ++k) {
            dp[i][j][k] = (1LL<<62)-1;
        }
    }
  }
  dp[0][0][0]=0;
  for (int i = 0; i <= 60; ++i) {
    for (int j = 0; j <= 60; ++j) {
        for (int k = 0; k <= 60; ++k) {
            if (dp[i][j][k] < (1LL<<62)-1) {
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if (j + i+1 <= 61) dp[i+1][j+i+1][k] = min(dp[i+1][j+i+1][k], dp[i][j][k]+(1LL<<(i+1)));
                if (k+i+1<=61) dp[i+1][j][k+i+1] = min(dp[i+1][j][k+i+1], dp[i][j][k]+(1LL<<(i+1)));
            }
        }
    }
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll x,y;
    scanf("%lld%lld", &x, &y);
    ll ans=(1LL<<62)-1;
    for (int i = 0; i <= 60; ++i) {
        for (int j = 0; j <= 60; ++j) {
            if ((x >> i)==(y>>j)) ans=min(ans, dp[61][i][j]);
           // if (i<=3 && j<=3) cout<<"ij="<<i<<" "<<j<<" "<<ans<<endl;
        }
    }
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
