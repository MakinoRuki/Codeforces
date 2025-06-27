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
#define N 500005
#define M 1002
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
ll x;
int t;
int a[N];
ll dp[27][N];
ll fac[N], fac2[N];
ll getpw(ll x, ll y) {
  ll res=1LL;
  while(y) {
    if (y&1) res=res*x%mod2;
    x=x*x%mod2;
    y/=2;
  }
  return res;
}
ll comb(ll x, ll y) {
  if (x<y) return 0LL;
  ll res=fac[x]*fac2[y]%mod2*fac2[x-y]%mod2;
  return res;
}
int main() {
  fac[0]=1LL,fac2[0]=1LL;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1]*(ll)i%mod2;
    fac2[i] = getpw(fac[i], mod2-2);
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int tot=0;
    for (int i = 1; i <= 26; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    for (int i = 0; i <= 26; ++i) {
      for (int j = 0; j <= tot; ++j) {
        dp[i][j]=0LL;
      }
    }
    dp[0][0]=1LL;
    int sum=0;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < tot; ++j) {
        if (dp[i][j]<=0) continue;
        if (a[i+1] == 0) {
          dp[i+1][j] = (dp[i+1][j] + dp[i][j])%mod2;
          continue;
        }
        if (j + a[i+1] <= tot/2) {
          int rem = tot/2-j;
          dp[i+1][j+a[i+1]] = (dp[i+1][j+a[i+1]] + dp[i][j]*comb(rem, a[i+1])%mod2) % mod2;
        }
        if (sum>=j && sum-j+a[i+1]<=(tot+1)/2) {
          int rem = (tot+1)/2-(sum-j);
          dp[i+1][j] = (dp[i+1][j] + dp[i][j]*comb(rem, a[i+1])%mod2)% mod2;
        }
      }
      sum += a[i+1];
    }
    printf("%lld\n", dp[26][tot/2]);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
