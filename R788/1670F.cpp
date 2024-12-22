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
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
ll dp[62][2*M];
ll C[2*M][2*M];
ll calc(ll x, ll z) {
  memset(dp, 0LL, sizeof(dp));
  dp[0][0] = 1LL;
  for (int i = 0; i <= 60; ++i) {
    int cur = 60-i;
    for (int j = 0; j <= 2*n; ++j) {
        int k = j;
        if ((1LL<<cur)&x) k++;
        for (int j2 = 0; j2 <= min(n,k); ++j2) {
            if ((1LL<<cur)&z) {
                if (j2%2) {
                    int k2 = min(2*n, (k-j2)*2);
                    dp[i+1][k2] = (dp[i+1][k2] + dp[i][j]*C[n][j2]%mod) % mod;
                }
            } else {
                if ((j2%2)==0) {
                    int k2 = min(2*n, (k-j2)*2);
                    dp[i+1][k2] = (dp[i+1][k2] + dp[i][j]*C[n][j2]%mod) % mod;
                }
            }
        }
    }
  }
  ll res=0LL;
  for (int i = 0; i <= 2*n; ++i) {
    res=(res+dp[61][i])%mod;
  }
  return res;
}
int main() {
  ll l,r,z;
  cin>>n>>l>>r>>z;
  for (int i = 0; i <= 2*n; ++i) {
    C[i][0] = 1LL;
    for (int j = 1; j <= i; ++j) {
        C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
    }
  }
  ll ans = (calc(r, z) - calc(l-1, z) + mod) % mod;
  printf("%lld\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

