
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
#define N 1000005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int c[N];
int dp[M][2*M][M][5];
int getst(int st, char cc) {
  if (st == 3) return 3;
  if (st == 0) {
    if (cc == '(') return 0;
    return 1;
  }
  if (st == 1) {
    if (cc == '(') return 2;
    return 1;
  }
  if (st == 2) {
    if (cc == '(') return 3;
    return 2;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= 2*n; ++j) {
        for (int k = 0; k <= n; ++k) {
          for (int st = 0; st < 5; ++st) {
            dp[i][j][k][st] = 0;
          }
        }
      }
    }
    dp[0][n][0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= 2*n; ++j) {
        for (int k = 0; k <= n; ++k) {
          for (int st = 0; st < 4; ++st) {
          //  cout<<i<<" "<<j<<" "<<k<<" "<<st<<endl;
            if (dp[i][j][k][st] == 0) continue;
            dp[i+1][j][k][st] = (dp[i+1][j][k][st] + dp[i][j][k][st]) % mod2;
            int st2 = getst(st, s[i]);
            int dt = (s[i] == '(' ? 1 : -1);
            if (j+dt >= n) dp[i+1][j+dt][k+1][st2] = (dp[i+1][j+dt][k+1][st2] + dp[i][j][k][st]) % mod2;
          }
        }
      }
    }
    ll ans=0LL;
    for (int i = 0; i <= n; ++i) {
      if (i >= 2) {
        ll tmp = (ll)dp[n][n][i][3] * (ll)(i-2) % (ll)mod2;
        ans = (ans + tmp) % mod2;
      }
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}

