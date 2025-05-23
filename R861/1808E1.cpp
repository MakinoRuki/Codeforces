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
#define N 500005
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
int dp[N][33];
int main() {
  cin>>n>>k>>m;
  int ans=1;
  for (int i =1 ; i <= n; ++i) {
    ans = (int)((ll)ans * (ll)k % m);
  }
  for (int x = 0; x < k; ++x) {
    for (int i = 0; i <= n; ++i) {
      for (int s=0; s < k; ++s) {
        dp[i][s] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int s= 0;s < k; ++s) {
        if (!dp[i][s]) continue;
        for (int y = 0; y < k; ++y) {
          if ((2*y)%k == x) continue;
          dp[i+1][(s+y)%k] = (dp[i+1][(s+y)%k] + dp[i][s]) %m;
        }
      }
    }
    ans = (ans - dp[n][x] + m) % m;
  }
  printf("%d\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

