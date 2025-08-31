
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
ll dp[N][3];
int main() {
//  freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = dp[i][1] = dp[i][2] = (1LL<<61)-1;
    }
    dp[n][0] = a[n];
    dp[n][1] = max(0LL, a[n]-1LL);
    dp[n][2] = max(0LL, a[n]-(n-1LL));
    for (int i = n-1; i >= 1; --i) {
      dp[i][0] = min(dp[i+1][0], dp[i+1][2]) + a[i];
      dp[i][1] = min(dp[i+1][1], dp[i+1][0]) + max(0LL, a[i]-1LL);
      dp[i][2] = min(dp[i+1][0], dp[i+1][1]) + max(a[i]-(i-1LL), 0LL);
    }
    ll ans = dp[1][0];
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
