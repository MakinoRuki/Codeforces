#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 31
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s;
ll a[N];
ll dp[N][2][2][2];
int main() {
  cin>>n;
  cin>>s;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    for (int j1 = 0; j1 < 2; ++j1) {
      for (int j2 = 0; j2 < 2; ++j2) {
        for (int j3 = 0; j3 < 2; ++j3) {
          dp[i][j1][j2][j3] = (1LL<<60)-1;
        }
      }
    }
  }
  dp[0][0][0][0] = 0LL;
  for (int i = 0; i < n; ++i) {
    for (int j1 = 0; j1 < 2; ++j1) {
      for (int j2 = 0; j2 < 2; ++j2) {
        for (int j3 = 0; j3 < 2; ++j3) {
          if (dp[i][j1][j2][j3] < (1LL<<60)-1) {
            dp[i+1][j1][j2][j3] = min(dp[i+1][j1][j2][j3], dp[i][j1][j2][j3]+a[i+1]);
            if (s[i] == 'h') {
              dp[i+1][1][j2][j3] = min(dp[i+1][1][j2][j3], dp[i][j1][j2][j3]);
            } else if (s[i] == 'a') {
              dp[i+1][j1][j2 | j1][j3] = min(dp[i+1][j1][j2|j1][j3], dp[i][j1][j2][j3]);
            } else if (s[i] == 'r') {
              dp[i+1][j1][j2][j2|j3] = min(dp[i+1][j1][j2][j2|j3], dp[i][j1][j2][j3]);
            } else {
              if (!j3 || s[i] != 'd') {
                dp[i+1][j1][j2][j3] = min(dp[i+1][j1][j2][j3], dp[i][j1][j2][j3]);
              }
            }
          }
        }
      }
    }
  }
  ll ans = (1LL<<60)-1;
  for (int j1 = 0; j1 < 2; ++j1) {
    for (int j2 = 0; j2 < 2; ++j2) {
      for (int j3 = 0; j3 < 2; ++j3) {
        ans = min(ans, dp[n][j1][j2][j3]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
