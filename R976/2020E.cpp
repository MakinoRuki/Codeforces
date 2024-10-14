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
#define N 500005
#define M 1100
#define eps 1e-7
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int p[N][2];
int dp[2][M];
ll getpw(ll x, ll y) {
  ll res= 1LL;
  while(y) {
    if (y&1) res=res * x% mod;
    x=x*x%mod;
    y/=2;
  }
  return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      p[i][1] = x%mod;
      p[i][0] = (10000-x)%mod;
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 1024; ++j) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      int now = i&1;
      for (int j = 0; j < 1024; ++j) {
        dp[now^1][j] = 0;
      }
      for (int j = 0; j < 1024; ++j) {
        dp[now^1][j] = (dp[now^1][j] + (int)((ll)dp[now][j] * (ll)p[i+1][0] % mod)) % mod;
        dp[now^1][j^a[i+1]] = (dp[now^1][j^a[i+1]] + (int)((ll)dp[now][j] * (ll)p[i+1][1] % mod))%mod;
      }
     // cout<<"i="<<i<<" "<<dp[now^1][0]<<" "<<dp[now^1][1]<<" "<<dp[now^1][2]<<" "<<dp[now^1][3]<<endl;
    }
    ll ans = 0LL;
    ll pp = getpw(10LL, 4LL*(ll)n*(mod-2));
    for (int i = 0; i < 1024; ++i) {
      ll tmp = (ll)dp[n&1][i] * pp % mod;
     // if (i<=3) cout<<"i="<<i<<" "<<dp[n&1][i]<<" "<<tmp<<" "<<getpw(4LL, mod-2)%mod<<endl;
      ll v = (ll)i * (ll)i % mod;
      ans = (ans + tmp * v % mod) % mod;
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

