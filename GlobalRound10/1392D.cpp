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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
ll a[N];
ll dp[N][2][2];
int calc(int s1, int s2, int x, int y) {
  for (int i = 0; i <= n; ++i) {
    for (int j1 = 0; j1 < 2; ++j1) {
      for (int j2 = 0; j2 < 2; ++j2) {
        dp[i][j1][j2] = inf;
      }
    }
  }
  int c1 = (s[0] == 'R' ? 1 : 0);
  int c2 = (s[1] == 'R' ? 1 : 0);
  dp[2][x][y] = (c1 ^ s1) + (c2 ^ s2);
  for (int i = 2; i < n; ++i) {
    int c1 = (s[i] == 'R' ? 1 : 0) ^ 1;
    int c0 = (s[i] == 'R' ? 1 : 0) ^ 0;
    dp[i+1][1][0] = min(dp[i+1][1][0], dp[i][0][0] + c1);
    dp[i+1][0][0] = min(dp[i+1][0][0], dp[i][0][1] + c0);
    dp[i+1][1][0] = min(dp[i+1][1][0], dp[i][0][1] + c1);
    dp[i+1][0][1] = min(dp[i+1][0][1], dp[i][1][0] + c0);
    dp[i+1][1][1] = min(dp[i+1][1][1], dp[i][1][0] + c1);
    dp[i+1][0][1] = min(dp[i+1][0][1], dp[i][1][1] + c0);
  }
  if (s1 == 1 && s2 == 0) {
    return min(dp[n][1][0], min(dp[n][0][1], dp[n][0][0]));
  } else if (s1 == 1 && s2 == 1) {
    return min(dp[n][0][1], dp[n][0][0]);
  } else if (s1 == 0 && s2 == 1) {
    return min(dp[n][0][1], min(dp[n][1][0], dp[n][1][1]));
  } else {
    return min(dp[n][1][0], dp[n][1][1]);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    int ans = n+1;
    ans = min(ans, calc(1, 0, 0, 1));
    ans = min(ans, calc(1, 1, 1, 1));
    ans = min(ans, calc(0, 0, 0, 0));
    ans = min(ans, calc(0, 1, 1, 0));
    printf("%d\n", ans);
  }
  return 0;
}
