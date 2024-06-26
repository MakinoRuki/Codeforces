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
#define N 500005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int sum[N];
int dp[N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
      sum[i]=sum[i-1];
      if (s[i-1] == '1') sum[i]++;
    }
    for (int i = 0; i <= n+1; ++i) {
      dp[i][0] = false;
      dp[i][1] = false;
    }
    dp[0][0] = true;
    dp[n+1][1] = true;
    for (int i = 1; i <= n; ++i) {
      if (i <= k) {
        if ((sum[i] == i) || (sum[i] == 0)) {
          dp[i][0] = true;
        }
      } else {
        if (dp[i-k][0]) {
          if (s[i-k-1] == '0') {
            if ((s[i-1] == '1') && (sum[i]-sum[i-k] == k)) {
              dp[i][0]=true;
            }
          } else {
            if ((s[i-1] == '0') && (sum[i]-sum[i-k] == 0)) {
              dp[i][0] = true;
            }
          }
        }
      }
    }
    for (int i = n; i >= 1; --i) {
      if (n-i+1 <= k) {
        if ((sum[n]-sum[i-1] == n-i+1) || (sum[n]-sum[i-1] == 0)) {
          dp[i][1] = true;
        }
      } else {
        if (dp[i+k][1]) {
          if (s[i+k-1] == '0') {
            if ((s[i-1] == '1') && (sum[i+k-1]-sum[i-1] == k)) {
              dp[i][1]=true;
            }
          } else {
            if ((s[i-1] == '0') && (sum[i+k-1]-sum[i-1] == 0)) {
              dp[i][1] = true;
            }
          }
        }
      }
    }
    if (dp[n][0]) {
      printf("%d\n", n);
      continue;
    }
    int ans=-1;
    for (int p = 1; p < n; ++p) {
      int l2 = n-p;
      int r2 = l2 % k;
      int r1 = k-r2;
      if (r2 == 0) {
        if (dp[p+1][1] && dp[p][0] && s[p-1] != s[n-1]) {
          ans=p;
          break;
        }
      } else {
        if (dp[p+1][1] && dp[p-r1][0] && ((n-r2==0) || (p-r1==0) || (s[n-r2-1] == s[p-r1-1]))) {
          // if (s[p-r1-1] == '0') {
          //   if ((s[n-1] == '1') && (s[p-1] == '1') && (sum[n]-sum[n-r2]==r2) && (sum[p]-sum[p-r1]==r1)) {
          //     ans=p;
          //     break;
          //   }
          // } else {
          //   if ((s[n-1] == '0') && (s[p-1] == '0') && (sum[n]-sum[n-r2]==0) && (sum[p]-sum[p-r1]==0)) {
          //     ans=p;
          //     break;
          //   }
          // }
          if (p-r1<=0 || s[p-r1-1] != s[p-1]) {
            if (n-r2 <=0 || s[n-1] != s[n-r2-1]) {
              int tmp= sum[n]-sum[n-r2] + sum[p]-sum[p-r1];
              if (tmp == k || tmp == 0) {
                ans=p;
                break;
              }
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
