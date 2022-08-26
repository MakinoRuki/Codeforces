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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
ll dp[2][N];
ll ans[N];
int main() {
  cin>>n>>k;
  memset(dp, 0LL, sizeof(dp));
  memset(ans, 0LL, sizeof(ans));
  dp[0][0] = 1LL;
  int now=0;
  for (int i = 0; i <= 700; ++i) {
    for (int j = 0; j <= n; ++j) {
      ans[j] = (ans[j] + dp[now][j]) % mod2;
    }
    for (int j = 0; j <= n; ++j) {
      dp[now^1][j] = 0LL;
    }
    int dt = k+i;
    for (int j = dt; j <= n; ++j) {
      dp[now^1][j] = (dp[now^1][j-dt] + dp[now][j-dt]) % mod2;
    }
    now ^= 1;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%lld", ans[i]);
    if (i < n) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
