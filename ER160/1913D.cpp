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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
ll dp[N];
ll sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    ll tot=0LL;
    vector<int> v;
    v.clear();
    sum[0] = 0LL;
    for (int i =1; i <= n; ++i) {
      while(!v.empty() && a[i] < a[v.back()]) {
        tot = (tot - dp[v.back()] + mod2) % mod2;
        v.pop_back();
      }
      if (v.empty()) {
        dp[i] = (sum[i-1] + 1) % mod2;
      } else {
        dp[i] = (sum[i-1] - sum[v.back()] + mod2) % mod2;
        dp[i] = (dp[i] + tot) % mod2;
      }
      sum[i] = (sum[i-1] + dp[i]) % mod2;
      v.push_back(i);
      tot = (tot + dp[i]) % mod2;
    }
    ll ans=0LL;
    int mn = inf;
    for (int i = n; i >= 1; --i) {
      if (a[i] < mn) {
        ans = (ans + dp[i]) % mod2;
      }
      mn = min(mn, a[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
