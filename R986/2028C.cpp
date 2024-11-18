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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
int dp[N][2];
ll sum[N];
bool check(ll x) {
  if (x == 0) {
    if (dp[n][0] >= m) return true;
    return false;
  }
  int r = 1;
  for (int i = 1; i <= n; ++i) {
    while(r <= n && sum[r] - sum[i-1] < x) {
      r++;
    }
    if (r > n) return false;
    if (dp[i-1][0] + dp[r+1][1] >= m) {
      return true;
    }
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int v;
    sum[0]=0LL;
    scanf("%d%d%d", &n, &m, &v);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i]=sum[i-1]+a[i];
    }
    for (int i = 0; i <= n+1; ++i) {
      for (int j = 0; j < 2;++j) {
        dp[i][j] = 0;
      }
    }
    dp[0][0]=0;
    int l = 1;
    for (int i = 1; i <= n; ++i) {
      while(l <= i && sum[i]-sum[l-1] >= v) {
        l++;
      }
      if (l>1) l--;
      if (sum[i]-sum[l-1]>=v) {
        dp[i][0] = dp[l-1][0]+1;
      }
    }
    dp[n+1][1] = 0;
    int r = n;
    for (int i = n; i >= 1; --i) {
      while(r >= i && sum[r]-sum[i-1]>=v) {
        r--;
      }
      if (r<n) r++;
      if (sum[r] - sum[i-1]>=v) {
        dp[i][1] = dp[r+1][1]+1;
      }
    }
    ll lx = 0, rx = sum[n];
    while(lx < rx) {
      ll mid = (lx+rx+1)/2;
     // cout<<"lx="<<lx<<" "<<rx<<" "<<mid<<endl;
      if (check(mid)) {
        lx = mid;
      } else {
        rx = mid-1;
      }
    }
    if (!check(rx)) puts("-1");
    else printf("%lld\n", rx);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

