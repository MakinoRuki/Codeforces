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
#define N 4000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
ll m;
ll dp[N];
int main() {
  cin>>n>>m;
  memset(dp, 0LL, sizeof(dp));
  dp[n] = 1LL;
  for (int i = n-1; i >= 1; --i) {
    dp[i] = (dp[i] + dp[i+1]) % m;
    for (int j = 2; j <= n/i; ++j) {
      ll j2 = min((ll)n, (ll)j*(ll)(i+1)-1);
      ll det = dp[j*i];
      if (j2 < n) det = (det - dp[j*(i+1)] + m) % m;
      dp[i] = (dp[i] + det) % m;
    }
    dp[i] = (dp[i] + dp[i+1]) % m;
  }
  ll ans = (dp[1] - dp[2] + m) % m;
  printf("%lld\n", ans);
 return 0;
}
