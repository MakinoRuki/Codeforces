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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int t,q;
ll dp[N];
ll sum[N];
vector<int> xv, yv, sv;
int main() {
  cin>>n;
  dp[0] = 0LL;
  xv.clear();
  yv.clear();
  sv.clear();
  for (int i = 1; i <= n; ++i) {
    int x,y,s;
    scanf("%d%d%d", &x, &y, &s);
    xv.push_back(x);
    yv.push_back(y);
    sv.push_back(s);
    if (i == 1) {
      dp[i] = (ll)(xv.back() - yv.back() + mod2) % mod2;
    } else {
      int id = upper_bound(xv.begin(), xv.end(), y) - xv.begin();
      dp[i] = ((ll)(x - y + mod2) % mod2 + (sum[i-1] - sum[id] + mod2) % mod2) % mod2;
    }
    sum[i] = (sum[i-1] + dp[i]) % mod2;
  }
  ll ans = (xv[n-1] + 1) % mod2;
  for (int i = 0; i < n; ++i) {
    if (sv[i] == 1) {
      ans = (ans + dp[i+1]) % mod2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
