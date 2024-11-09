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
int b[N];
ll dp[2][N][2];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    sum[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + a[i];
    }
    for (int i =1; i <= m; ++i) {
      scanf("%d", &b[i]);
    }
    ll ans0 = (1LL<<61)-1;
    ll ans1=0LL;
    for (int i = 1; i <= m; ++i) {
      for (int j= 0; j <= n; ++j) {
        dp[0][j][0] = dp[1][j][0] = (1LL<<61)-1;
        dp[0][j][1] = dp[1][j][1] = 0;
      }
    }
    for (int i = 1; i <= m; ++i) {
      int now=i&1;
      for (int j = 0; j <= n; ++j) {
        dp[now][j][0] = (1LL<<61)-1;
        dp[now][j][1] = 0LL;
      }
      map<ll, ll> mp;
      mp.clear();
      dp[now][0][0] = 0LL;
      dp[now][0][1] = 1LL;
      mp[0] = 1;
      deque<int> dq;
      dq.push_back(0);
      for (int j = 1; j <= n; ++j) {
        dp[now][j][0] = dp[now^1][j][0];
        dp[now][j][1] = dp[now^1][j][1];
        while(!dq.empty()) {
          auto id = dq.front();
          if (sum[j]-sum[id] > b[i]) {
            mp[dp[now][id][0]] = (mp[dp[now][id][0]] - dp[now][id][1] + mod) % mod;
            dq.pop_front();
            if (mp[dp[now][id][0]] == 0) {
              mp.erase(dp[now][id][0]);
            }
          } else {
            //dp[now][j] = min(dp[now][j], dp[now][id]+m-i);
            if (dp[now][id][0]+m-i < dp[now][j][0]) {
              dp[now][j][0] = dp[now][id][0]+m-i;
              dp[now][j][1] = mp[dp[now][id][0]];
            } else if (dp[now][id][0]+m-i==dp[now][j][0]) {
              dp[now][j][1] = (dp[now][j][1]+mp[dp[now][id][0]])%mod;
            }
            break;
          }
        }
        while(!dq.empty()) {
          auto id = dq.back();
          if (dp[now][j][0] < dp[now][id][0]) {
            dq.pop_back();
            mp[dp[now][id][0]] = (mp[dp[now][id][0]] - dp[now][id][1]+mod) % mod;
            if (mp[dp[now][id][0]] == 0) {
              mp.erase(dp[now][id][0]);
            }
          } else {
            break;
          }
        }
        dq.push_back(j);
        mp[dp[now][j][0]] = (mp[dp[now][j][0]] + dp[now][j][1]) % mod;
      }
      //cout<<"i="<<i<<" "<<dp[i][0][0]<<" "<<dp[i][1][0]<<endl;
      // if (dp[now][n][0] < ans0) {
      //   ans0 = dp[now][n][0];
      //   ans1 = dp[now][n][1];
      // } else if (dp[now][n][0] == ans0) {
      //   ans1 = (ans1 + dp[now][n][1]) % mod;
      // }
    }
    ans0=dp[m&1][n][0];
    ans1=dp[m&1][n][1];
    printf("%lld", (ans0>=(1LL<<61)-1)?-1:ans0);
    if (ans0 < (1LL<<61)-1) {
      printf(" %lld\n", ans1);
    } else {
      cout<<endl;
    }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

