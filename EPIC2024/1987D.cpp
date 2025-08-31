
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
#define N 600005
#define M 5002
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
int dp[M][M];
int cnt[M];
int main() {
//  freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = inf;
      }
    }
    dp[0][0]=0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (dp[i][j] >= inf) continue;
     //   cout<<"ij="<<i<<" "<<j<<endl;
        if (cnt[i+1]) {
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
       //   cout<<"v1="<<i+1<<" "<<j+1<<" "<<dp[i+1][j+1]<<endl;
          if (j >= cnt[i+1] + dp[i][j]) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+cnt[i+1]);
         //   cout<<"v2="<<i+1<<" "<<j<<" "<<dp[i+1][j]<<endl;
          }
        } else {
          dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        }
      }
    }
    int ans=0;
    for (int i = 0; i <= n; ++i) {
      if (dp[n][i] <= i) {
      //  cout<<"i="<<i<<" "<<dp[n][i]<<endl;
        //ans = max(ans, i);
        // 应该找最小的i。
        ans=i;
        break;
      }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
