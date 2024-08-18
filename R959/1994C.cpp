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
#define M 505
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
ll sum[N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i]=sum[i-1]+a[i];
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = 0LL;
    }
    //dp[0] = 1LL;
    ll ans = (ll)n*(ll)(n+1)/2LL;
    int r= 1;
    for (int i = 0; i < n; ++i) {
      while(r <= n && sum[r] - sum[i] <= x) {
        r++;
      }
      if (r > n) break;
      dp[r] += dp[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
      ans = ans - dp[i];
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
