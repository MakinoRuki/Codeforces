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
#define M 2000005
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int w,h;
int a[N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; --i) {
      if (i + a[i] <= n) dp[i] = dp[i+a[i]]+(ll)a[i];
      else dp[i] = a[i];
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
      ans=max(ans, dp[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
