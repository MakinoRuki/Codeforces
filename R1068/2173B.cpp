
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
int b[N];
ll dp[N][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = (1LL<<61)-1;
      dp[i][1] = -((1LL<<61)-1);
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i+1][0] = min(dp[i+1][0], dp[i][j]-a[i+1]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][j]-a[i+1]);
        dp[i+1][0] = min(dp[i+1][0], b[i+1]-dp[i][j]);
        dp[i+1][1] = max(dp[i+1][1], b[i+1]-dp[i][j]);
      }
    }
    ll ans = dp[n][1];
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
