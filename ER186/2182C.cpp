
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
#define M 10002
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
int a[M];
int b[M];
int c[M];
int dp[M][M];
int res[2][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i =1; i<=n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
      a[n+i] = a[i];
      b[n+i] = b[i];
      c[n+i] = c[i];
    }
    for (int i = 2*n; i >= 1; --i) {
      for (int j = 2*n; j >= 1; --j) {
        dp[i][j]=0;
        if (a[i]<b[j]) {
          dp[i][j]=1;
          if (i+1<=2*n && j+1<=2*n &&dp[i+1][j+1]) dp[i][j]+=dp[i+1][j+1];
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      res[0][i]=0;
      for (int j = 1; j <= n; ++j) {
        if (dp[j][i]>=n) res[0][i]++;
       // cout<<"ij1="<<j<<" "<<i<<" "<<dp[j][i]<<endl;
      }
    }
    for (int i = 2*n; i >= 1; --i) {
      for (int j = 2*n; j >= 1; --j) {
        dp[i][j]=0;
        if (b[i]<c[j]) {
          dp[i][j]=1;
          if (i+1<=2*n && j+1<=2*n &&dp[i+1][j+1]) dp[i][j]+=dp[i+1][j+1];
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      res[1][i]=0;
      for (int j = 1; j <= n; ++j) {
        if (dp[i][j]>=n) res[1][i]++;
        //cout<<"ij2="<<i<<" "<<j<<" "<<dp[i][j]<<endl;
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      ans += (ll)res[0][i]*(ll)res[1][i];
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
