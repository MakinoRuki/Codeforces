
#include <iostream>
#include <sstream>
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
#define N 2000005
#define M 1805
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N];
int dp[M][M];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
 //  ll x, y;
   scanf("%d%d", &n, &k);
   for (int i = 1; i <= n; ++i) {
     scanf("%d", &a[i]);
   }
   for (int i = 0; i <= k; ++i) {
     b[i]=-1;
   }
   vector<int> v;
   v.clear();
   for (int i = 1; i <= n; ++i) {
     if (v.empty()) v.push_back(i);
     else if (a[i] > a[v.back()]) {
       v.push_back(i);
     }
   }
   b[0]=0;
   for (auto i : v) {
     if (b[a[i]] < 0) b[a[i]] = i;
   }
   b[k+1]=-1;
   for (int i = k; i >= 1; --i) {
     if (b[i] < 0) b[i] = b[i+1];
   }
   int m = (int)v.size();
   for (int i = 0; i <= k+1; ++i) {
     for (int j = 0; j <= k+1; ++j) {
       dp[i][j] = -1;
     }
   }
   dp[0][0] = 0;
   int ans=0;
   // 因为在到达某个可以更新max的位置时候可以选择不更新
   // 所以第一维应该看第一次更新到某个max时的下标。
   for (int i = 0; i <= k; ++i) {
     for (int j = 0; j <= k; ++j) {
       if (dp[i][j] >= 0) {
         int id = b[i];
         for (int i2 = i+1; i2 <= k; ++i2) {
           int id2 = b[i2];
           if (id2 >= 0 && j + i2 <= k) {
             dp[i2][j+i2] = max(dp[i2][j+i2], dp[i][j]+(id2-id)*i);
           //  cout<<"i="<<i2<<" "<<j+i2<<" "<<dp[i2][j+i2]<<endl;
             ans = max(ans, dp[i2][j+i2] + (n+1-id2)*i2);
           }
         }
       }
     }
   }
  //  for (int i = 0; i < m; ++i) {
  //    int id = v[i];
  //    int nxt = (i + 1 < m ? v[i+1] : n+1);
  //    for (int j = 0; j <= k; ++j) {
  //      if (dp[i][j] >= 0) {
  //        int dt = k-j;
  //     //   if (i == 1 && j == 0) cout<<"ij="<<i<<" "<<j<<" "<<dt<<" "<<id<<" "<<a[id]<<" "<<dp[i][j]<<" "<<nxt<<endl;
  //        for (int i2 = i+1; i2 <= m; ++i2) {
  //          if (dt >= a[id]) {
  //             dp[i+1][j+a[id]] = max(dp[i+1][j+a[id]], dp[i][j]+(nxt-id)*a[id]);
  //             if (i > 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (nxt-id)*a[v[i-1]]);
  //             // cout<<"ij2="<<i<<" "<<j<<" "<<dp[i+1][j+a[id]]<<endl;
  //           } else {
  //             // cout<<"???"<<endl;
  //             if (i-1>=0) {
  //               dt = max(dt, a[v[i-1]]);
  //             }
  //             ans = max(ans, dp[i][j] + (n+1-id) * dt);
  //           }
  //        }
  //      }
  //    }
  //  }
  //  for (int i = 0; i <= k; ++i) {
  //    ans = max(ans, dp[m][i]);
  //  }
   printf("%d\n", ans);
 }
 return 0;
}
