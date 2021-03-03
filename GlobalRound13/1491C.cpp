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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,t;
int q;
ll a[N];
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i = 0; i <= n; ++i) {
      dp[i] = 0LL;
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
      ll det = max(a[i]-1, 0LL);
      if (dp[i] < det) {
        ans += det-dp[i];
        dp[i] = det;
      }
      if (a[i] > n-i) {
        det = a[i]-(n-i);
        dp[i] -= det;
        a[i] -= det;
      }
      if (dp[i] > 0) {
        for (int j = i+a[i]; j > i+1; --j) {
          if (dp[i] <= 0) {
            break;
          }
          dp[j]++;
          dp[i]--;
        }
        if (dp[i]>0) dp[i+1] += dp[i];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
