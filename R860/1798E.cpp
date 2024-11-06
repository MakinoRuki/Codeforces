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
#define N 3000005
#define M 325
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int dp[N][3];
int ans[N];
int suf[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ans[i] = 2;
      dp[i][0] = dp[i][1] = -1;
      suf[i] = -1;
    }
    for (int i = n; i >= 1; --i) {
      if (i+a[i]+1==n+1) {
        dp[i][0] = 1;
      } else if (i+a[i]+1<=n) {
        if (dp[i+a[i]+1][0]>=0) dp[i][0] = max(dp[i][0], dp[i+a[i]+1][0]+1);
      }
      if (i+a[i]+1<=n) {
        if (dp[i+a[i]+1][1]>=0) dp[i][1] = max(dp[i][1], dp[i+a[i]+1][1]+1);
      }
      if (i==n) {
        if (a[i]) dp[i][1] = max(dp[i][1], 1);
      } else {
        dp[i][1] = max(dp[i][1], 1);
        int res = suf[i+1];
        if (res >= 0) dp[i][1] = max(dp[i][1], res+1);
      }
      suf[i] = dp[i][0];
      if (i+1<=n) suf[i] = max(suf[i], suf[i+1]);
      if (i < n) {
        if (dp[i+1][0] == a[i]) ans[i] = 0;
        else if (dp[i+1][1] >= a[i] || dp[i+1][0]>=0) ans[i] = 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      printf("%d ", ans[i]);
    }
    cout<<endl;
  } 
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

