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
#define M 21
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
ll dp1[2][N][N];
ll dp2[2][N][N];
int main() {
  cin>>n>>k;
  memset(dp1, 0LL, sizeof(dp1));
  memset(dp2, 0LL, sizeof(dp2));
  dp1[1][1][1] = 1LL;
  for (int i = 1; i < n; ++i) {
    int now = i&1;
    memset(dp1[now^1], 0LL, sizeof(dp1[now^1]));
    for (int j = 1; j <= i; j++) {
      for (int j2 = 1; j2 <= i; ++j2) {
        dp1[now^1][j][1] = (dp1[now^1][j][1] + dp1[now][j][j2]) % mod2;
        if (j2+1 > j) {
          dp1[now^1][j2+1][j2+1] = (dp1[now^1][j2+1][j2+1] + dp1[now][j][j2]) % mod2;
        } else {
          dp1[now^1][j][j2+1] = (dp1[now^1][j][j2+1] + dp1[now][j][j2]) % mod2;
        }
      }
    }
  }
  for (int j = 1; j <= n; ++j) {
    for (int j2 = 1; j2 <= n; ++j2) {
      if (j < k) {
        dp2[1][j][1] = (dp2[1][j][1] + dp1[n&1][j][j2]) % mod2;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    int now=i&1;
    memset(dp2[now^1], 0LL, sizeof(dp2[now^1]));
    for (int j = 1; j <= n; ++j) {
      for (int j2 = 1; j2 <= i; ++j2) {
        dp2[now^1][j][1] = (dp2[now][j][j2] + dp2[now^1][j][1]) % mod2;
        int s = j * (j2+1);
        if (s<k) {
          dp2[now^1][j][j2+1] = (dp2[now^1][j][j2+1] + dp2[now][j][j2]) % mod2;
        }
      }
    }
  }
  ll ans = 0LL;
  for (int j = 1; j <= n; ++j) {
    for (int j2 = 1; j2 <= n; ++j2) {
      if (j*j2<k) {
        ans = (ans + dp2[n&1][j][j2]) % mod2;
      }
    }
  }
  ans = ans*2LL % mod2;
  cout<<ans<<endl;
  return 0;
}
