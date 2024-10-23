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
#define N 500005
#define M 1100
#define eps 1e-7
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
vector<string> rs;
ll dp[N][2][2];
ll calc(char x, char y, char z) {
  int cnt = (x == 'A') + (y == 'A') + (z == 'A');
  return cnt >= 2;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    rs.clear();
    for (int i = 0; i < 2; ++i) {
      string s;
      cin>>s;
      rs.push_back(s);
    }
    for (int i = 0; i <= n; ++i) {
      for (int s1 = 0; s1 < 2; ++s1) {
        for (int s2 = 0; s2 < 2; ++s2) {
          dp[i][s1][s2] = -1;
        }
      }
    }
    dp[0][1][1] = 0LL;
    for (int i = 0; i < n; ++i) {
      for (int s1 = 0; s1 < 2; ++s1) {
        for (int s2 = 0; s2 < 2; ++s2) {
          if (!s1 && !s2) continue;
          if (dp[i][s1][s2] < 0) continue;
          if (s1 && s2) {
            if (i+3<=n) dp[i+3][1][1] = max(dp[i+3][1][1], dp[i][s1][s2] + calc(rs[0][i], rs[0][i+1], rs[0][i+2]) + calc(rs[1][i], rs[1][i+1], rs[1][i+2]));
            if (i+2<=n) {
              dp[i+2][1][0] = max(dp[i+2][1][0], dp[i][s1][s2] + calc(rs[0][i], rs[0][i+1], rs[1][i]));
              dp[i+2][0][1] = max(dp[i+2][0][1], dp[i][s1][s2] + calc(rs[0][i], rs[1][i], rs[1][i+1]));
            }
          }
          if (s1 && !s2) {
            if (i+3<=n) dp[i+3][1][0] = max(dp[i+3][1][0], dp[i][s1][s2] + calc(rs[0][i], rs[0][i+1], rs[0][i+2]) + calc(rs[1][i-1], rs[1][i], rs[1][i+1]));
            if (i+1<=n) dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][s1][s2] + calc(rs[0][i], rs[1][i-1], rs[1][i]));
          }
          if (!s1 && s2) {
            if (i+3<=n) dp[i+3][0][1] = max(dp[i+3][0][1], dp[i][s1][s2] + calc(rs[0][i-1], rs[0][i], rs[0][i+1]) + calc(rs[1][i], rs[1][i+1], rs[1][i+2]));
            if (i+1<=n) dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][s1][s2] + calc(rs[0][i-1], rs[0][i], rs[1][i]));
          }
        }
      }
    }
    ll ans = dp[n][1][1];
    // if (t == 10000 && cas == 24) {
    //   cout<<rs[0]<<endl;
    // }
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

