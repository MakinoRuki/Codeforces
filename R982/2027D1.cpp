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
ll dp[2][N];
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
    ll ans = (1LL<<61)-1;
    for (int i = 1; i <= m; ++i) {
      for (int j= 0; j <= n; ++j) {
        dp[0][j] = dp[1][j] = (1LL<<61)-1;
      }
    }
    for (int i = 1; i <= m; ++i) {
      int now=i&1;
      for (int j = 0; j <= n; ++j) {
        dp[now][j] = (1LL<<61)-1;
      }
      dp[now][0] = 0LL;
      deque<int> dq;
      dq.push_back(0);
      for (int j = 1; j <= n; ++j) {
        dp[now][j] = dp[now^1][j];
        while(!dq.empty()) {
          auto id = dq.front();
          if (sum[j]-sum[id] > b[i]) {
            dq.pop_front();
          } else {
            dp[now][j] = min(dp[now][j], dp[now][id]+m-i);
            break;
          }
        }
        while(!dq.empty()) {
          auto id = dq.back();
          if (dp[now][j] < dp[now][id]) {
            dq.pop_back();
          } else {
            break;
          }
        }
        dq.push_back(j);
      }
      ans = min(ans, dp[now][n]);
    }
    printf("%lld\n", (ans>=(1LL<<61)-1)?-1:ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

